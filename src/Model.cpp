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
#include "../include/Model.h"

Model::Model(double time_increment, const char *filename)
{
    this->time_increment = time_increment;
    this->time = 0;
    this->outfile.open(filename);
    this->perpetual = true;
}

Model::Model(double time_increment, const char *filename, double start_time)
{
    this->time_increment = time_increment;
    this->time = start_time;
    this->outfile.open(filename);
    this->perpetual = true;
}

void Model::write_data()
{
    for (int i = 0; i < this->data_rows; i++)
    {
        for (int j = 0; j < this->data_cols; j++)
        {
            this->outfile << this->data[i][j];

            if (j + 1 != this->data_cols)
            {
                this->outfile << ",";
            }
        }
        this->outfile << "\n";
    }
}

void Model::free()
{
    this->outfile.close();

    for (int i = 0; i < this->data_rows; i++)
    {
        delete (this->data[i]);
    }
    delete (this->data);

    delete (this);
}