/**
 * @file rulkov_map.c
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Implementation file in c of the functions for Hindmarsh-Rose model
 * @version 0.1
 * @date 2024-07-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/c/rulkov_map.h"

#include <stdlib.h>
#include <math.h>

double calculate_stationary_y(RulkovMap *rulkovmap);


RulkovMap *rulkovmap_new_y(double start_time, double time_increment, int elements_in_model, float initial_x, float o, float a, float B, float m)
{
    RulkovMap *rulkovmap;
    int i = 0, j = 0;

    if (time_increment < 0 || elements_in_model < 1)
    {
        return NULL;
    }
    rulkovmap = (RulkovMap *)malloc(sizeof(RulkovMap));

    if (rulkovmap == NULL)
    {
        return NULL;
    }
    rulkovmap->model = model_new(start_time, time_increment, elements_in_model, (void *)rulkovmap);

    if (rulkovmap->model == NULL)
    {
        return NULL;
    }
    rulkovmap->x = initial_x;
    
    rulkovmap->o = o;
    rulkovmap->a = a;
    rulkovmap->B = B;
    rulkovmap->m = m;

    rulkovmap->y = calculate_stationary_y(rulkovmap);

    return rulkovmap;
}
RulkovMap *rulkovmap_new(double start_time, double time_increment, int elements_in_model, float initial_x, float initial_y, float o, float a, float B, float m)
{
    RulkovMap *rulkovmap;
    int i = 0, j = 0;

    if (time_increment < 0 || elements_in_model < 1)
    {
        return NULL;
    }
    rulkovmap = (RulkovMap *)malloc(sizeof(RulkovMap));

    if (rulkovmap == NULL)
    {
        return NULL;
    }
    rulkovmap->model = model_new(start_time, time_increment, elements_in_model, (void *)rulkovmap);

    if (rulkovmap->model == NULL)
    {
        return NULL;
    }
    rulkovmap->x = initial_x;
    rulkovmap->y = initial_y;

    rulkovmap->a = a;
    rulkovmap->B = B;
    rulkovmap->m = m;

    rulkovmap->o = o;


    return rulkovmap;
}



double calculate_stationary_y(RulkovMap *rulkovmap)
{
    return (-rulkovmap->m*(rulkovmap->x+1)+(rulkovmap->m*rulkovmap->o)) ;
}


void calculate(Model *model, int index)
{
    float aux_x, aux_y, aux_z;
    RulkovMap *actual_model = (RulkovMap *)model->model_type;

    model->data[index*model->data_cols] = actual_model->x;
    model->data[index*model->data_cols + 1] = actual_model->y;
    model->data[index*model->data_cols + 2] = actual_model->o;
    model->data[index*model->data_cols + 3] = (float)model->time;

    if (actual_model->x <= 0)
    {
        aux_x = (actual_model->a / (1 - actual_model->x)) + (actual_model->y + actual_model->B);
    }
    else if (actual_model->x < (actual_model->a + (actual_model->y + actual_model->B)))
    {
        aux_x = actual_model->a + (actual_model->y + actual_model->B);
    }
    else
    {
        aux_x = -1;
    }
    // aux_x= (a/(1+x*x)) + y;

    aux_y =actual_model-> y - actual_model->m * (actual_model->x + 1) + actual_model->m * actual_model->o;
    actual_model->x = aux_x;
    actual_model->y = aux_y;
    

    model->time = model->time + model->time_increment;
}

void rulkovmap_objective_loop(RulkovMap *rulkovmap, double target_time)
{
    model_objective_loop(rulkovmap->model, target_time, calculate);
}

void rulkovmap_iterations_loop(RulkovMap *rulkovmap, int iterations)
{
    model_iterations_loop(rulkovmap->model, iterations, calculate);
}

void rulkovmap_write_on_file(RulkovMap *rulkovmap, const char *filename)
{
    model_write_on_file(rulkovmap->model,  filename, "x;y;o;time\n", 1);
}

void rulkovmap_free(RulkovMap *rulkovmap)
{
    model_free(rulkovmap->model);

    free(rulkovmap);
}
