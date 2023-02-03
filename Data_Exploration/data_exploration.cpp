#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

double comp_sum(vector<double> vect){
    double sum = 0;
    
    for (double val: vect)
        sum += val;

    return sum;
}

double comp_mean(vector<double> vect){
    double sum = comp_sum(vect);
    double mean = sum / vect.size();

    return mean;
}

double comp_median(vector<double> vect){
    double median;
    //ascending order
    sort(vect.begin(), vect.end());

    if(vect.size() % 2 == 0)
        //even size -> get average of two middle values
        median = (vect[(vect.size() / 2) - 1] + vect[vect.size() / 2] / 2);
    else
        median = vect[vect.size() / 2];

    return median;
}

double comp_range(vector<double> vect){
    double range;
    //ascending order to get first and last element
    sort(vect.begin(), vect.end());

    double min = vect[0];
    double max = vect[vect.size() - 1];

    range = max - min;
    return range;
}

double comp_covariance(vector<double> vect1, vector<double> vect2){
    //covariance is the sum of the products of each set's elements minus the set's mean, all divided by the set size minus one
    double covariance = 0;
    double mean_one = comp_mean(vect1);
    double mean_two = comp_mean(vect2);

    //both vectors are assumed to be same size
    for(int i = 0; i < vect1.size(); i++)
        covariance += (vect1[i] - mean_one) * (vect2[i] - mean_two);
    
    covariance = covariance / (vect1.size() - 1);

    return covariance;
}

double comp_correlation(vector<double> vect1, vector<double> vect2){
    //correlation is the covariance between two sets divided by the product of both standard deviations
    double correlation = 0;

    double covariance = comp_covariance(vect1, vect2);

    double std_dev_one = sqrt(comp_covariance(vect1, vect1));
    double std_dev_two = sqrt(comp_covariance(vect2, vect2));

    correlation = covariance / (std_dev_one * std_dev_two);

    return correlation;
}

void print_feature_stats(vector<double> vect){

    cout << "Sum: " << comp_sum(vect) << endl
        << "Mean: " << comp_mean(vect) << endl
        << "Median: " << comp_median(vect) << endl
        << "Range: " << comp_range(vect) << endl;

    return;
}

void print_observation_stats(vector<double> vect1, vector<double> vect2){

    cout << "Covariance: " << comp_covariance(vect1, vect2) << endl
        << "Correlation: " << comp_correlation(vect1, vect2) << endl;

    return;
}


void print_vector(vector<double> vect){
    for(double val : vect)
        cout << val << " ";
    cout << endl << "---------" << endl;
    
    return;
}

int main(){

    //take in csv as an arg
    cout << "Opening csv.." << endl;
    ifstream in_file("Boston.csv");
    string token;
    vector<double> rm(0);
    vector<double> medv(0);
    int observation_count = 0;

    //check if csv file is open
    if(!in_file.is_open()){
        cout << "Could not open \'Boston.csv\'" << endl;
        return 1;
    }

    //first line are the column headers
    string line;
    getline(in_file, line);
    cout << "Header: " << line << endl;

    //get observations
    while(!in_file.eof()){
        getline(in_file, token, ',');

        rm.push_back(stod(token));

        getline(in_file, token, '\n');

        medv.push_back(stod(token));

        observation_count++;
    }

    cout << "Size: " << observation_count << endl;

    //remove unfilled space in vector
    rm.resize(observation_count);
    medv.resize(observation_count);

    cout << "Closing csv.." << endl;
    in_file.close();

    //debug
    /*
    print_vector(rm);
    print_vector(medv);
    */

    //print analysis
    cout << "-----" << endl;
    print_feature_stats(rm);
    cout << "-----" << endl;
    print_feature_stats(medv);

    cout << "=====" << endl;
    print_observation_stats(rm, medv);

    return 0;

}