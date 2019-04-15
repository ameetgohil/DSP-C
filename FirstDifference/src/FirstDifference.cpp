#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "waveforms.hpp"
#include "math.h"

#define SIG_LENGTH 320


using namespace std;

double Output_signal[SIG_LENGTH];

void RunningSum(double *sig_src_arr,
		double *sig_dest_arr,
		int sig_src_length) {

    sig_dest_arr[0] = sig_src_arr[0];
    for(int i = 1; i < sig_src_length; i++) {
	sig_dest_arr[i] =  sig_src_arr[i] + sig_dest_arr[i-1] ;
    }

}

int main() {
    FILE *input_sig_fptr, *imp_rsp_fptr, *output_sig_fptr;;

    RunningSum(InputSignal_f32_1kHz_15kHz,
	       Output_signal,
	       SIG_LENGTH);


    input_sig_fptr = fopen("input_sig.dat","w");
    output_sig_fptr = fopen("output_sig.dat","w");

    for(int i = 0; i < SIG_LENGTH; i++) {
	fprintf(input_sig_fptr, "\n%f", InputSignal_f32_1kHz_15kHz[i]);
    }
    fclose(input_sig_fptr);


    for(int i = 0; i < SIG_LENGTH; i++) {
	fprintf(output_sig_fptr, "\n%f", Output_signal[i]);
    }
    fclose(output_sig_fptr);
    
}
