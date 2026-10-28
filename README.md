 <p align="center">
  <img src="https://images.openai.com/static-rsc-4/PPGxuJA5Zq_60aXEMUk83lVsiXEnK_CeE4qSO_Ya-CCkduMMS_bMKfdwBJhDvdz4HioMDQVB7MHrFJ-Xp7Yctq8-aje_3LhX8irSoCW0qq-zOiqtpG0bA3ylfUive74R36vDdo8c_jsW46urBu2FWrF_kIq2AdDL2DDcT5OShd1cozGYbzqsXYF8-JjSgl2B?purpose=fullsize" width="850" alt="Oscar project banner" />
</p>

<h1 align="center">OSCAR</h1>

<p align="center">
  <strong>A Modular Payload Generation Framework</strong>
  <br />
  <sub>From a Windows prototype to a more extensible security research project.</sub>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Status-In_Development-orange?style=flat-square" alt="Status: In Development" />
  <img src="https://img.shields.io/badge/Platform-Windows-blue?style=flat-square" alt="Platform: Windows" />
  <img src="https://img.shields.io/badge/Languages-Python%20%7C%20C%20%7C%20C%2B%2B%20%7C%20Assembly-lightgrey?style=flat-square" alt="Languages: Python, C, C++, Assembly" />
</p>

<p align="center">
  <em>“There's chaos in you.”</em>
</p>

---

## What Is Oscar?

**Oscar is a Windows-focused payload generation project that uses a Python command-line interface to coordinate native components written in C, C++, and Assembly.**

The project started in 2022 as an experiment in simplifying the process of configuring and building native Windows executables. Rather than treating every implementation as a separate tool, Oscar explores how a common interface can organize components and provide a consistent workflow.

The original prototype focuses on a Windows keylogging component with local logging and Telegram reporting. The repository also contains C and Assembly implementations at different stages of completeness.

Oscar is now intended to evolve beyond its original prototype toward a better-organized, modular architecture.

## What Does It Do?

The current codebase contains the following elements:

- **Command-line interface:** A Python menu for navigating the available options.
- **Native components:** Windows-focused implementations in C, C++, and Assembly.
- **Build orchestration:** An early Python Builder intended to prepare source files and invoke a native compiler.
- **Component organization:** Source files grouped by operating system, component type, and programming language.
- **Planned modularity:** A direction for separating configuration, build logic, and individual implementations.

The current Builder has path and build-validation issues, so the presence of a component in the repository does not guarantee that its complete workflow works out of the box.

## How Does It Work?

Oscar's original design can be understood as three layers:

| Layer | Responsibility |
| --- | --- |
| Python interface | Displays the menu and receives user input |
| Builder logic | Prepares source files and invokes the compiler |
| Native components | Implement the functionality of each individual component |

The long-term objective is to make these layers independent, so that a change to one component does not require rewriting the entire application.

## Current Project Status

Oscar is a prototype under active development, not a production-ready framework.

| Component | Current status |
| --- | --- |
| Python command-line interface | Implemented; needs cleanup |
| Windows Builder | Present; currently has path and build-validation issues |
| C implementation | Source present; requires further testing |
| C++ implementation | Source present; requires further testing |
| Assembly implementation | Experimental source; completeness and buildability are unverified |
| Linux support | Not implemented in the current interface |
| Modular plugin architecture | Future development |
| Automated tests | Not established |

**Important:** These statuses describe the source code currently available in the repository. They should not be interpreted as claims that every component compiles or works reliably.

## Repository Structure

```text
Oscar/
├── Oscar.py
├── Payloads/
│   └── windows/
│       └── keylogger/
│           ├── C/
│           │   └── keylog.c
│           ├── C++/
│           │   └── keylog.cpp
│           └── Assembly/
│               └── keylog.asm
├── modules/
│   ├── banner.py
│   └── gnt.py
├── icon/
├── requirements.txt
├── log.log
└── README.md
```

This layout reflects the files currently identified in the repository. The Builder still contains references to an older `CPP-Payload/` directory, which needs to be reconciled with the current `Payloads/` layout.

## Getting Started

### Prerequisites

- Python 3.8 or later
- Git
- `colorama` for the Python command-line interface
- A compatible native compiler and required libraries for native components

### Clone the Repository

```bash
git clone https://github.com/Arash-abraham/Oscar.git
cd Oscar
```

### Install the CLI Dependency

```bash
python -m pip install colorama
```

The current `requirements.txt` includes dependencies that should be reviewed. In particular, `ctypes` is part of Python's standard library and normally does not need to be installed through pip.

### Start the Interface

```bash
python Oscar.py
```

The interface presents a menu for the available options. However, the Windows Builder currently references source paths that do not match the repository layout, so successful payload generation should not be assumed until that issue is resolved.

## Known Limitations

The current prototype has several limitations that are relevant to anyone studying or contributing to the code:

- **Path consistency:** The Builder references an outdated source directory.
- **Build verification:** Compiler exit status and output-file existence are not reliably checked.
- **Input validation:** Some menu and build inputs need stricter validation.
- **Network security:** The C and C++ implementations disable TLS certificate verification.
- **Assembly completeness:** The Assembly source contains placeholder sections and requires independent verification.
- **Dependency management:** The Python dependency list needs to be aligned with actual imports and build requirements.

These are known areas for improvement, not features that should be considered complete.

## Development Roadmap

### Stability

- [ ] Reconcile source paths across the Builder and payload directories.
- [ ] Correct menu input handling.
- [ ] Validate build inputs and handle failures explicitly.
- [ ] Replace fixed delays with actual process-result checks.
- [ ] Review dependency declarations.

### Architecture

- [ ] Separate interface, configuration, and build responsibilities.
- [ ] Define a consistent interface for individual components.
- [ ] Add a configuration format and component registry.
- [ ] Improve platform-specific path handling.
- [ ] Document the status and requirements of each component.

### Quality and Security

- [ ] Add automated tests for non-destructive functionality.
- [ ] Verify compiler compatibility and build reproducibility.
- [ ] Restore proper TLS certificate verification.
- [ ] Document component behavior, data handling, and network communication.
- [ ] Test in isolated, explicitly authorized environments.

### Future Direction

- [ ] Explore a modular extension system.
- [ ] Evaluate additional operating-system support.
- [ ] Add clearer diagnostics and developer documentation.

Future items are goals, not promises of existing functionality.

## Contributing

Contributions are welcome, particularly in the areas of code quality, documentation, testing, dependency management, and architecture.

When submitting a bug report, include:

- Your operating system and Python version
- The affected file or component
- The steps required to reproduce the issue
- Relevant error output
- Expected behavior versus actual behavior

Please avoid including real credentials, bot tokens, private logs, or other sensitive information in public issues.

## Responsible Use

Oscar is intended for educational experimentation, controlled malware analysis, and authorized security research.

Some existing components can capture keyboard input, collect system information, and transmit data to a configured Telegram destination. These behaviors are sensitive and must be clearly understood before any testing.

Only assess systems for which you have explicit authorization. Do not use the project for covert monitoring, unauthorized data collection, or access to systems belonging to others.

## About the Name

Oscar was inspired by Oscar Isaac and the period when development began in 2022. The name stayed with the project as it evolved.

---

<p align="center">
  <sub>Built for learning, experimentation, and responsible security research.</sub>
</p>
