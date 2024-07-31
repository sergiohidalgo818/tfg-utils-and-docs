#ifndef HINDMARSH_ROSE_H
#define HINDMARSH_ROSE_H

/**
 * @brief This function simulates the hindmarsh rose model, y is stationary.
 *
 * @param x value x
 * @param z the value z
 * @param start_time the time when the model starts 
 * @param time_increment incremet of the time (time step)
 * @param target_time time when it stops
 * @param e value of the e constant (> 3.0  is chaotic)
 * @param m value of the m constant 
 * @param S value of the S constant
 * @param n_lines number of linesc
 *
 * @return Returns the array of values.
 */
double **hindmarsh_rose_stationary_z(double x, double y, double start_time, double time_increment, double target_time,  double e, double m, double S, long *n_lines);

/**
 * @brief This function simulates the hindmarsh rose model, z is stationary.
 *
 * @param x value x
 * @param y the value y
 * @param start_time the time when the model starts 
 * @param time_increment incremet of the time (time step)
 * @param target_time time when it stops
 * @param e value of the e constant (> 3.0  is chaotic)
 * @param m value of the m constant 
 * @param S value of the S constant
 * @param n_lines number of linesc
 *
 * @return Returns the array of values.
 */
double **hindmarsh_rose_stationary_y(double x, double z, double start_time, double time_increment, double target_time,  double e, double m, double S, long *n_lines);

/**
 * @brief This function simulates the hindmarsh rose model, z and y are stationary.
 *
 * @param x value x
 * @param start_time the time when the model starts 
 * @param time_increment incremet of the time (time step)
 * @param target_time time when it stops
 * @param e value of the e constant (> 3.0  is chaotic)
 * @param m value of the m constant 
 * @param S value of the S constant
 * @param n_lines number of linesc
 *
 * @return Returns the array of values.
 */
double **hindmarsh_rose_stationary_yz(double x, double start_time, double time_increment, double target_time,  double e, double m, double S, long *n_lines);


/**
 * @brief This function simulates the hindmarsh rose model
 *
 * @param x value x
 * @param y the value y
 * @param z the value z
 * @param start_time the time when the model starts 
 * @param time_increment incremet of the time (time step)
 * @param target_time time when it stops
 * @param e value of the e constant (> 3.0  is chaotic)
 * @param m value of the m constant 
 * @param S value of the S constant
 * @param n_lines number of linesc
 *
 * @return Returns the array of values.
 */
double ** hindmarsh_rose(double x, double y, double z, double start_time, double time_increment, double target_time,  double e, double m, double S, long *n_lines);


/**
 * @brief This function frees the memory of the array
 * @param array the array 
 * @param n_lines the number of lines
 *
 */
void free_array(double** array, long n_lines);

#endif /* HINDMARSH_ROSE_H */