#include "../include/hindmarsh_rose.h"
#include <stdio.h>
#include <chrono>

void write_on_file(const char *filename, double **values, long lines)
{
    FILE *fptr;
    int i = 0;

    fptr = fopen(filename, "w");
    fprintf(fptr, "x,y,z,time\n");
    for (i; i < lines; i++)
    {
        fprintf(fptr, "%lf,%lf,%lf,%lf\n", values[i][0], values[i][1], values[i][2], values[i][3]);
    }

    fclose(fptr);
}

int main()
{

    double **regular_values, **chaotic_values, **regular_values_continue, **chaotic_values_continue;
    long regular_lines, chaotic_lines, regular_lines_continue, chaotic_lines_continue;
    int i = 0;
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    regular_values = hindmarsh_rose_stationary_yz(-1.3, 0, 0.001, 5000.0, 3.0, 0.0021, 4.0, &regular_lines);
    std::chrono::steady_clock::time_point end_function = std::chrono::steady_clock::now();

    chaotic_values = hindmarsh_rose_stationary_yz(-1.3, 0, 0.001, 5000.0, 3.281, 0.0021, 4.0, &chaotic_lines);

    regular_values_continue = hindmarsh_rose(regular_values[regular_lines - 1][0], regular_values[regular_lines - 1][1], regular_values[regular_lines - 1][2], (regular_values[regular_lines - 1][3]), 0.001, 10000.0, 3.0, 0.0021, 4.0, &regular_lines_continue);

    chaotic_values_continue = hindmarsh_rose(chaotic_values[chaotic_lines - 1][0], chaotic_values[chaotic_lines - 1][1], chaotic_values[chaotic_lines - 1][2], (chaotic_values[chaotic_lines - 1][3]), 0.001, 10000.0, 3.281, 0.0021, 4.0, &chaotic_lines_continue);
    std::chrono::steady_clock::time_point end_all_functions = std::chrono::steady_clock::now();


    write_on_file("./data/HindmarshRoseRegular_cppinc.dat", regular_values, regular_lines);
    write_on_file("./data/HindmarshRoseChaotic_cppinc.dat", chaotic_values, chaotic_lines);
    write_on_file("./data/HindmarshRoseRegular_continue_cppinc.dat", regular_values_continue, regular_lines_continue);
    write_on_file("./data/HindmarshRoseChaotic_continue_cppinc.dat", chaotic_values_continue, chaotic_lines_continue);
    std::chrono::steady_clock::time_point end_writing_operations = std::chrono::steady_clock::now();

    free_array(regular_values, regular_lines);
    free_array(chaotic_values, chaotic_lines);
    free_array(regular_values_continue, regular_lines_continue);
    free_array(chaotic_values_continue, chaotic_lines_continue);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    FILE *fptr;

    fptr = fopen("./measures/timing_HR/speed_cppinc.txt", "w");
    fprintf(fptr, "function_time,all_functions_time,writing_operations,program_after_writing,frees,total_program\n");
    fprintf(fptr, "%lf,%lf,%lf,%lf,%lf,%lf\n", std::chrono::duration<double>(end_function - start).count(), std::chrono::duration<double>(end_all_functions - start).count(), std::chrono::duration<double>(end_writing_operations - end_all_functions).count(), std::chrono::duration<double>(end_writing_operations - start).count(), std::chrono::duration<double>(end - end_writing_operations).count(), std::chrono::duration<double>(end - start).count());

    fclose(fptr);
}