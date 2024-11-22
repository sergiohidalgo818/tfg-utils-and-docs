/**
 * @file hindmarsh_rose.c
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Implementation file in c of the functions for Hindmarsh-Rose model
 * @version 0.1
 * @date 2024-07-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/c/hindmarsh_rose.h"

#include <stdlib.h>
#include <math.h>

double calculate_stationary_y(HindmarshRose *hindmarshrose);
double calculate_stationary_z(HindmarshRose *hindmarshrose);

HindmarshRose *hindmarshrose_new(double start_time, double time_increment, int elements_in_model, float initial_x, float initial_y, float initial_z, float e, float m, float S, float v)
{
    // printf("\nnew: %f start_time, %f  time_increment, %d elements_in_model, %f initial_x, %f initial_y, %f initial_z, %f e, %f m, %f S, %f v\n", start_time,  time_increment,  elements_in_model,  initial_x,  initial_y,  initial_z,  e,  m,  S,  v);
    HindmarshRose *hindmarshrose;
    int i = 0, j = 0;

    if (time_increment < 0 || elements_in_model < 1)
    {
        return NULL;
    }
    hindmarshrose = (HindmarshRose *)malloc(sizeof(HindmarshRose));

    if (hindmarshrose == NULL)
    {
        return NULL;
    }
    hindmarshrose->model = model_new(start_time, time_increment, elements_in_model, (void *)hindmarshrose);

    if (hindmarshrose->model == NULL)
    {
        return NULL;
    }
    hindmarshrose->x = initial_x;
    hindmarshrose->y = initial_y;
    hindmarshrose->z = initial_z;

    hindmarshrose->e = e;
    hindmarshrose->m = m;
    hindmarshrose->S = S;

    hindmarshrose->v = v;

    return hindmarshrose;
}

HindmarshRose *hindmarshrose_new_y_or_z(double start_time, double time_increment, int elements_in_model, float initial_x, float initial_yz, float e, float m, float S, float v, StationaryMode mode)
{
    HindmarshRose *hindmarshrose;
    int i = 0, j = 0;

    if (time_increment < 0 || elements_in_model < 1)
    {
        return NULL;
    }
    hindmarshrose = (HindmarshRose *)malloc(sizeof(HindmarshRose));

    if (hindmarshrose == NULL)
    {
        return NULL;
    }
    hindmarshrose->model = model_new(start_time, time_increment, elements_in_model, (void *)hindmarshrose);

    if (hindmarshrose->model == NULL)
    {
        return NULL;
    }
    hindmarshrose->x = initial_x;

    hindmarshrose->e = e;
    hindmarshrose->m = m;
    hindmarshrose->S = S;

    hindmarshrose->v = v;

    if (mode == Y_STATIONARY)
    {
        hindmarshrose->y = initial_yz;
        hindmarshrose->y = calculate_stationary_y(hindmarshrose);
    }
    else if (mode = Z_STATIONARY)
    {
        hindmarshrose->y = initial_yz;
        hindmarshrose->z = calculate_stationary_z(hindmarshrose);
    }
    else
    {
        hindmarshrose->y = calculate_stationary_y(hindmarshrose);
        hindmarshrose->z = calculate_stationary_z(hindmarshrose);
    }

    return hindmarshrose;
}

HindmarshRose *hindmarshrose_new_yz(double start_time, double time_increment, int elements_in_model, float initial_x, float e, float m, float S, float v)
{

    HindmarshRose *hindmarshrose;
    int i = 0, j = 0;

    if (time_increment < 0 || elements_in_model < 1)
    {
        return NULL;
    }
    hindmarshrose = (HindmarshRose *)malloc(sizeof(HindmarshRose));

    if (hindmarshrose == NULL)
    {
        return NULL;
    }
    hindmarshrose->model = model_new(start_time, time_increment, elements_in_model, (void *)hindmarshrose);

    if (hindmarshrose->model == NULL)
    {
        return NULL;
    }
    hindmarshrose->x = initial_x;

    hindmarshrose->e = e;
    hindmarshrose->m = m;
    hindmarshrose->S = S;

    hindmarshrose->v = v;

    hindmarshrose->y = calculate_stationary_y(hindmarshrose);
    hindmarshrose->z = calculate_stationary_z(hindmarshrose);

    return hindmarshrose;
}

double calculate_stationary_y(HindmarshRose *hindmarshrose)
{
    return (hindmarshrose->model->time_increment * (1 - 5 * hindmarshrose->x * hindmarshrose->x)) / (hindmarshrose->model->time_increment - 1);
}

double calculate_stationary_z(HindmarshRose *hindmarshrose)
{
    return (hindmarshrose->model->time_increment * hindmarshrose->m * hindmarshrose->S * (hindmarshrose->x + 1.6)) / (hindmarshrose->model->time_increment * hindmarshrose->m - 1);
}

void calculate(Model *model, int index)
{
    float aux_x, aux_y, aux_z;
    HindmarshRose *actual_model = (HindmarshRose *)model->model_type;

    model->data[index * model->data_cols] = actual_model->x;
    model->data[index * model->data_cols + 1] = actual_model->y;
    model->data[index * model->data_cols + 2] = actual_model->z;
    model->data[index * model->data_cols + 3] = (float)model->time;

    aux_x = actual_model->x + model->time_increment * (actual_model->y + 3 * actual_model->x * actual_model->x - actual_model->x * actual_model->x * actual_model->x - actual_model->z + actual_model->e);
    aux_y = actual_model->y + model->time_increment * (1 - 5 * actual_model->x * actual_model->x - actual_model->y);
    aux_z = actual_model->z + model->time_increment * actual_model->m * (-actual_model->v * actual_model->z + actual_model->S * (actual_model->x + 1.6));

    actual_model->x = aux_x;
    actual_model->y = aux_y;
    actual_model->z = aux_z;

    model->time = model->time + model->time_increment;
}

void hindmarshrose_objective_loop(HindmarshRose *hindmarshrose, double target_time)
{
    model_objective_loop(hindmarshrose->model, target_time, calculate);
}

void hindmarshrose_iterations_loop(HindmarshRose *hindmarshrose, int iterations)
{
    model_iterations_loop(hindmarshrose->model, iterations, calculate);
}

void hindmarshrose_write_on_file(HindmarshRose *hindmarshrose, const char *filename, int save_every)
{
    model_write_on_file(hindmarshrose->model, filename, "x;y;z;time\n", save_every);
}

void hindmarshrose_free(HindmarshRose *hindmarshrose)
{
    model_free(hindmarshrose->model);

    free(hindmarshrose);
}
