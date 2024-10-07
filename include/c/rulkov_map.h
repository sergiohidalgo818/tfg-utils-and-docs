/**
 * @file rulkov_map.h
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Definition file for the c functions
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef RULKOV_MAP_H
#define RULKOV_MAP_H

#include "../constants.h"



/**
 * @brief This function simulates the hindmarsh rose model, y is stationary.
 *
 * @param x value x
 * @param yz the value of z or y
 * @param start_time the time when the model starts
 * @param time_increment incremet of the time (time step)
 * @param target_time time when it stops
 * @param time pointer to keep last time
 * @param e value of the e constant (> 3.0  is chaotic)
 * @param m value of the m constant
 * @param S value of the S constant
 * @param n_lines number of linesc
 *
 * @return Returns the array of values.
 */
double **rulkov_map_stationary(double x, double start_time, double time_increment, double target_time, double *time, double o, double a, double B,double m, long *n_lines);

/**
 * @brief This function simulates the hindmarsh rose model, z and y are stationary.
 *
 * @param x value x
 * @param start_time the t  e when the model starts
 * @param time_increment incremet of the time (time step)
 * @param target_time time when it stops
 * @param time pointer to keep last time
 * @param e value of the e constant (> 3.0  is chaotic)
 * @param m value of the m constant
 * @param S value of the S constant
 * @param n_lines number of linesc
 *
 * @return Returns the array of values.
 */
double **rulkov_map(double x, double y, double start_time, double time_increment, double target_time, double *time, double o, double a, double B,double m, long *n_lines);

/**
 * @brief This function allocates the memory of the array
 * @param start_time the time in wich it starts
 * @param time_increment the time step
 * @param target_time the time stop
 * @param n_lines pointer to the number of lines
 *
 * @return Returns the array allocated.
 */
double **allocate_array(double start_time, double time_increment, double target_time, long *n_lines);

/**
 * @brief This function frees the memory of the array
 * @param array the array
 * @param n_lines the number of lines
 *
 */
void free_array(double **array, long n_lines);

#endif /* RULKOV_MAP_H */