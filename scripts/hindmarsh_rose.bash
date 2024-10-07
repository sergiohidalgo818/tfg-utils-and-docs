rm graphs/timings_HR/*
rm -r graphs/executions_HR/*

make clean_data
make clean
make main

echo "compilation DONE";

for i in $(seq 1 1 5);
do 
    $(./bin/runner/main_hr_c)
    $(./bin/runner/main_hr_cpp)
    $(./bin/runner/main_hr_cppinc)
done

echo "first round DONE";


for j in $(seq 1 1 5);
do 
    $(./bin/runner/main_hr_c)
done

echo "second round c DONE";

for x in $(seq 1 1 5);
do 
    $(./bin/runner/main_hr_cpp)
done

echo "second round cpp DONE";


for z in $(seq 1 1 5);
do 
    $(./bin/runner/main_hr_cppinc)
done
echo "second round cppinc DONE";

python3 scripts/generate_hidmarsh_rose_graphs.py