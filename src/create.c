#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "variables.h"
#include "create.h"

void making(struct generator *g, struct waveform *w) {
	if (g->step <= 0 || g->simulationTime <=0) {
		printf ("The 'simulation time' and 'step' cannot be zero or negative.");
		exit(EXIT_SUCCESS);
	}		
	w->step = g->step;
	w->simulationTime = g->simulationTime;
	/* w->amplitude *= sqrt(2); */
	w->samplingTime = w->simulationTime/g->step;
	w->outTime = (float*)calloc(w->step, sizeof(float));
	w->outValue = (float*)calloc(w->step, sizeof(float));
	int i = -1;
	while (++i < w->step)
		*(w->outTime+i) = w->samplingTime * i;
}

struct waveform operation(struct generator *g, struct waveform *w1, struct waveform *w2) {
	struct waveform r;
	if (w1->step != w2->step)
		return r;
	r.step = g->step;
	r.samplingTime = g->simulationTime/g->step;
	r.outTime = (float*)calloc(g->step, sizeof(float));
	r.outValue = (float*)calloc(g->step, sizeof(float));	
	int i = -1;	
	while (++i < g->step)
		*(r.outTime+i) = r.samplingTime * i;
	r.result = 1;
	return r;	
}
