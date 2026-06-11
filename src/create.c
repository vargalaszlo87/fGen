#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "variables.h"
#include "create.h"
#include "language.h"

void making(struct simulation *s, struct waveform *w) {
	if (s->step <= 0 || s->simulationTime <=0) {
		fprintf (stderr, ERROR_SIMULATION_ZERO_OR_NEGATIVE);
		exit(EXIT_FAILURE);
	}		
	w->step = s->step;
	w->simulationTime = s->simulationTime;
	w->samplingTime = w->simulationTime/s->step;
	w->outTime = (float*)calloc(w->step, sizeof(float));
	w->outValue = (float*)calloc(w->step, sizeof(float));
	if (!w->outTime || !w->outValue) {
		fprintf (stderr, ERROR_ALLOC);
		exit(EXIT_FAILURE);
	}
	int i = -1;
	while (++i < w->step)
		*(w->outTime+i) = w->samplingTime * i;
}

struct waveform operation(struct simulation *s, struct waveform *w1, struct waveform *w2) {
	struct waveform r = {0};
	if (w1->step != w2->step)
		return r;
	r.step = s->step;
	r.samplingTime = s->simulationTime/s->step;
	r.outTime = (float*)calloc(s->step, sizeof(float));
	r.outValue = (float*)calloc(s->step, sizeof(float));
	if (!r.outTime || !r.outValue) {
		fprintf (stderr, ERROR_ALLOC);
		exit(EXIT_FAILURE);
	}		
	int i = -1;	
	while (++i < s->step)
		*(r.outTime+i) = r.samplingTime * i;
	r.result = 1;
	return r;	
}
