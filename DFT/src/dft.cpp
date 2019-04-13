#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "waveforms.hpp"
#include "math.h"

#define SIG_LENGTH 320
#define IMP_RSP_LENGTH 29


using namespace std;

double Output_REX[SIG_LENGTH/2];
double Output_IMX[SIG_LENGTH/2];


void calc_sig_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_length) {
    int i,j,k;
    double PI = 3.14159265359;

    for(j = 0; j < sig_length/2; j++) {
	sig_dest_rex_arr[j] = 0;
	sig_dest_imx_arr[j] = 0;
    }

    for(k = 0; k < sig_length/2; k++) {
	for(i = 0; i < sig_length; i++) {
	    sig_dest_rex_arr[k] += sig_src_arr[i] * cos(2*PI*k*i/sig_length);
	    sig_dest_imx_arr[k] -= sig_src_arr[i] * sin(2*PI*k*i/sig_length);
	}
    }
}
	
int main() {
    FILE *fptr1, *fptr2, *fptr3;

 
    calc_sig_dft(InputSignal_f32_1kHz_15kHz,
		 Output_REX,
		 Output_IMX,
		 SIG_LENGTH);
    
    fptr1 = fopen("input_sig.dat","w");
    fptr2 = fopen("output_rex.dat","w");
    fptr3 = fopen("output_imx.dat","w");

    for(int i = 0; i < SIG_LENGTH; i++) {
	fprintf(fptr1,"\n%f", InputSignal_f32_1kHz_15kHz[i]);
    }

    for(int i = 0; i < SIG_LENGTH; i++) {
	fprintf(fptr2,"\n%f", Output_REX[i]);
    }

    for(int i = 0; i < SIG_LENGTH; i++) {
	fprintf(fptr3,"\n%f", Output_IMX[i]);
    }
    
    return 0;
}
