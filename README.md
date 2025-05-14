# Utils TFG

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
