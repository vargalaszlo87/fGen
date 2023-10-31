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


