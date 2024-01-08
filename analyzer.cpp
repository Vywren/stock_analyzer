#include <iostream>
using namespace std;
#include "analyzer.h"

double avg_price(double *data_array, int points){
    cout << "starting avg test" << std::endl;
    double average = 0;
    for (int i = 0; i< points; i++){
        average += *(data_array + i * 2);
    }
    average = average / points;
    return average;
}

double min_price(double *data_array, int points){
    cout << "starting min test" << std::endl;
    double min = *data_array;
    cout << " I am here" << std::endl;
    for (int i = 0; i< points; i++){
        if(*(data_array + i * 2) < min){
            min = *(data_array + i * 2);
        }
    }
    cout << " I am here" << std::endl;
    return min;
}

double max_price(double *data_array, int points){
    cout << "starting max test" << std::endl;
    double max = *data_array;
    for (int i = 0; i< points; i++){
        if(*(data_array + i * 2) > max){
            max = *(data_array + i * 2);
        }
    }
    return max;
}

/*int main(){
    cout << "starting tests" << std::endl;
    double test_array[3][2] = {{3.21, 900},{4.52, 1000},{5.67, 1200}};
    cout << min_price((double*)test_array, 3) << std::endl;
    cout << max_price((double*)test_array, 3) << std::endl;
    cout << avg_price((double*)test_array, 3) << std::endl;
    return 0;
}*/