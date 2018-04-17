//
// Created by s3 on 03.04.18.
//
#include "refers.h"

void showmatrix(vector<vector<double>> matrix){
    int r=matrix.size();
    int c=matrix[0].size();
    for (int i = 0; i < r; i++) {
        cout<<endl;
        for (int j = 0; j < c; j++) cout<< ' ' <<matrix[i][j];
    }
    cout<<endl;
}
void showvector(vector<double> v){
    int r=v.size();
    for (int i = 0; i < r; i++) {
        cout <<' '<<setprecision(4)<< v[i];
    }
    cout<<endl;
}
vector<vector<double>> monm(vector<vector<double>> A,vector<vector<double>> B) {//matrix on matrix
    vector<vector<double>> result(A.size(), vector<double>(B[0].size()));
    for (int i = 0; i < result.size(); i++)
        for (int j = 0; j < result[i].size(); j++) {
            result[i][j] = 0;
            for (int k = 0; k < A[0].size(); k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    return result;
}
vector<vector<double>> transpone(vector<vector<double>> A){
    vector<vector<double>> result(A[0].size(),vector<double>(A.size()));
    for (int i=0;i<A.size();i++){
        for (int j=0;j<A[i].size();j++){
            result[j][i]=A[i][j];
        }
    }
    return result;
}