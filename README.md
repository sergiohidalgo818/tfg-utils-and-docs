# TFG Utils and Docs

- [Neural Models](#neural-models)
  - [Location](#location)
  - [Prerequisites](#prerequisites)
  - [Build Tool](#build-tool)
- [Detecting Points](#detecting-points)
  - [Location](#location-3)
- [Code Documentation](#code-docs)
  - [Location](#location-4)
- [Tutorials and Reports](#tutorials-and-reports)
  - [Location](#location-5)
  - [Contents](#contents)
- [Scripts](#scripts)
  - [Location](#location-6)
- [Graphs](#graphs)
  - [Location](#location-7)


This repository includes several code and documents related with my *TFG*


## Neural models

Implementation of the following neural models:

1. Hindmarsh-Rose `cpp`
2. Hindmarsh-Rose V2 `c`
3. Rulkov-Map `c`, `cpp`

### Location

Under `include`, `src/cpp` and `src/c` directories.


### Prerequisites

- For bash outputs install bc: run `sudo apt install bc`

- If you are on windows, for executing the scripts you may need to run the following command: `sed -i -e 's/\r$//' scripts/*.bash`

- If you are in linux, for executing the scripts you may need to run the following command: `sed -i 's/\r$//' scripts/*.bash`


### Build tool

Use `make` to build all.

## Detecting points

An algorithm to detect spike points on bursts.

### Location

Under `src/python` directory.


## Code docs

A brief Doxygen documentation for the code.

### Location

Under `docs/` directory.


## Tutorials and reports

Diverse tutorials and reports, from results of executions to `preempt-rt` installation tutorials


### Location

Under `tuts_and_reports/` directory.

### Contents

- CPU isolation: A tutorial that explains how to isolate a CPU core.
  - [Markdown file](tuts_and_reports/markdown/aislamiento_cpu.md)
  - [PDF file](tuts_and_reports/aislamiento_cpu.pdf)
  - Language: Spanish

- NVIDIA drivers on RT kernel: A guide on installing NVIDIA drivers in a Real-Time Ubuntu system.
  - [Markdown file](tuts_and_reports/markdown/drivers_nvidia_rt.md)
  - [PDF file](tuts_and_reports/drivers_nvidia_rt.pdf)
  - Language: English

- Finding the bottleneck: A performance analysis tutorial to detect the bottleneck in the [pico-neuron](www.github.com/pico-neuron) program.
  - [Markdown file](tuts_and_reports/markdown/encontrando_el_bottleneck.md)
  - [PDF file](tuts_and_reports/encontrando_el_bottleneck.pdf)
  - Language: Spanish

- Debian installation: A tutorial to install Debian with `preempt-rt`.
  - [Markdown file](tuts_and_reports/markdown/instalacion_debian_rt.md)
  - [PDF file](tuts_and_reports/instalacion_debian_rt.pdf)
  - Language: Spanish

> [!WARNING]
> Do not install comedi if you are willing to use RTXI. Install NI drivers instead. 
- Ubuntu RT installation: Step-by-step guide to install Ubuntu with a Real-Time kernel and RTHybrid. 
  - [Markdown file](tuts_and_reports/markdown/instalación_ubuntu_rt.md)
  - [PDF file](tuts_and_reports/instalación_ubuntu_rt.pdf)
  - Language: Spanish

- Parameter update in HR model: Analysis and visualization of parameter changes in the Hindmarsh-Rose model.
  - [Markdown file](tuts_and_reports/markdown/parameter_update_hr.md)
  - [PDF file](tuts_and_reports/parameter_update_hr.pdf)
  - Language: English

- Spike analysis: Evaluation of spike behavior in neural models.
  - [Markdown file](tuts_and_reports/markdown/spike_analysis.md)
  - [PDF file](tuts_and_reports/spike_analysis.pdf)
  - Language: English

- Synapses between HR neurons: Shows the interaction and connectivity in Hindmarsh-Rose neuron models.
  - [Markdown file](tuts_and_reports/markdown/synapses_between_hr.md)
  - [PDF file](tuts_and_reports/synapses_between_hr.pdf)
  - Language: English

- Synapse in HR model: Synaptic dynamics of the HR model.
  - [Markdown file](tuts_and_reports/markdown/synapse_hr.md)
  - [PDF file](tuts_and_reports/synapse_hr.pdf)
  - Language: English

- National Instruments drivers: Guide on installing National Instruments drivers for Linux.
  - [Markdown file](tuts_and_reports/markdown/tutorial-ni.md)
  - [PDF file](tuts_and_reports/tutorial-ni.pdf)
  - Language: Spanish

- Resources: Compilation of useful links and concepts used on the research.
  - [Markdown file](tuts_and_reports/markdown/resources.md)
  - [PDF file](tuts_and_reports/resources.pdf)
  - Language: English


## Scripts

A series of scripts that contains examples of execution of the models (but they will only execute the c version, as exception of Rulkov-Map), generation of the graphs, generation of the pdfs (from tutorial and reports markdowns) and detection of points (but this last one its a but hard-coded, so for using it you will need to modify the variables on the top of it).

>[!NOTE]
>Please execute the scripts from the project root directory, not inside `scripts` folder.


### Location

Under `scripts/` directory.


## Graphs

A series of graphs from executions of the models

>[!NOTE]
>This graphs may be outdated, but you can regenerate them with the provided scripts

### Location

Under `graphs/` directory.
