#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "waveforms.hpp"
#include "math.h"

#define SIG_LENGTH 320

double MEAN;
double VARIANCE;
double STD;

using namespace std;

double calc_signal_mean(double *sig_src_arr, int sig_length) {
    double _mean = 0.0;
    for(int i = 0; i < sig_length; i++){
	_mean += sig_src_arr[i];
    }
    _mean /= (double)sig_length;
    return _mean;
}

double calc_signal_variance(double *sig_src_arr, double sig_mean, int sig_length) {
    double _variance = 0.0;
    for(int i = 0; i < sig_length; i++) {
	_variance = _variance + pow((sig_src_arr[i] - sig_mean), 2);
    }
    _variance = _variance/(sig_length - 1);
    return _variance;
}

double calc_signal_std(double variance) {
    double _std = sqrt(variance);
    return _std;
}

int main() {
    MEAN = calc_signal_mean(InputSignal_f32_1kHz_15kHz, SIG_LENGTH);
    VARIANCE = calc_signal_variance(InputSignal_f32_1kHz_15kHz, MEAN, SIG_LENGTH);
    STD = calc_signal_std(VARIANCE);
    cout << "Mean: " << MEAN << endl;
    cout << "Variance: " << VARIANCE << endl;
    cout << "Standard Devaialtion: " << STD << endl;
}
