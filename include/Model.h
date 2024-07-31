#ifndef MODEL_H
#define MODEL_H

#include <fstream>
#include "constants.h"


/**
 * @class This class implements the base class model.
 *
 * @param data_rows number of data rows
 * @param data_cols number of data colummns
 * @param time the value of the time
 * @param time_increment the value of the time increment
 * @param outfile outfile to print the data
 * @param data values of data
 * @param S value of the S constant
 *
 */
class Model
{

public:
    int data_rows;
    int data_cols;
    double time;
    double time_increment;
    std::ofstream outfile;
    float **data;
    bool perpetual;

public:
    /**
     * @brief This function initialices the model.
     *
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     *
     * @return Returns the model initialized.
     */
    Model(double time_increment, const char *filename);

    /**
     * @brief This function initialices the model.
     *
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param start_time time of starting

     * @return Returns the model initialized.
     */
    Model(double time_increment, const char *filename, double start_time);

    /**
     * @brief This function writes the data on file.
     *
     */
    void write_data();

    /**
     * @brief This function frees the data the data on file.
     *
     */
    void free();
};

#endif /* MODEL_H */