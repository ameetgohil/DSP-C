#include <stdio.h>
#include <stdlib.h>
#include <iostream>


#define SIG_LENGTH 320


using namespace std;

double calc_signal_mean(double *sig_src_arr, int sig_length) {
    double _mean = 0.0;
    for(int i = 0; i < sig_length; i++){
	_mean += sig_src_arr[i];
    }
    _mean /= (double)sig_length;
    return _mean;
}

int main() {
    cout << "Mean: " << calc_signal_mean(InputSignal_f32_1kHz_15kHz, SIG_LENGTH) << endl;
}
