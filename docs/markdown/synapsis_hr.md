# Fast Synapsis Hindmarsh-Rose

By Sergio Hidalgo

## Index
- [Fast Synapsis Hindmarsh-Rose](#fast-synapsis-hindmarsh-rose)
  - [Index](#index)
  - [Introduction](#introduction)
  - [Parameters](#parameters)
  - [Graphs](#graphs)


## Introduction
This document shows the results from two programs that simulates the fast synapis between two Hindmarsh-Rose neurons.

## Parameters
The parameters choosed are based on the file *"pract3-15.pdf"* inside the directory **`resources/`**.

The values $S_{fast}=0.44$, $V_{fast}=-1.66$, $E_{syn}=-1.92$ for Hindmarsh-Rose synapsis, are obtained from **Table 2**.

The **Table 3** of the document shows the values of maximal conductance, and we can see that *LP* neuron and *PY* neuron have a both values between them. 
So neuron1 will be *LP* and neuron2 *PY*, being $gfast_{1}=0.241$ and $gfast_{2}=0.186$.

The rest of the values ($time increment$, $x_{initial}$, $e$, $m$ and $S$) for the model, are the same used on the part 2 of the same document.

## Graphs
On the following pages are the graphs for the different simulations:


![Simulation regular](images/synapsis_hr/HR_syn_regular_c.png "Simulation regular")



![Simulation regular continue](images/synapsis_hr/HR_syn_regular_continue_c.png "Simulation regular continue")



![Simulation chaotic](images/synapsis_hr/HR_syn_chaotic_c.png "Chaotic regular")



![Simulation chaotic continue](images/synapsis_hr/HR_syn_chaotic_continue_c.png "Chaotic regular continue")
