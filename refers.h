//
// Created by s3 on 03.04.18.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;
const double EPS = 1e-3;
const double U = 0;

void zMethod(vector<vector<double>>, vector<double>, vector<double>);
void gMethod(vector<vector<double>>, vector<double>);
void showmatrix(vector<vector<double>>);
void showvector(vector<double>);
vector<vector<double>> monm(vector<vector<double>>,vector<vector<double>>);
vector<vector<double>> transpone(vector<vector<double>>);