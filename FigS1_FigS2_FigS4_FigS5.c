#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gsl/gsl_rng.h"

int main (int argc, char *argv[])
{
	unsigned long int seed = 1;
	unsigned long int n = 42;
	double q01 = 0.1;
	double q10 = 0.3;
	double p01 = 0.1;
	double p11 = 0.9;

	unsigned int i;

	gsl_rng *rng_mt = gsl_rng_alloc (gsl_rng_mt19937);
	gsl_rng_set (rng_mt, seed);

	char filename_system_state[41] = "FigS1_FigS2_FigS4_FigS5_system_state.dat";
	char filename_surveillance_data[46] = "FigS1_FigS2_FigS4_FigS5_surveillance_data.dat";

	FILE *datafile_system_state = fopen (filename_system_state, "w");
	FILE *datafile_surveillance_data = fopen (filename_surveillance_data, "w");

	unsigned int system_state, surveillance_data;

	if (gsl_rng_uniform(rng_mt)<q01/(q01+q10)) system_state=1; else system_state=0;

	fprintf (datafile_system_state, "%d ", system_state);

	if (system_state==0) {if (gsl_rng_uniform(rng_mt)<p01) surveillance_data=1; else surveillance_data=0;}
	else {if (gsl_rng_uniform(rng_mt)<p11) surveillance_data=1; else surveillance_data=0;}

	fprintf (datafile_surveillance_data, "%d ", surveillance_data);

	for (i=1; i<n; i++)
	{
		if (system_state==0 && gsl_rng_uniform(rng_mt)<q01) system_state=1;
		else if (system_state==1 && gsl_rng_uniform(rng_mt)<q10) system_state=0;

		fprintf (datafile_system_state, "%d ", system_state);

		if (system_state==0) {if (gsl_rng_uniform(rng_mt)<p01) surveillance_data=1; else surveillance_data=0;}
		else {if (gsl_rng_uniform(rng_mt)<p11) surveillance_data=1; else surveillance_data=0;}

		fprintf (datafile_surveillance_data, "%d ", surveillance_data);
	}

	fprintf (datafile_system_state, "\n", system_state);
	fprintf (datafile_surveillance_data, "\n", system_state);

	fclose (datafile_surveillance_data);
	fclose (datafile_system_state);

	return 0;
}

