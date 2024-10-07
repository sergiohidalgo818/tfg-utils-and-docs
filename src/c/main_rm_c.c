/**
 * @file main_c.c
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Main file for the execution of the Rulkov-Map model in c
 * @version 0.1
 * @date 2024-10-10
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/c/rulkov_map.h"
#include <stdio.h>
#include <time.h>

/**
 * @brief This function writes the content of an array in a file.
 *
 * @param filename the file name
 * @param values values to write
 * @param lines number of lines
 *
 */
void write_on_file(const char *filename, double **values, long lines)
{
    FILE *fptr;
    int i = 0;

    fptr = fopen(filename, "w");
    if (fptr == NULL)
    {
        printf("\nFile does not exist\n");
        return;
    }

    fprintf(fptr, "x,y,z,time\n");
    for (i; i < lines; i++)
    {
        fprintf(fptr, "%lf,%lf,%lf,%lf\n", values[i][0], values[i][1], values[i][2], values[i][3]);
    }

    fclose(fptr);
}

int main()
{

    double **a_values, **b_values, **c_values, **a_values_continue, **b_values_continue, **c_values_continue;
    double start, end_function, end_all_functions, end_writing_operations, end;
    double a_time, b_time, c_time, a_time_continue, b_time_continue, c_time_continue;
    long a_lines, b_lines, c_lines, a_lines_continue, b_lines_continue, c_lines_continue;
    int i = 0;
    const char *filename = "./data/timings_RM/speed_c.csv";

    clock_t clock(void);
    FILE *fptr;

    start = (double)clock();
    start = start / CLOCKS_PER_SEC;
    a_values = rulkov_map_stationary(-1, 0, 1, 4000.0, &a_time, 0.14, 4.5, 0, M_VAL, &a_lines);
    end_function = (double)clock();
    end_function = end_function / CLOCKS_PER_SEC;

    b_values = rulkov_map_stationary(-1, 0, 1, 4000.0, &b_time, -0.1, 6.0, 0, M_VAL, &b_lines);
    c_values = rulkov_map_stationary(-1, 0, 1, 4000.0, &c_time, 0.386, 6.0, 0, M_VAL, &c_lines);

    a_values_continue = rulkov_map(a_values[a_lines - 1][0], a_values[a_lines - 1][1], a_time, 1, 8000.0, &a_time_continue, 0.14, 4.5, 0, M_VAL, &a_lines_continue);
    b_values_continue = rulkov_map(b_values[b_lines - 1][0], b_values[b_lines - 1][1], b_time, 1, 8000.0, &b_time_continue, -0.1, 6.0, 0, M_VAL, &b_lines_continue);
    c_values_continue = rulkov_map(c_values[c_lines - 1][0], c_values[c_lines - 1][1], c_time, 1, 8000.0, &c_time_continue,  0.386, 6.0, 0, M_VAL, &c_lines_continue);

    end_all_functions = (double)clock();
    end_all_functions = end_all_functions / CLOCKS_PER_SEC;

    write_on_file("./data/executions_RM/c/RM_a_c.csv", a_values, a_lines);
    write_on_file("./data/executions_RM/c/RM_b_c.csv", b_values, b_lines);
    write_on_file("./data/executions_RM/c/RM_c_c.csv", c_values, c_lines);

    write_on_file("./data/executions_RM/c/RM_a_continue_c.csv", a_values_continue, a_lines_continue);
    write_on_file("./data/executions_RM/c/RM_b_continue_c.csv", b_values_continue, b_lines_continue);
    write_on_file("./data/executions_RM/c/RM_c_continue_c.csv", c_values_continue, c_lines_continue);

    end_writing_operations = (double)clock();
    end_writing_operations = end_writing_operations / CLOCKS_PER_SEC;

    free_array(a_values, a_lines);
    free_array(b_values, b_lines);
    free_array(c_values, c_lines);
    free_array(a_values_continue, a_lines_continue);
    free_array(b_values_continue, b_lines_continue);
    free_array(c_values_continue, c_lines_continue);

    end = (double)clock();
    end = end / CLOCKS_PER_SEC;

    if (!(fptr = fopen(filename, "r")))
    {
        fptr = fopen(filename, "w");
        fprintf(fptr, "function_time,all_functions_time,writing_operations,program_after_writing,frees,total_program\n");
    }
    else
    {
        fclose(fptr);
        fptr = fopen(filename, "a");
    }

    fprintf(fptr, "%lf,%lf,%lf,%lf,%lf,%lf\n", end_function - start, end_all_functions - start, end_writing_operations - end_all_functions, end_writing_operations - start, end - end_writing_operations, end - start);

    fclose(fptr);
}