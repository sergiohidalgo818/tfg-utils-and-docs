#include "../include/Model.h"

Model::Model(double time_increment, const char *filename)
{
    this->time_increment = time_increment;
    this->time = 0;
    this->outfile.open(filename);
    this->perpetual = true;

    this->data = new std::vector<std::vector<float>>();
}

Model::Model(double time_increment, const char *filename, float start_time)
{
    this->time_increment = time_increment;
    this->time = start_time;
    this->outfile.open(filename);
    this->perpetual = true;

    this->data = new std::vector<std::vector<float>>();
}


void Model::write_vector()
{
    //TO-DO eliminate vector

    for (std::vector<std::vector<float>>::iterator data_iterator = this->data->begin(); data_iterator != this->data->end(); ++data_iterator)
    {
        for (std::vector<float>::iterator value_iterator = data_iterator->begin(); value_iterator != data_iterator->end(); ++value_iterator)
        {
            this->outfile << *value_iterator;

            if (value_iterator + 1 != data_iterator->end())
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

    this->data->clear();

    delete (this);
}