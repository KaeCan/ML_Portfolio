#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

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

double sigmoid(double val){
    val = 1 / (1 + exp(-val));
    return val;
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

int main(int argc, char** argv){

    //read in csv
    ifstream in_file("titanic_project.csv");
    string token;
    vector<double> age_vect(0);
    vector<double> sex_vect(0);
    vector<double> survived_vect(0);
    vector<double> pclass_vect(0);

    vector<double> weights_vect(1);
    vector<double> data_matrix(800);
    vector<double> label_matrix(800);
    vector<double> probability_vect(800);
    vector<double> error_matrix(800);

    double error = 0;
    double learning_rate = 0.001;
    double w0 = 0;
    double w1 = 0;

    //get predictors

    //put predictors as vectors

    //get observations
    
    //only use sex as predictor for survival

    //use first 800 observations for training

    //



    return 0;
}