#include "Model.hpp"

/*
Paramter: vector, coefficent, the coefficients of the model 
Description: constructor method that sets the coefficients 
* of the model 
Return: void, nothing 
*/ 
Model::Model(std::vector<double> coefficient)
{
    this->coefficient = coefficient; 
}

/*
Paramter: void, nothing 
Description: Empty Construction
Return: void, nothing 
*/
Model::Model(){}

/*
Paramter: vector, inputs, the input values for model
Description: based off the inputs, this gets a predicted
* output based off the model 
Return: double, predicted output 
*/
double Model::get_p(std::vector<double> inputs)
{
    double sum = 0; 
    for (int i = 0; i < inputs.size(); i++)
    {
        sum += get_c(i) * inputs[i]; 
    }

    return sum; 
}

/*
Paramter: int, pos, the position for the coefficent 
Description: this get's the coefficient based off a given 
* index ex. (0, longitude or 1, latitude)
Return: double, coefficient for that input value 
*/
double Model::get_c(int pos)
{
    return this->coefficient[pos]; 
}

/*
Paramter: vector, coefficient, the coefficients of model 
Description: this sets the coefficent of the model 
Return: void, nothing 
*/ 
void Model::set_coef(std::vector<double> coefficient)
{
    this->coefficient = coefficient; 
}