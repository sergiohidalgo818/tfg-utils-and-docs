/**
 * @file rulkov_map.c
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Implementation file in c of the functions for Rulkov-Map model
 * @version 0.1
 * @date 2024-10-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/c/model.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


   

Model *model_new(double start_time,  double time_increment, int elements_in_model, void *model_type)
{
    Model *model;
    int i = 0, j = 0;

    if (time_increment < 0 ||  elements_in_model < 1 || model_type == NULL)
    {
        return NULL;
    }

    model = (Model *)malloc(sizeof(Model));

    if (model == NULL)
    {
        return NULL;
    }

    model->time_increment = time_increment;
    model->time = start_time;
    model->data_cols = elements_in_model;
    model->model_type = model_type;
    model->data_rows = 0;
    model->data  = NULL;

    return model;
}

void model_objective_loop(Model *model, double target_time, void (*calculate)(Model *, int))
{

    int counter = 0;

    model_allocate_array_time(model, target_time);

    while ((target_time - model->time) > DECIMAL_PRECISION)
    {
        calculate(model, counter);
        counter++;


    }
         printf("-------------------->%d c\n", counter);

}

void model_iterations_loop(Model *model, int iterations, void (*calculate)(Model *, int))
{

    model_allocate_array_iterations(model, iterations);

    for (int i = 0; i < iterations; i++)
    {

        calculate(model, i);
    }
}

void model_allocate_array_time(Model *model, double target_time)
{
    float *array;
    int i = 0;
    double time = target_time - model->time;

    if (model == NULL || time < 0)
    {
        return;
    }

    model->data_rows = (long)(round(time / model->time_increment));

    if (model->data_rows < 1)
    {
        model->data_rows = 1;
    }

    model->data = (float *)malloc(model->data_rows * model->data_cols * sizeof(float));
}

void model_allocate_array_iterations(Model *model, int iterations)
{
    float *array;
    int i = 0;

    if (model == NULL || iterations < 1)
    {
        return;
    }

    model->data_rows = (long)(iterations);

    model->data = (float *)malloc(model->data_rows * model->data_cols * sizeof(float));
}

void model_write_on_file(Model *model,  const char *file_name, const char *header_of_file)
{
    FILE *fptr = NULL;
    int i = 0, j = 0, len = 0;
    char buffer[50] = "";

    fptr = fopen(file_name, "w");
    if (fptr == NULL)
    {
        printf("\nFile does not exist\n");
        return;
    }
    fputs(header_of_file, fptr);

    for (i = 0; i < model->data_rows * model->data_cols; i += j)
    {

        for (j = 0; j < model->data_cols; j++)
        {

            if (j + 1 == model->data_cols)
            {
                sprintf(buffer,"%f\n", model->data[i + j]);

            }
            else
            {
                sprintf(buffer, "%f;", model->data[i + j]);
            }
            

            fprintf(fptr, "%s",buffer);

        }
    }



    fclose(fptr);

}


void model_free(Model *model)
{
    int i = 0, j = 0;
    if (model == NULL)
    {
        return;
    }

    free(model->data);

    free(model);
}
