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
#include "../../include/c/hindmarsh_rose.h"
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

    HindmarshRose *regular_values, *chaotic_values, *regular_values_continue, *chaotic_values_continue;
    double start, end_function, end_all_functions, end_writing_operations, end;
    double regular_time, chaotic_time, regular_time_continue, chaotic_time_continue;
    long regular_lines, chaotic_lines, regular_lines_continue, chaotic_lines_continue;
    int i = 0, save_every = 100;
    const char *filename = "./data/timings_HR/speed_c.csv";
    float e=3.0, e_chaotic=3.281,S = 4.0, v =1;
    float loop_1 = 10000.0, loop_continue = 20000.0;
    clock_t clock(void);
    FILE *fptr;

    start = (double)clock();
    start = start / CLOCKS_PER_SEC;
    regular_values = hindmarshrose_new_yz(0, 0.001, ELEMENTS_HR, -1.3, e, M_VAL, S, v);
    hindmarshrose_objective_loop(regular_values, loop_1);
    end_function = (double)clock();
    end_function = end_function / CLOCKS_PER_SEC;

    chaotic_values = hindmarshrose_new_yz(0, 0.001, ELEMENTS_HR, -1.3, e_chaotic, M_VAL, S, v);
    hindmarshrose_objective_loop(chaotic_values, loop_1);

    regular_values_continue = hindmarshrose_new(regular_values->model->data[regular_values->model->data_rows * ELEMENTS_HR - 1], 0.001, ELEMENTS_HR,
                                                regular_values->model->data[regular_values->model->data_rows * ELEMENTS_HR - 4],
                                                regular_values->model->data[regular_values->model->data_rows * ELEMENTS_HR - 3],
                                                regular_values->model->data[regular_values->model->data_rows * ELEMENTS_HR - 2], e, M_VAL, S, v);

    chaotic_values_continue = hindmarshrose_new(regular_values->model->data[chaotic_values->model->data_rows * ELEMENTS_HR - 1], 0.001, ELEMENTS_HR,
                                                chaotic_values->model->data[chaotic_values->model->data_rows * ELEMENTS_HR - 4],
                                                chaotic_values->model->data[chaotic_values->model->data_rows * ELEMENTS_HR - 3],
                                                chaotic_values->model->data[chaotic_values->model->data_rows * ELEMENTS_HR - 2], e_chaotic, M_VAL, S, v);

    hindmarshrose_objective_loop(regular_values_continue, loop_continue);
    hindmarshrose_objective_loop(chaotic_values_continue, loop_continue);

    end_all_functions = (double)clock();
    end_all_functions = end_all_functions / CLOCKS_PER_SEC;

    end_writing_operations = (double)clock();
    end_writing_operations = end_writing_operations / CLOCKS_PER_SEC;

    hindmarshrose_write_on_file(regular_values, "./data/executions_HR/c/HR_regular_c.csv", save_every);
    hindmarshrose_write_on_file(chaotic_values, "./data/executions_HR/c/HR_chaotic_c.csv", save_every);
    hindmarshrose_write_on_file(regular_values_continue, "./data/executions_HR/c/HR_regular_continue_c.csv", save_every);
    hindmarshrose_write_on_file(chaotic_values_continue, "./data/executions_HR/c/HR_chaotic_continue_c.csv", save_every);

    hindmarshrose_free(regular_values);
    hindmarshrose_free(chaotic_values);
    hindmarshrose_free(regular_values_continue);
    hindmarshrose_free(chaotic_values_continue);

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