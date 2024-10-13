/**
 * @file HindmarshRose.cpp
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Implementation file in c++ for the class of Hindmarsh-Rose model class
 * @version 0.1
 * @date 2024-07-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/cpp/HindmarshRose.h"

#include <cmath>

HindmarshRose::HindmarshRose(double time_increment, const char *filename, int elements_in_model, float initial_x, float e, float m, float S) : Model(time_increment, filename, elements_in_model)
{
    this->x = initial_x;

    this->e = e;
    this->m = m;
    this->S = S;

    this->calculate_stationary_y();
    this->calculate_stationary_z();

    this->outfile << "x;y;z;time\n";
}

HindmarshRose::HindmarshRose(double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_y, float initial_z, float e, float m, float S) : Model(time_increment, filename, elements_in_model)
{
    this->x = initial_x;
    this->y = initial_y;
    this->z = initial_z;

    this->e = e;
    this->m = m;
    this->S = S;

    this->outfile << "x;y,z;time\n";
}

HindmarshRose::HindmarshRose(double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode) : Model(time_increment, filename, elements_in_model)
{
    this->x = x;

    this->e = e;
    this->m = m;
    this->S = S;

    if (HindmarshRose::StationaryMode::Y_Stationary == mode)
    {
        this->z = initial_yz;

        this->calculate_stationary_y();
    }
    else if (HindmarshRose::StationaryMode::Z_Stationary == mode)
    {
        this->y = initial_yz;
        this->calculate_stationary_z();
    }
    else
    {
        this->calculate_stationary_y();
        this->calculate_stationary_z();
    }

    this->outfile << "x;y;z;time\n";
}

HindmarshRose::HindmarshRose(float start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float e, float m, float S) : Model(time_increment, filename, elements_in_model, start_time)
{
    this->x = initial_x;

    this->e = e;
    this->m = m;
    this->S = S;

    this->calculate_stationary_y();
    this->calculate_stationary_z();

    this->outfile << "x;y;z;time\n";
}

HindmarshRose::HindmarshRose(float start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_y, float initial_z, float e, float m, float S) : Model(time_increment, filename, elements_in_model, start_time)
{
    this->x = initial_x;
    this->y = initial_y;
    this->z = initial_z;

    this->e = e;
    this->m = m;
    this->S = S;

    this->outfile << "x;y;z;time\n";
}

HindmarshRose::HindmarshRose(float start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode) : Model(time_increment, filename,  elements_in_model, start_time)
{
    this->x = x;

    this->e = e;
    this->m = m;
    this->S = S;

    if (HindmarshRose::StationaryMode::Y_Stationary == mode)
    {
        this->z = initial_yz;
        this->calculate_stationary_y();
    }
    else if (HindmarshRose::StationaryMode::Z_Stationary == mode)
    {
        this->y = initial_yz;
        this->calculate_stationary_z();
    }
    else
    {
        this->calculate_stationary_y();
        this->calculate_stationary_z();
    }

    this->outfile << "x;y;z;time\n";
}

void HindmarshRose::calculate_stationary_y()
{
    y = (time_increment * (1 - 5 * x * x)) / (time_increment - 1);
}

void HindmarshRose::calculate_stationary_z()
{
    z = (time_increment * m * S * (x + 1.6)) / (time_increment * m - 1);
}

void HindmarshRose::calculate(int index)
{

    float aux_x, aux_y, aux_z;

    this->data[index*this->data_cols] = x;
    this->data[index*this->data_cols+1] = y;
    this->data[index*this->data_cols+2] = z;
    this->data[index*this->data_cols+3] = (float)time;


    aux_x = x + time_increment * (y + 3 * x * x - x * x * x - z + e);
    aux_y = y + time_increment * (1 - 5 * x * x - y);
    aux_z = z + time_increment * m * (-z + S * (x + 1.6));

    this->x = aux_x;
    this->y = aux_y;
    this->z = aux_z;

    this->time = time + time_increment;

}

