#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "waveforms.hpp"
#include "math.h"

#define SIG_LENGTH 320
#define IMP_RSP_LENGTH 29


using namespace std;

double Output_signal[SIG_LENGTH+IMP_RSP_LENGTH];

void convolution(double *sig_src_arr,
		 double *sig_dest_arr,
		 double *imp_rsp_arr,
		 int sig_src_length,
		 int imp_rsp_length) {
    
    for(int i = 0; i < sig_src_length + imp_rsp_length; i++) {
	sig_dest_arr[i] = 0;
    }

    for(int i = 0; i < sig_src_length; i++) {
	for(int j = 0; j < imp_rsp_length; j++) {
	    sig_dest_arr[i+j] += sig_src_arr[i] * imp_rsp_arr[j];
	}
    }
}

int main() {
    FILE *input_sig_fptr, *imp_rsp_fptr, *output_sig_fptr;;

    convolution(InputSignal_f32_1kHz_15kHz,
		Output_signal,
		Impulse_response,
		SIG_LENGTH,
		IMP_RSP_LENGTH);

    input_sig_fptr = fopen("input_sig.dat","w");
    imp_rsp_fptr = fopen("impulse_rsp.dat","w");
    output_sig_fptr = fopen("output_sig.dat","w");

    for(int i = 0; i < SIG_LENGTH; i++) {
	fprintf(input_sig_fptr, "\n%f", InputSignal_f32_1kHz_15kHz[i]);
    }
    fclose(input_sig_fptr);

    for(int i = 0; i < IMP_RSP_LENGTH; i++) {
	fprintf(imp_rsp_fptr, "\n%f", Impulse_response[i]);
    }
    fclose(imp_rsp_fptr);

    for(int i = 0; i < IMP_RSP_LENGTH+SIG_LENGTH; i++) {
	fprintf(output_sig_fptr, "\n%f", Output_signal[i]);
    }
    fclose(output_sig_fptr);
    
}
