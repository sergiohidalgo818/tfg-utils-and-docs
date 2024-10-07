/**
 * @file HindmarshRose.h
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Definition file for the Hindmarsh-Rose model class
 * @version 0.1
 * @date 2024-07-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef HINDMARSHROSE_H
#define HINDMARSHROSE_H

#include "Model.h"

/**
 * @class HindmarshRose
 * @brief This function initialices the model.
 *
 * @param x value x
 * @param y the value y
 * @param z the value z
 * @param e value of the e constant (> 3.0  is chaotic)
 * @param m value of the m constant
 * @param S value of the S constant
 *
 */
class HindmarshRose : public Model
{

public:
    enum StationaryMode
    {
        Z_Stationary,
        Y_Stationary,
        ZY_Stationary,
        None_Stationary
    };

    float x;
    float y;
    float z;
    float e;
    float S;
    float m;
    HindmarshRose::StationaryMode mode;

public:
    /**
     * @brief This function initialices the model.
     *
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_x value of intial x
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(double time_increment, const char *filename, int elements_in_model, float initial_x, float e, float m, float S);

    /**
     * @brief This function initialices the model.
     *
     * @param time_increment incremet of the time (time step)
     * @param initial_x value of intial x
     * @param initial_y value of intial y
     * @param initial_z value of intial z
     * @param filename name of the file to write
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_y, float initial_z, float e, float m, float S);

    /**
     * @brief This function initialices the model.
     *
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_x value of intial x
     * @param initial_yz value of initial y or value of initial z (depends on the mode)
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     * @param mode mode of the stationary values
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode);

    /**
     * @brief This function initialices the model.
     *
     * @param start_time time of starting
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_x value of intial x
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(float start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float e, float m, float S);

    /**
     * @brief This function initialices the model.
     *
     * @param start_time time of starting
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_x value of intial x
     * @param initial_y value of intial y
     * @param initial_z value of intial z
     * @param y value y
     * @param z value z
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(float start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_y, float initial_z, float e, float m, float S);

    /**
     * @brief This function initialices the model.
     *
     * @param start_time time of starting
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_x value of intial x
     * @param initial_yz value of initial y or value of initial z (depends on the mode)
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     * @param mode mode of the stationary values
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(float start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode);

    /**
     * @brief This function calculates t + t_increment on the model.
     * 
     * @param index indicates where to store the variables in the array
     */
    void calculate(int index);


private:
    /**
     * @brief This function calculates stationary_z.
     *
     */
    void calculate_stationary_z();

    /**
     * @brief This function calculates stationary_y.
     *
     */
    void calculate_stationary_y();


};

#endif /* HINDMARSHROSE_H */