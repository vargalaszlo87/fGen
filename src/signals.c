#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "variables.h"
#include "signals.h"

/* periodic signals */

void makeSine(struct generator *g, struct waveform *w) {
	int i = -1;
	making(g, w);
	while (++i < w->step) 
		*(w->outValue+i) = w->amplitude * sin(2*M_PI*(float)w->frequency*i*w->samplingTime);	
}

void makeSquare(struct generator *g, struct waveform *w) {
	int i = -1;
	float temp = 0.0;
	making(g, w);
	while (++i < w->step) {
		temp = w->amplitude * sin(2*M_PI*(float)w->frequency*i*w->samplingTime);
		*(w->outValue+i) = (temp < 0) ? -1*w->amplitude : w->amplitude;
	}
}

void makeTriangle(struct generator *g, struct waveform *w) {
	int i = -1, j = 0, k = 0;
	making (g, w);
	float 
		mask[] = {0, w->amplitude, 0, -w->amplitude},
		countPeriod = g->simulationTime / (1.0 / w->frequency);
	int increment = round(w->step / (countPeriod * 4));
	float incrementum = w->amplitude / increment; 
	while (++i < ceil(countPeriod)*4) {
		if (k == w -> step)
			return;			
		*(w->outValue+k++) = mask[i%4];
		j = 0;
		while (++j < increment) {	
			if (k == w -> step)
				return;
			*(w->outValue+k++) = mask[i%4] + incrementum * ((i%4 == 0 || i%4 == 3) ? +1 : -1) * j;		
		}
	}	
}

/* non-periodic signals */

void makeSqrt(struct generator *g, struct waveform *w) {
	int i = -1;
	making(g, w);
	float temp = pow(1,2)/g->step;
	while (++i < w->step) 
		*(w->outValue+i) = sqrt(0 + i * temp);
}

void makeLog(struct generator *g, struct waveform *w) {
	int i = -1;
	making(g, w);
	double temp = 2.71828/g->step;
	while (++i < w->step) 
		*(w->outValue+i) = (i == 0) ? log(1.0/g->step) : log(0 + i * temp);
}

void makeLog2(struct generator *g, struct waveform *w) {
	int i = -1;
	making(g, w);
	float temp = pow(2,1)/g->step;
	while (++i < w->step) 
		*(w->outValue+i) = (i == 0) ? 0 : log2(0 + i * temp);
}

void makeLog10(struct generator *g, struct waveform *w) {
	int i = -1;
	making(g, w);
	float temp = pow(10,1)/g->step;
	while (++i < w->step) 
		*(w->outValue+i) = (i == 0) ? 0 : log10(0 + i * temp);
}

void makeLin(struct generator *g, struct waveform *w) {
	int i = -1;
	making(g, w);
	float temp = 1.0/g->step;
	while (++i < w->step) 
		*(w->outValue+i) = 0 + i * temp;	
}
