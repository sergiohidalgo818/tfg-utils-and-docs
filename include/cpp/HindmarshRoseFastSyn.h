/**
 * @file HindmarshRoseFastSyn.h
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Definition file for the Hindmarsh-Rose fast synaptic model class
 * @version 0.1
 * @date 2024-10-30
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef HINDMARSHROSEFASTSYN_H
#define HINDMARSHROSEFASTSYN_H

#include "HindmarshRose.h"

/**
 * @class HindmarshRoseFastSyn
 * @brief This function initialices the model.
 *
 * @param Vspre value of the other neuron
 * @param gfast value of the g fast constant
 * @param Sfast value of the S fast constant
 * @param Esyn value of the E constant
 * @param Vfast value of the V fast constant
 *
 */
class HindmarshRoseFastSyn : public HindmarshRose
{

public:
    float Vspre;
    float gfast;
    float Esyn;
    float Sfast;
    float Vfast;

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
     * @param gfast value of the g fast constant
     * @param Sfast value of the S fast constant
     * @param Esyn value of the E constant
     * @param Vfast value of the V fast constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRoseFastSyn(double time_increment, const char *filename, int elements_in_model, float initial_x, float e, float m, float S, float gfast, float Sfast, float Esyn, float Vfast);

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
     * @param gfast value of the g fast constant
     * @param Sfast value of the S fast constant
     * @param Esyn value of the E constant
     * @param Vfast value of the V fast constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRoseFastSyn(double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_y, float initial_z, float e, float m, float S, float gfast, float Sfast, float Esyn, float Vfast);
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
     * @param gfast value of the g fast constant
     * @param Sfast value of the S fast constant
     * @param Esyn value of the E constant
     * @param Vfast value of the V fast constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRoseFastSyn(double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode, float gfast, float Sfast, float Esyn, float Vfast);

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
     * @param gfast value of the g fast constant
     * @param Sfast value of the S fast constant
     * @param Esyn value of the E constant
     * @param Vfast value of the V fast constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRoseFastSyn(float start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float e, float m, float S, float gfast, float Sfast, float Esyn, float Vfast);

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
     * @param gfast value of the g fast constant
     * @param Sfast value of the S fast constant
     * @param Esyn value of the E constant
     * @param Vfast value of the V fast constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRoseFastSyn(float start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_y, float initial_z, float e, float m, float S, float gfast, float Sfast, float Esyn, float Vfast);

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
     * @param gfast value of the g fast constant
     * @param Sfast value of the S fast constant
     * @param Esyn value of the E constant
     * @param Vfast value of the V fast constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRoseFastSyn(float start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode, float gfast, float Sfast, float Esyn, float Vfast);

    /**
     * @brief This function calculates t + t_increment on the model.
     *
     * @param index indicates where to store the variables in the array
     */
    void calculate(int index);
};

#endif /* HINDMARSHROSEFASTSYN_H */