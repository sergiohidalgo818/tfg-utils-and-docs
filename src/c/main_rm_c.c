/**
 * @file main_c.c
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Main file for the execution of the Hindmarsh-Rose model in c
 * @version 0.1
 * @date 2024-07-31
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
int main()
{

    RulkovMap *a_values, *b_values, *c_values, *a_values_continue, *b_values_continue, *c_values_continue;
    double start, end_function, end_all_functions, end_writing_operations, end;
    double regular_time, chaotic_time, regular_time_continue, chaotic_time_continue;
    long regular_lines, chaotic_lines, regular_lines_continue, chaotic_lines_continue;
    int i = 0;
    const char *filename = "./data/timings_RM/speed_c.csv";

    clock_t clock(void);
    FILE *fptr;

    start = (double)clock();
    start = start / CLOCKS_PER_SEC;
    a_values = rulkovmap_new_y(0, 1, ELEMENTS_RM, -1.3, 0.14, 4.5, 0, M_VAL);
    rulkovmap_objective_loop(a_values, 5000.0);
    end_function = (double)clock();
    end_function = end_function / CLOCKS_PER_SEC;

    b_values = rulkovmap_new_y(0, 1, ELEMENTS_RM, -1.3, -0.1, 6.0, 0, M_VAL);

    rulkovmap_objective_loop(b_values, 5000.0);

    c_values = rulkovmap_new_y(0, 1, ELEMENTS_RM, -1.3, 0.386, 6.0, 0, M_VAL);

    rulkovmap_objective_loop(c_values, 5000.0);

    a_values_continue = rulkovmap_new(5000, 1, ELEMENTS_RM, a_values->model->data[a_values->model->data_rows * ELEMENTS_RM - 4], a_values->model->data[a_values->model->data_rows * ELEMENTS_RM - 3], 0.14, 4.5, 0, M_VAL);
    b_values_continue = rulkovmap_new(5000, 1, ELEMENTS_RM, b_values->model->data[b_values->model->data_rows * ELEMENTS_RM - 4], b_values->model->data[b_values->model->data_rows * ELEMENTS_RM - 3], -0.1, 6.0, 0, M_VAL);
    c_values_continue = rulkovmap_new(5000, 1, ELEMENTS_RM, c_values->model->data[c_values->model->data_rows * ELEMENTS_RM - 4], c_values->model->data[c_values->model->data_rows * ELEMENTS_RM - 3], 0.386, 6.0, 0, M_VAL);

    rulkovmap_objective_loop(a_values_continue, 10000.0);
    rulkovmap_objective_loop(b_values_continue, 10000.0);
    rulkovmap_objective_loop(c_values_continue, 10000.0);

    end_all_functions = (double)clock();
    end_all_functions = end_all_functions / CLOCKS_PER_SEC;

    end_writing_operations = (double)clock();
    end_writing_operations = end_writing_operations / CLOCKS_PER_SEC;

    rulkovmap_write_on_file(a_values, "./data/executions_RM/c/RM_a_c.csv");
    rulkovmap_write_on_file(b_values, "./data/executions_RM/c/RM_b_c.csv");
    rulkovmap_write_on_file(c_values, "./data/executions_RM/c/RM_c_c.csv");
    rulkovmap_write_on_file(a_values_continue, "./data/executions_RM/c/RM_a_continue_c.csv");
    rulkovmap_write_on_file(b_values_continue, "./data/executions_RM/c/RM_b_continue_c.csv");
    rulkovmap_write_on_file(c_values_continue, "./data/executions_RM/c/RM_c_continue_c.csv");

    rulkovmap_free(a_values);
    rulkovmap_free(b_values);
    rulkovmap_free(c_values);
    rulkovmap_free(a_values_continue);
    rulkovmap_free(b_values_continue);
    rulkovmap_free(c_values_continue);

    end = (double)clock();
    end = end / CLOCKS_PER_SEC;

    if (!(fptr = fopen(filename, "r")))
    {
        fptr = fopen(filename, "w");
        fprintf(fptr, "function_time;all_functions_time;writing_operations;program_after_writing;frees;total_program\n");
    }
    else
    {
        fclose(fptr);
        fptr = fopen(filename, "a");
    }

    fprintf(fptr, "%lf;%lf;%lf;%lf;%lf;%lf\n", end_function - start, end_all_functions - start, end_writing_operations - end_all_functions, end_writing_operations - start, end - end_writing_operations, end - start);

    fclose(fptr);
}