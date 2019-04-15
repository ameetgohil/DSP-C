#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "waveforms.hpp"
#include "math.h"

#define SIG_LENGTH 640
#define IMP_RSP_LENGTH 29


using namespace std;

double Output_REX[SIG_LENGTH/2];
double Output_IMX[SIG_LENGTH/2];
double Output_MAG[SIG_LENGTH/2];
double Output_IDFT[SIG_LENGTH];


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

void get_dft_output_mag(double *sig_dest_mag_arr) {
    for(int k = 0; k < SIG_LENGTH/2; k++) {
	sig_dest_mag_arr[k] = sqrt(pow(Output_REX[k],2) + pow(Output_IMX[k],2));
    }
}

void calc_sig_idft(double *idft_out_arr, double *sig_src_rex_arr, double *sig_src_imx_arr, int idft_length) {
    double PI = 3.14159265359;

    for(int k = 0; k < idft_length/2; k++) {
	sig_src_rex_arr[k] = sig_src_rex_arr[k]/(idft_length/2);
	sig_src_imx_arr[k] = -sig_src_imx_arr[k]/(idft_length/2);
    }

    sig_src_rex_arr[0] = sig_src_rex_arr[0]/2;
    sig_src_imx_arr[0] = -sig_src_imx_arr[0]/2;

    for(int i = 0; i < idft_length; i++) {
	idft_out_arr[i] = 0;
    }

    for(int k = 0; k < idft_length/2; k++) {
	for(int i = 0; i < idft_length; i++) {
	    idft_out_arr[i] += sig_src_rex_arr[k] * cos(2*PI*k*i/idft_length);
	    idft_out_arr[i] += sig_src_imx_arr[k] * sin(2*PI*k*i/idft_length);
	}
    }
}
	
int main() {
    FILE *fptr1, *fptr2, *fptr3, *fptr4, *fptr5;

 
    calc_sig_dft(_640_points_ecg_,
		 Output_REX,
		 Output_IMX,
		 SIG_LENGTH);
    get_dft_output_mag(Output_MAG);
    calc_sig_idft(Output_IDFT, Output_REX, Output_IMX, SIG_LENGTH); 
    
    fptr1 = fopen("input_sig.dat","w");
    fptr2 = fopen("output_rex.dat","w");
    fptr3 = fopen("output_imx.dat","w");
    fptr4 = fopen("output_idft.dat", "w");
    fptr5 = fopen("output_mag.dat", "w");

    for(int i = 0; i < SIG_LENGTH; i++) {
	fprintf(fptr1,"\n%f", _640_points_ecg_[i]);
    }

    for(int i = 0; i < SIG_LENGTH/2; i++) {
	fprintf(fptr2,"\n%f", Output_REX[i]);
    }

    for(int i = 0; i < SIG_LENGTH/2; i++) {
	fprintf(fptr3,"\n%f", Output_IMX[i]);
    }

    for(int i = 0; i < SIG_LENGTH/2; i++) {
	fprintf(fptr5, "\n%f", Output_MAG[i]);
    }

    for(int i = 0; i < SIG_LENGTH; i++) {
	fprintf(fptr4, "\n%f", Output_IDFT[i]);
    }
    
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    fclose(fptr4);
    fclose(fptr5);
    
    return 0;
}
