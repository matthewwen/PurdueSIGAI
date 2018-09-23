#include <iostream>
#include "Housing.hpp"
#include <vector>
#include <math.h>
#include <fstream>
#include "Point.hpp"

double getAverage(std::vector<double> vec); 
void scanHousing(std::vector<Housing> * vec); 
std::vector<double> get_d_r_values(std::vector<Housing> * hous, int index); 

int main()
{
	std::vector<Housing> all_housing(0); //all the housing in one vector array

	std::vector<double> x_values(0); //all the input values for a function
	std::vector<double> y_values(0); //all the output values for a function 

	double x_average; //the average of all the input values
	double y_average; //the average of all the output values

	//scan documents
	scanHousing(&all_housing); 

	//getting x values and w yavlues  
	x_values = get_d_r_values(&all_housing, 0); 
	y_values = get_d_r_values(&all_housing, 1); 

	///getting the average for domain and range 
	x_average = getAverage(x_values); 
	y_average = getAverage(y_values); 

	std::cout << "x average: " << x_average << std::endl; 
	std::cout << "y average: " << y_average << std::endl; 


	return 0; 
}


/*
* Parameter: vec, vector<double>, a vector with a set of values
* Return: the average value
*/
double getAverage(std::vector<double> vec)
{
	if (vec.size() == 0){
		return 0; 
	}

	double sum = 0.0; 
	for (int i = 0; i < vec.size(); i++){
		sum += vec[i]; 
	}

	return sum / vec.size(); 
};

/*
* Parameter: vec, address of vector, list of all the housing options  
* Return: void, null 
*/ 
void scanHousing(std::vector<Housing> * vec)
{
	//opening the file 
	std::ifstream ip; 
	ip.open("california_housing_train.csv"); 

	//getting the headings
	std::string val; 
	getline(ip, val, '\n');  

	//setting it into vector 
	while (ip.good()){
		std::string longitude; 
		std::string latitude; 
		std::string housing_median_age; 
		std::string total_rooms; 
		std::string total_bedrooms; 
		std::string population; 
		std::string households; 
		std::string median_income; 
		std::string median_house_value; 

		getline(ip, longitude, ','); 
		getline(ip, latitude, ','); 
		getline(ip, housing_median_age, ','); 
		getline(ip, total_rooms, ','); 
		getline(ip, total_bedrooms, ','); 
		getline(ip, population, ','); 
		getline(ip, households, ','); 
		getline(ip, median_income, ','); 
		getline(ip, median_house_value, '\n'); 

		Housing temp(stod(longitude), stod(latitude), 
			stod(housing_median_age), stod(total_rooms), 
			stod(total_bedrooms), stod(population), 
			stod(households), stod(median_income), 
			stod(median_house_value)); 
	
		vec->push_back(temp); 
	}

	ip.close(); 
}


/* 
*Paramter: hous, address of Housing, list of all the housing options 
*		   index, int, the logitutde etc. it want to return 
*Return: vector<double> list of all the values for that particualar column (input/output)
*/
std::vector<double> get_d_r_values(std::vector<Housing> * hous, int index)
{
	std::vector<double> vec(0); 
	for (int i = 0; i < hous->size(); i++)
	{
		vec.push_back((*hous)[i].get_value(index)); 
	}
	return vec; 
}