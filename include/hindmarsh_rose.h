/**
 * @file hindmarsh_rose.h
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Definition file for the c functions
 * @version 0.1
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef HINDMARSH_ROSE_H
#define HINDMARSH_ROSE_H

#include "constants.h"


/**
 * @enum StationaryMode
 * @brief enum for the stationary variable.
 */
typedef enum
{
  Y_STATIONARY = 1,
  Z_STATIONARY = 2
} StationaryMode;

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
double **hindmarsh_rose_stationary_y_or_z(double x, double yz, double start_time, double time_increment, double target_time, double *time, double e, double m, double S, long *n_lines, StationaryMode mode);

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
double **hindmarsh_rose_stationary_yz(double x, double start_time, double time_increment, double target_time, double *time, double e, double m, double S, long *n_lines);

/**
 * @brief This function simulates the hindmarsh rose model
 *
 * @param x value x
 * @param y the value y
 * @param z the value z
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
double **hindmarsh_rose(double x, double y, double z, double start_time, double time_increment, double target_time, double *time, double e, double m, double S, long *n_lines);

/**
 * @brief This function frees the memory of the array
 * @param array the array
 * @param n_lines the number of lines
 *
 */
void free_array(double **array, long n_lines);

#endif /* HINDMARSH_ROSE_H */