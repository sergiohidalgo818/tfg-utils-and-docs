/**
 * @file Model.cpp
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Implementation file in c++ for the class of Model class
 * @version 0.1
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../../include/cpp/Model.h"

#include <math.h>
#include <string>

Model::Model(double time_increment, const char *filename, int elements_in_model)
{
    this->time_increment = time_increment;
    this->time = 0;
    this->outfile.open(filename);
    this->perpetual = true;
    this->elements_in_model = elements_in_model;
}

Model::Model(double time_increment, const char *filename, int elements_in_model, double start_time)
{
    this->time_increment = time_increment;
    this->time = start_time;
    this->outfile.open(filename);
    this->perpetual = true;
    this->elements_in_model = elements_in_model;
}


void Model::objective_loop(double target_time)
{

    int counter = 0;

    this->allocate_array(this->time, target_time);

    while ((target_time - time) > DECIMAL_PRECISION)
    {

        this->calculate(counter);
        counter++;
    }
}

void Model::iterations_loop(int iterations)
{

    this->allocate_array(iterations);

    for (int i = 0; i < iterations; i++)
    {

        this->calculate(i);
    }
}




void Model::allocate_array(double start_time, double target_time)
{

    int i = 0;
    double time = target_time - this->time;
    this->data_rows = (long)(round(time / time_increment));

    this->data_cols = ELEMENTS_RM;

    this->data = new float *[this->data_rows];

    for (i = 0; i < this->data_rows; i++)
    {
        this->data[i] = new float[this->data_cols];
    }
}

void Model::allocate_array(int iterations)
{
    int i = 0;
    this->data_rows = iterations;
    this->data_cols = this->elements_in_model;

    this->data = new float *[this->data_rows];

    for (i = 0; i < this->data_rows; i++)
    {
        this->data[i] = new float[this->data_cols];
    }
}

void Model::write_data()
{
    std::string buffer;
    for (int i = 0; i < this->data_rows; i++)
    {
        for (int j = 0; j < this->data_cols; j++)
        {
            buffer += std::to_string(this->data[i][j]);

            if (j + 1 != this->data_cols)
            {
                buffer += ",";
            }
        }
        buffer+= "\n";
    }
    this->outfile << buffer;
}

void Model::free()
{
    this->outfile.close();

    for (int i = 0; i < this->data_rows; i++)
    {
        delete[] this->data[i];
    }
    delete[] this->data;

    delete this;
}
