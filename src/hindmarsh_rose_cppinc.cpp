/**
 * @file hindmarsh_rose_cppinc.cpp
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Implementation file in c of the functions for Hindmarsh-Rose model
 * but compiled in c
 * @version 0.1
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../include/hindmarsh_rose.h"

#include <stdlib.h>

#include <math.h>

double **allocate_array(double start_time, double time_increment, double target_time, long *n_lines)
{
    double **array;
    int i = 0;
    double time = target_time - start_time;

    (*n_lines) = (long)(ceil(time / time_increment));


    int n_cols = ELEMENTS_IN_MODEL;

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

double calculate_stationary_y(double x, double time_increment)
{
    return (time_increment * (1 - 5 * x * x)) / (time_increment - 1);
}

double calculate_stationary_z(double x, double time_increment, double m, double S)
{
    return (time_increment * m * S * (x + 1.6)) / (time_increment * m - 1);
}

void calculate(double *x_ptr, double *y_ptr, double *z_ptr, double time_increment, double *time, double e, double m, double S)
{
    double aux_x, aux_y, aux_z;
    double x = (*x_ptr);
    double y = (*y_ptr);
    double z = (*z_ptr);

    aux_x = x + time_increment * (y + 3 * x * x - x * x * x - z + e);
    aux_y = y + time_increment * (1 - 5 * x * x - y);
    aux_z = z + time_increment * m * (-z + S * (x + 1.6));

    (*x_ptr) = aux_x;
    (*y_ptr) = aux_y;
    (*z_ptr) = aux_z;

    (*time) = (*time) + time_increment;
}

double **hindmarsh_rose_stationary_y_or_z(double x, double yz, double start_time, double time_increment, double target_time, double *time, double e, double m, double S, long *n_lines, StationaryMode mode)
{
    (*time) = start_time;
    double z, y;

    if (mode == Y_STATIONARY)
    {
        y = calculate_stationary_y(x, time_increment);
    }
    else if (mode = Z_STATIONARY)
    {
        z = calculate_stationary_z(x, time_increment, m, S);
    }
    else
    {
        y = calculate_stationary_y(x, time_increment);
        z = calculate_stationary_z(x, time_increment, m, S);
    }

    double **array = allocate_array(start_time, time_increment, target_time, n_lines);

    int counter = 0;

    while ((target_time - (*time)) > DECIMAL_PRECISION)
    {
        array[counter][0] = x;
        array[counter][1] = y;
        array[counter][2] = z;
        array[counter][3] = (*time);
        calculate(&x, &y, &z, time_increment, time, e, m, S);
        counter++;
    }

    return array;
}

double **hindmarsh_rose_stationary_yz(double x, double start_time, double time_increment, double target_time, double *time, double e, double m, double S, long *n_lines)
{
    (*time) = start_time;

    double y = calculate_stationary_y(x, time_increment);
    double z = calculate_stationary_z(x, time_increment, m, S);

    double **array = allocate_array(start_time, time_increment, target_time, n_lines);

    int counter = 0;

    while ((target_time - (*time)) > DECIMAL_PRECISION )
    {

        array[counter][0] = x;
        array[counter][1] = y;
        array[counter][2] = z;
        array[counter][3] = (*time);
        calculate(&x, &y, &z, time_increment, time, e, m, S);
        counter++;
    }
    return array;
}

double **hindmarsh_rose(double x, double y, double z, double start_time, double time_increment, double target_time, double *time, double e, double m, double S, long *n_lines)
{
    (*time) = start_time;

    double **array = allocate_array(start_time, time_increment, target_time, n_lines);

    int counter = 0;

    while ((target_time - (*time)) > DECIMAL_PRECISION )
    {

        array[counter][0] = x;
        array[counter][1] = y;
        array[counter][2] = z;
        array[counter][3] = (*time);
        calculate(&x, &y, &z, time_increment, time, e, m, S);

        counter++;
    }

    return array;
}