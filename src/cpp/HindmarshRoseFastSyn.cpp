/**
 * @file HindmarshRoseFastSyn.cpp
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Implementation file in c++ for the class of Hindmarsh-Rose fast synaptic model class
 * @version 0.1
 * @date 2024-10-30
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/cpp/HindmarshRoseFastSyn.h"

#include <cmath>

HindmarshRoseFastSyn::HindmarshRoseFastSyn(double time_increment, const char *filename, int elements_in_model, float initial_x, float e, float m, float S, float gfast, float Sfast, float Esyn, float Vfast) : HindmarshRose(time_increment, filename, elements_in_model, initial_x, e, m, S)
{

    this->gfast = gfast;
    this->Sfast = Sfast;
    this->Esyn = Esyn;
    this->Vfast = Vfast;
}

HindmarshRoseFastSyn::HindmarshRoseFastSyn(double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_y, float initial_z, float e, float m, float S, float gfast, float Sfast, float Esyn, float Vfast) : HindmarshRose(time_increment, filename, elements_in_model, initial_x, initial_y, initial_z, e, m, S)
{

    this->gfast = gfast;
    this->Sfast = Sfast;
    this->Esyn = Esyn;
    this->Vfast = Vfast;
}

HindmarshRoseFastSyn::HindmarshRoseFastSyn(double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode, float gfast, float Sfast, float Esyn, float Vfast) : HindmarshRose(time_increment, filename, elements_in_model, initial_x, initial_yz, e, m, S, mode)
{

    this->gfast = gfast;
    this->Sfast = Sfast;
    this->Esyn = Esyn;
    this->Vfast = Vfast;
}

HindmarshRoseFastSyn::HindmarshRoseFastSyn(float start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float e, float m, float S, float gfast, float Sfast, float Esyn, float Vfast) : HindmarshRose(start_time, time_increment, filename, elements_in_model, initial_x, e, m, S)
{

    this->gfast = gfast;
    this->Sfast = Sfast;
    this->Esyn = Esyn;
    this->Vfast = Vfast;
}

HindmarshRoseFastSyn::HindmarshRoseFastSyn(float start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_y, float initial_z, float e, float m, float S, float gfast, float Sfast, float Esyn, float Vfast) : HindmarshRose(start_time, time_increment, filename, elements_in_model, initial_x, initial_y, initial_z, e, m, S)
{

    this->gfast = gfast;
    this->Sfast = Sfast;
    this->Esyn = Esyn;
    this->Vfast = Vfast;
}

HindmarshRoseFastSyn::HindmarshRoseFastSyn(float start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode, float gfast, float Sfast, float Esyn, float Vfast) : HindmarshRose(start_time, time_increment, filename, elements_in_model, initial_x, initial_yz, e, m, S, mode)
{

    this->gfast = gfast;
    this->Sfast = Sfast;
    this->Esyn = Esyn;
    this->Vfast = Vfast;
}

void HindmarshRoseFastSyn::calculate(int index)
{

    float aux_x, aux_y, aux_z;


    this->data[index * this->data_cols] = x;
    this->data[index * this->data_cols + 1] = y;
    this->data[index * this->data_cols + 2] = z;
    this->data[index * this->data_cols + 3] = (float)time;

    float Isyn = (gfast * (x - Esyn)) / (1 + exp(Sfast * (Vfast - Vspre)));

    aux_x = x + time_increment * (y + 3 * x * x - x * x * x - z + e + Isyn);
    aux_y = y + time_increment * (1 - 5 * x * x - y+ Isyn);
    aux_z = z + time_increment * m * (-z + S * (x + 1.6)+ Isyn);

    this->x = aux_x;
    this->y = aux_y;
    this->z = aux_z;

    this->time = time + time_increment;
}
