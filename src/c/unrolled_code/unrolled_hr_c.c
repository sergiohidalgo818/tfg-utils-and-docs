/**
 * @file unrolled_hr_c.c
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Main file for the execution of the Hindmarsh-Rose model in c without functions
 * @version 0.1
 * @date 2024-11-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ELEMENTS_HR 4
# define M_VAL 0.0021
# define DECIMAL_PRECISION 0.00001
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

    double start, end_function, end_all_functions, end_writing_operations, end;
    int i = 0, j = 0, save_every = 100;
    const char *filename = "./data/timings_HR/speed_c.csv";
    float e = 3.0, e_chaotic = 3.281, S = 3.0, v = 0.1;
    float loop_1 = 10000.0, loop_continue = 20000.0;
    float start_time = 0.0, time_increment = 0.001, initial_x = -1.3;
    float aux_x, aux_y, aux_z;
    char buffer[50] = "";
    clock_t clock(void);
    FILE *fptr;

    // model->e = e;
    // model->m = M_VAL;
    // model->S = S;
    // model->v = v;

    start = (double)clock();
    start = start / CLOCKS_PER_SEC;

    /* regular_values initialization */
    float regular_values_x = initial_x, regular_values_y = 0.0, regular_values_z = 0.0, *regular_values_array;
    double regular_values_time = 0.0;
    int regular_values_data_rows = 0;

    if (time_increment < 0 || ELEMENTS_HR < 1)
    {
        return -1;
    }

    /* regular_values stationaries */
    regular_values_y = (time_increment * (1 - 5 * regular_values_x * regular_values_x)) / (time_increment - 1);
    regular_values_z = (time_increment * M_VAL * S * (regular_values_x + 1.6)) / (time_increment * M_VAL - 1);

    /* regular_values calculate loop_1 time target*/
    regular_values_time = loop_1 - regular_values_time;

    regular_values_data_rows = (long)(round(regular_values_time / time_increment));

    if (regular_values_data_rows < 1)
    {
        regular_values_data_rows = 1;
    }


    regular_values_array = (float *)malloc(regular_values_data_rows * ELEMENTS_HR * sizeof(float));
    
    regular_values_time = 0.0;
    i = 0;
    while ((loop_1 - regular_values_time) > DECIMAL_PRECISION)
    {

        regular_values_array[i * ELEMENTS_HR] = regular_values_x;
        regular_values_array[i * ELEMENTS_HR + 1] = regular_values_y;
        regular_values_array[i * ELEMENTS_HR + 2] = regular_values_z;
        regular_values_array[i * ELEMENTS_HR + 3] = (float)regular_values_time;


        aux_x = regular_values_x + time_increment * (regular_values_y + 3 * regular_values_x * regular_values_x - regular_values_x * regular_values_x * regular_values_x - regular_values_z + e);
        aux_y = regular_values_y + time_increment * (1 - 5 * regular_values_x * regular_values_x - regular_values_y);
        aux_z = regular_values_z + time_increment * M_VAL * (-v * regular_values_z + S * (regular_values_x + 1.6));
//   printf("\n%lf == %lf\t%lf == %lf\t%lf == %lf\t%lf == %lf\n",
//         regular_values_array[i * ELEMENTS_HR], regular_values_x,
//         regular_values_array[i * ELEMENTS_HR +1], regular_values_y,
//         regular_values_array[i * ELEMENTS_HR +2], regular_values_z,
//         regular_values_array[i * ELEMENTS_HR +3],(float)regular_values_time);

        regular_values_x = aux_x;
        regular_values_y = aux_y;
        regular_values_z = aux_z;

        regular_values_time = regular_values_time + time_increment;
        i++;
    }
    i = 0;

    end_function = (double)clock();
    end_function = end_function / CLOCKS_PER_SEC;

    /* chaotic_values initialization */
    float chaotic_values_x = initial_x, chaotic_values_y = 0.0, chaotic_values_z = 0.0, *chaotic_values_array;
    double chaotic_values_time = 0.0, chaotic_values_data_rows = 0;

    if (time_increment < 0 || ELEMENTS_HR < 1)
    {
        return -1;
    }

    /* chaotic_values stationaries */
    chaotic_values_y = (time_increment * (1 - 5 * chaotic_values_x * chaotic_values_x)) / (time_increment - 1);
    chaotic_values_z = (time_increment * M_VAL * S * (chaotic_values_x + 1.6)) / (time_increment * M_VAL - 1);

    /* chaotic_values calculate loop_1 times*/
    chaotic_values_time = loop_1 - chaotic_values_time;

    chaotic_values_data_rows = (long)(round(chaotic_values_time / time_increment));

    if (chaotic_values_data_rows < 1)
    {
        chaotic_values_data_rows = 1;
    }

    chaotic_values_array = (float *)malloc(chaotic_values_data_rows * ELEMENTS_HR * sizeof(float));

    chaotic_values_time = 0.0;
    i = 0;
    while ((loop_1 - chaotic_values_time) > DECIMAL_PRECISION)
    {

        chaotic_values_array[i * ELEMENTS_HR] = chaotic_values_x;
        chaotic_values_array[i * ELEMENTS_HR + 1] = chaotic_values_y;
        chaotic_values_array[i * ELEMENTS_HR + 2] = chaotic_values_z;
        chaotic_values_array[i * ELEMENTS_HR + 3] = (float)chaotic_values_time;

        aux_x = chaotic_values_x + time_increment * (chaotic_values_y + 3 * chaotic_values_x * chaotic_values_x - chaotic_values_x * chaotic_values_x * chaotic_values_x - chaotic_values_z + e_chaotic);
        aux_y = chaotic_values_y + time_increment * (1 - 5 * chaotic_values_x * chaotic_values_x - chaotic_values_y);
        aux_z = chaotic_values_z + time_increment * M_VAL * (-v * chaotic_values_z + S * (chaotic_values_x + 1.6));

        chaotic_values_x = aux_x;
        chaotic_values_y = aux_y;
        chaotic_values_z = aux_z;

        chaotic_values_time = chaotic_values_time + time_increment;
        i++;
    }
    i = 0;


    /* regular_values_continue initialization */
    float regular_values_continue_x = regular_values_x, regular_values_continue_y = regular_values_y, regular_values_continue_z = regular_values_z, *regular_values_continue_array;
    double  regular_values_continue_time = regular_values_time;
    int regular_values_continue_data_rows = 0;

    if (time_increment < 0 || ELEMENTS_HR < 1)
    {
        return -1;
    }

    /* regular_values_continue stationaries */
    regular_values_continue_y = (time_increment * (1 - 5 * regular_values_continue_x * regular_values_continue_x)) / (time_increment - 1);
    regular_values_continue_z = (time_increment * M_VAL * S * (regular_values_continue_x + 1.6)) / (time_increment * M_VAL - 1);

    /* regular_values_continue calculate loop_continue times*/
    regular_values_continue_time = loop_continue - regular_values_continue_time;

    regular_values_continue_data_rows = (long)(round(regular_values_continue_time / time_increment));

    if (regular_values_continue_data_rows < 1)
    {
        regular_values_continue_data_rows = 1;
    }

    regular_values_continue_array = (float *)malloc(regular_values_continue_data_rows * ELEMENTS_HR * sizeof(float));

    regular_values_continue_time = regular_values_time;
    i = 0;
    while ((loop_continue - regular_values_continue_time) > DECIMAL_PRECISION)
    {

        regular_values_continue_array[i * ELEMENTS_HR] = regular_values_continue_x;
        regular_values_continue_array[i * ELEMENTS_HR + 1] = regular_values_continue_y;
        regular_values_continue_array[i * ELEMENTS_HR + 2] = regular_values_continue_z;
        regular_values_continue_array[i * ELEMENTS_HR + 3] = (float)regular_values_continue_time;

        aux_x = regular_values_continue_x + time_increment * (regular_values_continue_y + 3 * regular_values_continue_x * regular_values_continue_x - regular_values_continue_x * regular_values_continue_x * regular_values_continue_x - regular_values_continue_z + e);
        aux_y = regular_values_continue_y + time_increment * (1 - 5 * regular_values_continue_x * regular_values_continue_x - regular_values_continue_y);
        aux_z = regular_values_continue_z + time_increment * M_VAL * (-v * regular_values_continue_z + S * (regular_values_continue_x + 1.6));

        regular_values_continue_x = aux_x;
        regular_values_continue_y = aux_y;
        regular_values_continue_z = aux_z;

        regular_values_continue_time = regular_values_continue_time + time_increment;
        i++;
    }
    i = 0;

    /* chaotic_values_continue initialization */
    float chaotic_values_continue_x = chaotic_values_x, chaotic_values_continue_y = chaotic_values_y, chaotic_values_continue_z = chaotic_values_z, *chaotic_values_continue_array;
    double chaotic_values_continue_time = chaotic_values_time, chaotic_values_continue_data_rows = 0;

    if (time_increment < 0 || ELEMENTS_HR < 1)
    {
        return -1;
    }

    /* chaotic_values_continue stationaries */
    chaotic_values_continue_y = (time_increment * (1 - 5 * chaotic_values_continue_x * chaotic_values_continue_x)) / (time_increment - 1);
    chaotic_values_continue_z = (time_increment * M_VAL * S * (chaotic_values_continue_x + 1.6)) / (time_increment * M_VAL - 1);

    /* chaotic_values_continue calculate loop_continue times*/
    chaotic_values_continue_time = loop_continue - chaotic_values_continue_time;

    chaotic_values_continue_data_rows = (long)(round(chaotic_values_continue_time / time_increment));

    if (chaotic_values_continue_data_rows < 1)
    {
        chaotic_values_continue_data_rows = 1;
    }

    chaotic_values_continue_array = (float *)malloc(chaotic_values_continue_data_rows * ELEMENTS_HR * sizeof(float));

    chaotic_values_continue_time=chaotic_values_time;
    i = 0;
    while ((loop_continue - chaotic_values_continue_time) > DECIMAL_PRECISION)
    {


        chaotic_values_continue_array[i * ELEMENTS_HR] = chaotic_values_continue_x;
        chaotic_values_continue_array[i * ELEMENTS_HR + 1] = chaotic_values_continue_y;
        chaotic_values_continue_array[i * ELEMENTS_HR + 2] = chaotic_values_continue_z;
        chaotic_values_continue_array[i * ELEMENTS_HR + 3] = (float)chaotic_values_continue_time;
      

        aux_x = chaotic_values_continue_x + time_increment * (chaotic_values_continue_y + 3 * chaotic_values_continue_x * chaotic_values_continue_x - chaotic_values_continue_x * chaotic_values_continue_x * chaotic_values_continue_x - chaotic_values_continue_z + e_chaotic);
        aux_y = chaotic_values_continue_y + time_increment * (1 - 5 * chaotic_values_continue_x * chaotic_values_continue_x - chaotic_values_continue_y);
        aux_z = chaotic_values_continue_z + time_increment * M_VAL * (-v * chaotic_values_continue_z + S * (chaotic_values_continue_x + 1.6));

        chaotic_values_continue_x = aux_x;
        chaotic_values_continue_y = aux_y;
        chaotic_values_continue_z = aux_z;

        chaotic_values_continue_time = chaotic_values_continue_time + time_increment;
        i++;
    }
    i = 0;


    end_all_functions = (double)clock();
    end_all_functions = end_all_functions / CLOCKS_PER_SEC;

    end_writing_operations = (double)clock();
    end_writing_operations = end_writing_operations / CLOCKS_PER_SEC;


    /* regular_values write on file */

    fptr = fopen( "./data/executions_HR/c/HR_regular_c.csv", "w");
    if (fptr == NULL)
    {
        printf("\nFile does not exist\n");
        return -1;
    }
    fputs("x;y;z;time\n", fptr);


    for (i = 0, j=0; i < regular_values_data_rows * ELEMENTS_HR; i = i+ j*save_every)
    {

        for (j = 0; j < ELEMENTS_HR; j++)
        {

            if (j + 1 == ELEMENTS_HR)
            {
                sprintf(buffer,"%f\n", regular_values_array[i + j]);

            }
            else
            {
                sprintf(buffer, "%f;", regular_values_array[i + j]);
            }
            

            fprintf(fptr, "%s",buffer);

        }
    }

    fclose(fptr);

    /* chaotic_values write on file */
    fptr = fopen( "./data/executions_HR/c/HR_chaotic_c.csv", "w");
    if (fptr == NULL)
    {
        printf("\nFile does not exist\n");
        return -1;
    }
    fputs("x;y;z;time\n", fptr);


    for (i = 0, j=0; i < chaotic_values_data_rows * ELEMENTS_HR; i = i+ j*save_every)
    {

        for (j = 0; j < ELEMENTS_HR; j++)
        {

            if (j + 1 == ELEMENTS_HR)
            {
                sprintf(buffer,"%f\n", chaotic_values_array[i + j]);

            }
            else
            {
                sprintf(buffer, "%f;", chaotic_values_array[i + j]);
            }
            

            fprintf(fptr, "%s",buffer);

        }
    }

    fclose(fptr);


    
    /* regular_values_continue write on file */
    
    fptr = fopen( "./data/executions_HR/c/HR_regular_continue_c.csv", "w");
    if (fptr == NULL)
    {
        printf("\nFile does not exist\n");
        return -1;
    }
    fputs("x;y;z;time\n", fptr);


    for (i = 0, j=0; i < regular_values_continue_data_rows * ELEMENTS_HR; i = i+ j*save_every)
    {

        for (j = 0; j < ELEMENTS_HR; j++)
        {

            if (j + 1 == ELEMENTS_HR)
            {
                sprintf(buffer,"%f\n", regular_values_continue_array[i + j]);

            }
            else
            {
                sprintf(buffer, "%f;", regular_values_continue_array[i + j]);
            }
            

            fprintf(fptr, "%s",buffer);

        }
    }

    fclose(fptr);

    /* chaotic_values_continue write on file */
    
    fptr = fopen( "./data/executions_HR/c/HR_chaotic_continue_c.csv", "w");
    if (fptr == NULL)
    {
        printf("\nFile does not exist\n");
        return -1;
    }
    fputs("x;y;z;time\n", fptr);


    for (i = 0, j=0; i < chaotic_values_continue_data_rows * ELEMENTS_HR; i = i+ j*save_every)
    {

        for (j = 0; j < ELEMENTS_HR; j++)
        {

            if (j + 1 == ELEMENTS_HR)
            {
                sprintf(buffer,"%f\n", chaotic_values_continue_array[i + j]);

            }
            else
            {
                sprintf(buffer, "%f;", chaotic_values_continue_array[i + j]);
            }
            

            fprintf(fptr, "%s",buffer);

        }
    }

    fclose(fptr);

    free(regular_values_array);
    free(chaotic_values_array);
    free(regular_values_continue_array);
    free(chaotic_values_continue_array);

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

    return 0;
}