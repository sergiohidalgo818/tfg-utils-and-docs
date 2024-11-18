rm -r graphs/executions_HR_syn/*
rm -r data/executions_HR_syn/*

rm graphs/timings_syn_HR/*

make clean
make main

echo "compilation DONE";

# $(./bin/runner/main_syn_hr_cpp)
$(./bin/runner/main_syn_hr_c)


echo "execution DONE";


python3 scripts/generate_hidmarsh_rose_syn_graphs.py