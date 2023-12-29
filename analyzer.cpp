#include <iostream>
using namespace std;

double avg_price(double **data_array, int points){
    int average = 0;
    for (int i = 0; i< points; i++){
        average += data_array[i][0];
    }
    average = average / points;
    return average;
}

double min_price(double **data_array, int points){
    int min = data_array[0][0];
    for (int i = 0; i< points; i++){
        if(data_array[i][0] < min){
            min = data_array[i][0];
        }
    }
    return min;
}

double max_price(double **data_array, int points){
    int max = data_array[0][0];
    for (int i = 0; i< points; i++){
        if(data_array[i][0] > max){
            max = data_array[i][0];
        }
    }
    return max;
}

int main(){
    double test_array[3][2] = {{3.21, 900},{4.52, 1000},{5.67, 1200}};
    cout << min_price((double**)test_array, 3) << std::endl;
    cout << max_price((double**)test_array, 3) << std::endl;
    cout << avg_price((double**)test_array, 3) << std::endl;
    return 0;
}