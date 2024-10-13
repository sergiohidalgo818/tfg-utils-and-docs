
rm graphs/timings_RM/*
rm -r graphs/executions_RM/*
rm data/timings_MR/*

make clean
make main

echo "compilation DONE";

for i in $(seq 1 1 5);
do 
    $(./bin/runner/main_rm_c)
    $(./bin/runner/main_rm_cpp)
done

echo "first round DONE";


for j in $(seq 1 1 5);
do 
    $(./bin/runner/main_rm_c)
done

echo "second round c DONE";

for x in $(seq 1 1 5);
do 
    $(./bin/runner/main_rm_cpp)
done

echo "second round cpp DONE";




python3 scripts/generate_rulkov_map_graphs.py