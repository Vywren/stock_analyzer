#include <iostream>
using namespace std;
#include "analyzer.h"

int main(){
    cout << "starting tests" << std::endl;
    double test_array[3][2] = {{3.21, 900},{4.52, 1000},{5.67, 1200}};
    cout << min_price((double*)test_array, 3) << std::endl;
    cout << max_price((double*)test_array, 3) << std::endl;
    cout << avg_price((double*)test_array, 3) << std::endl;
    return 0;
}
