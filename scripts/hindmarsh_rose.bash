#!/bin/bash
rm graphs/timings_HR/*
rm -r graphs/executions_HR/*

rm -r data/executions_HR/*

rm data/timings_HR/*
make clean
make main

echo "compilation DONE";

# for i in $(seq 1 1 5);
# do 
#     $(./bin/runner/maicn_hr_c)
# done
    $(./bin/runner/main_hr_c)
    # $(./bin/runner/unrolled_hr_c)
echo "first round DONE";


# for j in $(seq 1 1 5);
# do 
#     $(./bin/runner/main_hr_c)
# done

echo "second round c DONE";

# for x in $(seq 1 1 5);
# do 
#     $(./bin/runner/main_hr_cpp)
# done

# echo "second round cpp DONE";



python3 scripts/generate_hidmarsh_rose_graphs.py