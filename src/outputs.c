#include <stdio.h>

#include "variables.h"
#include "outputs.h"

void showWaves(struct waveform *w) {
	int i = -1;
	fprintf (stdout,"Time[s];Value\n");
	while (++i < w->step) {
		fprintf (stdout, "%lf;%lf\n",*(w->outTime+i),*(w->outValue+i));
	}	
}

int writeCSV(struct waveform *w) {
	FILE *f;
	f = fopen("out.csv","w");
	if (f == NULL) {
		fprintf (stdout,"Error occurred while opening file.");
		return 1;
	}
	int i = -1;
	while (++i < w->step) {
		fprintf (f, "%lf;%lf\n",*(w->outTime+i),*(w->outValue+i));
	}
	fclose(f);
	return 0;
}

int writeHeader(struct waveform *w) {
	FILE *f;
	f = fopen("fgenwave.h","w");
	if (f == NULL) {
		fprintf (stdout,"Error occurred while opening file.");
		return 1;
	}
	fprintf (f,"#ifndef FGENWAVE_H\n#define FGENWAVE_H\n\ndouble fgenAmplitude[] = {");
	int i = -1;	
	while (++i < w->step) 
		fprintf (f, "%lf, ",*(w->outValue+i));
	fprintf (f, "};\n\ndouble fgenTime[] = {");
	i = -1;	
	while (++i < w->step) 
		fprintf (f, "%lf, ",*(w->outTime+i));
	fprintf (f, "};\n\n#endif\n");
	fclose(f);
} 


