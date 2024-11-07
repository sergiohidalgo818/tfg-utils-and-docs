/**
 * @file hindmarsh_rose_fast_syn.c
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Implementation file in c of the functions for Hindmarsh-Rose fast synaptic model
 * @version 0.1
 * @date 2024-07-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/c/hindmarsh_rose_fast_syn.h"

#include <stdlib.h>
#include <math.h>


HindmarshRoseFastSyn *hindmarshrosefastsyn_new(double start_time, double time_increment, int elements_in_model, float initial_x, float initial_y, float initial_z, float e, float m, float S, float gfast, float Sfast, float Esyn, float Vfast)
{
    HindmarshRoseFastSyn *hindmarshrosefastsyn;
    int i = 0, j = 0;

    if (time_increment < 0 || elements_in_model < 1)
    {
        return NULL;
    }
    hindmarshrosefastsyn = (HindmarshRoseFastSyn *)malloc(sizeof(HindmarshRose));

    if (hindmarshrosefastsyn == NULL)
    {
        return NULL;
    }
    hindmarshrosefastsyn->hr_model = hindmarshrose_new(start_time, time_increment, elements_in_model, initial_x, initial_y, initial_z, e, m, S);

    if (hindmarshrosefastsyn->hr_model == NULL)
    {
        return NULL;
    }

    hindmarshrosefastsyn->gfast = gfast;
    hindmarshrosefastsyn->Sfast = Sfast;
    hindmarshrosefastsyn->Esyn = Sfast;
    hindmarshrosefastsyn->Vfast = Vfast;

    return hindmarshrosefastsyn;
}

HindmarshRoseFastSyn *hindmarshrosefastsyn_new_y_or_z(double start_time, double time_increment, int elements_in_model, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode, float gfast, float Sfast, float Esyn, float Vfast)
{
    HindmarshRoseFastSyn *hindmarshrosefastsyn;
    int i = 0, j = 0;

    if (time_increment < 0 || elements_in_model < 1)
    {
        return NULL;
    }
    hindmarshrosefastsyn = (HindmarshRoseFastSyn *)malloc(sizeof(HindmarshRose));

    if (hindmarshrosefastsyn == NULL)
    {
        return NULL;
    }
    hindmarshrosefastsyn->hr_model = hindmarshrose_new_y_or_z(start_time, time_increment, elements_in_model, initial_x, initial_yz, e, m, S, mode);

    if (hindmarshrosefastsyn->hr_model == NULL)
    {
        return NULL;
    }

    hindmarshrosefastsyn->gfast = gfast;
    hindmarshrosefastsyn->Sfast = Sfast;
    hindmarshrosefastsyn->Esyn = Sfast;
    hindmarshrosefastsyn->Vfast = Vfast;

    return hindmarshrosefastsyn;
}

HindmarshRoseFastSyn *hindmarshrosefastsyn_new_yz(double start_time, double time_increment, int elements_in_model, float initial_x, float e, float m, float S, float gfast, float Sfast, float Esyn, float Vfast)
{
    HindmarshRoseFastSyn *hindmarshrosefastsyn;
    int i = 0, j = 0;

    if (time_increment < 0 || elements_in_model < 1)
    {
        return NULL;
    }
    hindmarshrosefastsyn = (HindmarshRoseFastSyn *)malloc(sizeof(HindmarshRose));

    if (hindmarshrosefastsyn == NULL)
    {
        return NULL;
    }
    hindmarshrosefastsyn->hr_model = hindmarshrose_new_yz(start_time, time_increment, elements_in_model, initial_x, e, m, S);

    if (hindmarshrosefastsyn->hr_model == NULL)
    {
        return NULL;
    }

    hindmarshrosefastsyn->gfast = gfast;
    hindmarshrosefastsyn->Sfast = Sfast;
    hindmarshrosefastsyn->Esyn = Sfast;
    hindmarshrosefastsyn->Vfast = Vfast;

    return hindmarshrosefastsyn;
}


void hindmarshrosefastsyn_calculate(HindmarshRoseFastSyn *hindmarshrosefastsyn, int index, float Vspre)
{
    float aux_x, aux_y, aux_z, Isyn;
    HindmarshRose *actual_model = (HindmarshRose *)hindmarshrosefastsyn->hr_model;
    Model *model = (Model *)actual_model->model;

    model->data[index*model->data_cols] = actual_model->x;
    model->data[index*model->data_cols + 1] = actual_model->y;
    model->data[index*model->data_cols + 2] = actual_model->z;
    model->data[index*model->data_cols + 3] = (float)model->time;

    Isyn = (hindmarshrosefastsyn->gfast * (actual_model->x - hindmarshrosefastsyn->Esyn)) / (1 + exp(hindmarshrosefastsyn->Sfast * (hindmarshrosefastsyn->Vfast - Vspre)));


    aux_x = actual_model->x + model->time_increment * (actual_model->y + 3 * actual_model->x * actual_model->x - actual_model->x * actual_model->x * actual_model->x - actual_model->z + actual_model->e+ Isyn);
    aux_y = actual_model->y + model->time_increment * (1 - 5 * actual_model->x * actual_model->x - actual_model->y+ Isyn);
    aux_z = actual_model->z + model->time_increment * actual_model->m * (-actual_model->z + actual_model->S * (actual_model->x + 1.6)+ Isyn);

    actual_model->x = aux_x;
    actual_model->y = aux_y;
    actual_model->z = aux_z;

    model->time = model->time + model->time_increment;
}

void hindmarshrosefastsyn_write_on_file(HindmarshRoseFastSyn *hindmarshrosefastsyn, const char *filename)
{
    hindmarshrose_write_on_file(hindmarshrosefastsyn->hr_model,  filename);
}

void hindmarshrosefastsyn_free(HindmarshRoseFastSyn *hindmarshrosefastsyn)
{
    hindmarshrose_free(hindmarshrosefastsyn->hr_model);
}


void hindmarshrosefastsyn_allocate_array_iterations(HindmarshRoseFastSyn *hindmarshrosefastsyn, int iterations)
{
    float *array;
    int i = 0;
    Model *model = hindmarshrosefastsyn->hr_model->model;


    if (model == NULL)
    {
        return;
    }

    model->data_rows = iterations;

    if (model->data_rows < 1)
    {
        model->data_rows = 1;
    }

    model->data = (float *)malloc(model->data_rows * model->data_cols * sizeof(float));
}