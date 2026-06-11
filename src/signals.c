#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "variables.h"
#include "signals.h"


// generator

void generate(simulation *s, waveform *w)
{
    switch(w->type)
    {
        case SIGNAL_SINE:
            makeSine(s, w);
            break;

        case SIGNAL_SQUARE:
            makeSquare(s, w);
            break;
			
		case SIGNAL_TRIANGLE:
            makeTriangle(s, w);
            break;

		case SIGNAL_SQRT:
            makeSqrt(s, w);
            break;

		case SIGNAL_LIN:
            makeLin(s, w);
            break;

		case SIGNAL_LOG:
            makeLog(s, w);
            break;


		case SIGNAL_LOG2:
            makeLog2(s, w);
            break;

		case SIGNAL_LOG10:
            makeLog10(s, w);
            break;

    }
}

// periodic signals

void makeSine(struct simulation *s, struct waveform *w) {
	int i = -1;
	making(s, w);
	while (++i < w->step) 
		*(w->outValue+i) = 
			w->offset 
			+ w->amplitude 
			* sin(
				2 * M_PI * (float)w->frequency * i * w->samplingTime);	
}

void makeSquare(struct simulation *s, struct waveform *w) {
	int i = -1;
	float temp = 0.0;
	making(s, w);
	while (++i < w->step) {
		temp =
			w->offset 
			+ w->amplitude 
			* sin(
				2 * M_PI * (float)w->frequency * i * w->samplingTime);

		*(w->outValue+i) = (temp < 0) ? -1*w->amplitude : w->amplitude;
	}
}

void makeTriangle(struct simulation *s, struct waveform *w) {
	int i = -1, j = 0, k = 0;
	making (s, w);
	float 
		mask[] = {
			0 + w->offset, 
			w->amplitude + w->offset, 
			0 + w->offset, 
			-w->amplitude + w->offset},
		countPeriod = s->simulationTime / (1.0 / w->frequency);
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

// non-periodic sisnals

void makeSqrt(struct simulation *s, struct waveform *w) {
	int i = -1;
	making(s, w);
	float temp = pow(1,2)/s->step;
	while (++i < w->step) 
		*(w->outValue+i) = sqrt(0 + i * temp);
}

void makeLog(struct simulation *s, struct waveform *w) {
	int i = -1;
	making(s, w);
	double temp = 2.71828/s->step;
	while (++i < w->step) 
		*(w->outValue+i) = (i == 0) ? log(1.0/s->step) : log(0 + i * temp);
}

void makeLog2(struct simulation *s, struct waveform *w) {
	int i = -1;
	making(s, w);
	float temp = pow(2,1)/s->step;
	while (++i < w->step) 
		*(w->outValue+i) = (i == 0) ? 0 : log2(0 + i * temp);
}

void makeLog10(struct simulation *s, struct waveform *w) {
	int i = -1;
	making(s, w);
	float temp = pow(10,1)/s->step;
	while (++i < w->step) 
		*(w->outValue+i) = (i == 0) ? 0 : log10(0 + i * temp);
}

void makeLin(struct simulation *s, struct waveform *w) {
	int i = -1;
	making(s, w);
	float temp = 1.0/s->step;
	while (++i < w->step) 
		*(w->outValue+i) = 0 + i * temp;	
}
