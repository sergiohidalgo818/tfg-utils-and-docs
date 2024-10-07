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
#include "../../include/c/rulkov_map.h"

#include <stdlib.h>

#include <math.h>

double **allocate_array(double start_time, double time_increment, double target_time, long *n_lines)
{
    double **array;
    int i = 0;
    double time = target_time - start_time;

    (*n_lines) = (long)(ceil(time / time_increment));

    int n_cols = ELEMENTS_HR;

    array = (double **)malloc((*n_lines) * sizeof(double *));

    for (i; i < (*n_lines); i++)
        array[i] = (double *)malloc(n_cols * sizeof(double));

    return array;
}

void free_array(double **array, long n_lines)
{
    int i = 0;
    for (i; i < n_lines; i++)
    {
        free(array[i]);
    }

    free(array);
}

double calculate_stationary_y(double x, double time_increment, double m, double o)
{
    return (time_increment * (-m*(x+1)+(m*o))) ;
}

void calculate(double *x_ptr, double *y_ptr, double time_increment, double *time, double o, double a, double B, double m)
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

double **rulkov_map_stationary(double x, double start_time, double time_increment, double target_time, double *time, double o, double a, double B, double m, long *n_lines)
{
    (*time) = start_time;
    double y;

    y = calculate_stationary_y( x, time_increment, m, o);

    double **array = allocate_array(start_time, time_increment, target_time, n_lines);

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


double **rulkov_map(double x, double y, double start_time, double time_increment, double target_time, double *time, double o, double a, double B, double m, long *n_lines)
{
    (*time) = start_time;

    double **array = allocate_array(start_time, time_increment, target_time, n_lines);

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