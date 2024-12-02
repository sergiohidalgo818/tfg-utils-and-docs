#!/bin/bash
# cp ../../graphs/executions_HR_syn/c/HR_syn_chaotic_c.png images/
# cp ../../graphs/executions_HR_syn/c/HR_syn_chaotic_continue_c.png images/
# cp ../../graphs/executions_HR_syn/c/HR_syn_regular_c.png images/
# cp ../../graphs/executions_HR_syn/c/HR_syn_regular_continue_c.png images/


pandoc synapsis_hr.md -f markdown --listings -H config/listings-setup.tex -V geometry:"left=1cm, top=1cm, right=1cm, bottom=2cm" -V fontsize=12pt -V urlcolor='blue' -V block-headings -o ../synapsis_hr.pdf
pandoc parameter_update_hr.md -f markdown --listings -H config/listings-setup.tex -V geometry:"left=1cm, top=1cm, right=1cm, bottom=2cm" -V fontsize=12pt -V urlcolor='blue' -V block-headings -o ../parameter_update_hr.pdf
pandoc synapsis_between_hr.md -f markdown --listings -H config/listings-setup.tex -V geometry:"left=1cm, top=1cm, right=1cm, bottom=2cm" -V fontsize=12pt -V urlcolor='blue' -V block-headings -o ../synapsis_between_hr.pdf
