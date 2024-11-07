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
#include "../../include/c/hindmarsh_rose_fast_syn.h"
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

    HindmarshRoseFastSyn *regular_values, *regular_values2, *chaotic_values, *chaotic_values2, *regular_values_continue, *regular_values2_continue, *chaotic_values_continue, *chaotic_values2_continue;
    double start, end_function, end_all_functions, end_writing_operations, end;
    long regular_lines, regular_lines2, chaotic_lines, chaotic_lines2, regular_lines_continue, regular_lines2_continue, chaotic_lines_continue, chaotic_lines2_continue;
    int i = 0;
    const char *filename = "./data/timings_syn_HR/speed_c.csv";

    clock_t clock(void);
    FILE *fptr;

    start = (double)clock();
    start = start / CLOCKS_PER_SEC;
    regular_values = hindmarshrosefastsyn_new_yz(0, 0.01, ELEMENTS_HR, -1.3, 3.0, M_VAL, 4.0, 0.02, 0.0002, -0, 05);
    regular_values2 = hindmarshrosefastsyn_new_yz(0, 0.01, ELEMENTS_HR, -1.3, 3.0, M_VAL, 4.0, 0.005, 0.0002, -0, 05);

    int first_loop = 20000;

    hindmarshrosefastsyn_allocate_array_iterations(regular_values, first_loop);
    hindmarshrosefastsyn_allocate_array_iterations(regular_values2, first_loop);
    for (i = 0; i < first_loop; i++)
    {
        hindmarshrosefastsyn_calculate(regular_values, i, regular_values2->hr_model->x);
        hindmarshrosefastsyn_calculate(regular_values2, i, regular_values->hr_model->x);
    }


    end_function = (double)clock();
    end_function = end_function / CLOCKS_PER_SEC;

    chaotic_values = hindmarshrosefastsyn_new_yz(0, 0.01, ELEMENTS_HR, -1.3, 3.281, M_VAL, 4.0, 0.02, 0.0002, -0, 05);
    chaotic_values2 = hindmarshrosefastsyn_new_yz(0, 0.01, ELEMENTS_HR, -1.3, 3.281, M_VAL, 4.0,  0.005, 0.0002, -0, 05);

    hindmarshrosefastsyn_allocate_array_iterations(chaotic_values, first_loop);
    hindmarshrosefastsyn_allocate_array_iterations(chaotic_values2, first_loop);

    for (i = 0; i < first_loop; i++)
    {


        hindmarshrosefastsyn_calculate(chaotic_values, i, regular_values2->hr_model->x);
        hindmarshrosefastsyn_calculate(chaotic_values2, i, regular_values->hr_model->x);
    }



    regular_values_continue = hindmarshrosefastsyn_new(regular_values->hr_model->model->data[regular_values->hr_model->model->data_rows * ELEMENTS_HR - 1],
                                                       0.01, ELEMENTS_HR,
                                                       regular_values->hr_model->model->data[regular_values->hr_model->model->data_rows * ELEMENTS_HR - 4],
                                                       regular_values->hr_model->model->data[regular_values->hr_model->model->data_rows * ELEMENTS_HR - 3],
                                                       regular_values->hr_model->model->data[regular_values->hr_model->model->data_rows * ELEMENTS_HR - 2],
                                                       3.0, M_VAL, 4.0, 0.02, 0.0002, -0, 05);

    regular_values2_continue = hindmarshrosefastsyn_new(regular_values2->hr_model->model->data[regular_values2->hr_model->model->data_rows * ELEMENTS_HR - 1],
                                                        0.01, ELEMENTS_HR,
                                                        regular_values2->hr_model->model->data[regular_values2->hr_model->model->data_rows * ELEMENTS_HR - 4],
                                                        regular_values2->hr_model->model->data[regular_values2->hr_model->model->data_rows * ELEMENTS_HR - 3],
                                                        regular_values2->hr_model->model->data[regular_values2->hr_model->model->data_rows * ELEMENTS_HR - 2],
                                                        3.0, M_VAL, 4.0, 0.005, 0.0002, -0, 05);

    chaotic_values_continue = hindmarshrosefastsyn_new(chaotic_values->hr_model->model->data[regular_values->hr_model->model->data_rows * ELEMENTS_HR - 1],
                                                       0.01, ELEMENTS_HR,
                                                       chaotic_values->hr_model->model->data[chaotic_values->hr_model->model->data_rows * ELEMENTS_HR - 4],
                                                       chaotic_values->hr_model->model->data[chaotic_values->hr_model->model->data_rows * ELEMENTS_HR - 3],
                                                       chaotic_values->hr_model->model->data[chaotic_values->hr_model->model->data_rows * ELEMENTS_HR - 2],
                                                       3.281, M_VAL, 4.0, 0.02, 0.0002, -0, 05);

    chaotic_values2_continue = hindmarshrosefastsyn_new(chaotic_values2->hr_model->model->data[regular_values2->hr_model->model->data_rows * ELEMENTS_HR - 1],
                                                       0.01, ELEMENTS_HR,
                                                       chaotic_values2->hr_model->model->data[chaotic_values2->hr_model->model->data_rows * ELEMENTS_HR - 4],
                                                       chaotic_values2->hr_model->model->data[chaotic_values2->hr_model->model->data_rows * ELEMENTS_HR - 3],
                                                       chaotic_values2->hr_model->model->data[chaotic_values2->hr_model->model->data_rows * ELEMENTS_HR - 2],
                                                       3.281, M_VAL, 4.0, 0.005, 0.0002, -0, 05);


    int second_loop = 20000;



    hindmarshrosefastsyn_allocate_array_iterations(regular_values_continue, second_loop);
    hindmarshrosefastsyn_allocate_array_iterations(regular_values2_continue, second_loop);

    hindmarshrosefastsyn_allocate_array_iterations(chaotic_values_continue, second_loop);
    hindmarshrosefastsyn_allocate_array_iterations(chaotic_values2_continue, second_loop);




    for (i = 0; i < second_loop; i++)
    {


        hindmarshrosefastsyn_calculate(regular_values_continue, i, regular_values2_continue->hr_model->x);
        hindmarshrosefastsyn_calculate(regular_values2_continue, i, regular_values_continue->hr_model->x);

        hindmarshrosefastsyn_calculate(chaotic_values_continue, i, chaotic_values2_continue->hr_model->x);
        hindmarshrosefastsyn_calculate(chaotic_values2_continue, i, chaotic_values_continue->hr_model->x);
    }


    end_all_functions = (double)clock();
    end_all_functions = end_all_functions / CLOCKS_PER_SEC;

    end_writing_operations = (double)clock();
    end_writing_operations = end_writing_operations / CLOCKS_PER_SEC;



    hindmarshrosefastsyn_write_on_file(regular_values, "./data/executions_HR_syn/c/HR_syn_regular_neuron1_c.csv");
    hindmarshrosefastsyn_write_on_file(regular_values2, "./data/executions_HR_syn/c/HR_syn_regular_neuron2_c.csv");
    hindmarshrosefastsyn_write_on_file(chaotic_values, "./data/executions_HR_syn/c/HR_syn_chaotic_neuron1_c.csv");
    hindmarshrosefastsyn_write_on_file(chaotic_values2, "./data/executions_HR_syn/c/HR_syn_chaotic_neuron2_c.csv");

    hindmarshrosefastsyn_write_on_file(regular_values_continue, "./data/executions_HR_syn/c/HR_syn_regular_neuron1_continue_c.csv");
    hindmarshrosefastsyn_write_on_file(regular_values2_continue, "./data/executions_HR_syn/c/HR_syn_regular_neuron2_continue_c.csv");
    hindmarshrosefastsyn_write_on_file(chaotic_values_continue, "./data/executions_HR_syn/c/HR_syn_chaotic_neuron1_continue_c.csv");
    hindmarshrosefastsyn_write_on_file(chaotic_values2_continue, "./data/executions_HR_syn/c/HR_syn_chaotic_neuron2_continue_c.csv");


    hindmarshrosefastsyn_free(regular_values);
    hindmarshrosefastsyn_free(regular_values2);
    hindmarshrosefastsyn_free(chaotic_values);
    hindmarshrosefastsyn_free(chaotic_values2);

    hindmarshrosefastsyn_free(regular_values_continue);
    hindmarshrosefastsyn_free(regular_values2_continue);
    hindmarshrosefastsyn_free(chaotic_values_continue);
    hindmarshrosefastsyn_free(chaotic_values2_continue);

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