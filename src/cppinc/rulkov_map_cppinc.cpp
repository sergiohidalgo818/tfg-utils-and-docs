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
#include "../../include/cppinc/rulkov_map_cppinc.h"

#include <stdlib.h>
#include <math.h>

float **allocate_array(double start_time, double time_increment, double target_time, long *n_lines)
{
    float **array;
    int i = 0;
    double time = target_time - start_time;

    (*n_lines) = (long)(ceil(time / time_increment));

    int n_cols = ELEMENTS_HR;

    array = (float **)malloc((*n_lines) * sizeof(float *));

    for (i; i < (*n_lines); i++)
        array[i] = (float *)malloc(n_cols * sizeof(float));

    return array;
}

void free_array(float **array, long n_lines)
{
    int i = 0;
    for (i; i < n_lines; i++)
    {
        free(array[i]);
    }

    free(array);
}

float calculate_stationary_y(float x, double time_increment, float m, float o)
{
    return (time_increment * (-m*(x+1)+(m*o))) ;
}

void calculate(float *x_ptr, float *y_ptr, double time_increment, double *time, float o, float a, float B, float m)
{
    double aux_x, aux_y;
    double x = (*x_ptr);
    double y = (*y_ptr);

    if (x <= 0)
    {
        aux_x = (a / (1 - x)) + (y + B);
    }
    else if (x < (a + (y + B)))
    {
        aux_x = a + (y + B);
    }
    else
    {
        aux_x = -1;
    }
    // aux_x= (a/(1+x*x)) + y;

    aux_y = y - m * (x + 1) + m * o;

    (*x_ptr) = aux_x;
    (*y_ptr) = aux_y;

    (*time) = (*time) + time_increment;
}

float **rulkov_map_stationary(float x, double start_time, double time_increment, double target_time, double *time, float o, float a, float B, float m, long *n_lines)
{
    (*time) = start_time;
    float y;

    y = calculate_stationary_y( x, time_increment, m, o);

    float **array = allocate_array(start_time, time_increment, target_time, n_lines);

    int counter = 0;

    while ((target_time - (*time)) > DECIMAL_PRECISION)
    {
        array[counter][0] = x;
        array[counter][1] = y;
        array[counter][2] = o;
        array[counter][3] = (*time);
        calculate(&x, &y, time_increment, time, o, a, B, m);
        counter++;
    }

    return array;
}


float **rulkov_map(float x, float y, double start_time, double time_increment, double target_time, double *time, float o, float a, float B, float m, long *n_lines)
{
    (*time) = start_time;

    float **array = allocate_array(start_time, time_increment, target_time, n_lines);

    int counter = 0;

    while ((target_time - (*time)) > DECIMAL_PRECISION)
    {

        array[counter][0] = x;
        array[counter][1] = y;
        array[counter][2] = o;
        array[counter][3] = (*time);
        calculate(&x, &y, time_increment, time, o, a, B, m);

        counter++;
    }

    return array;
}