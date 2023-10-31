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

/*

// DEVELOP, problem with transformation!

void makeTriangle(struct generator *g, struct waveform *w) {	
	int i = -1, j = 0, k = 1;
	float mask[] = {1, 1, -1, -1}, x;	
	int *cross = (int*)calloc(k,sizeof(int));
	*(cross+(k)) = 0;	
	makeSquare(g,w);
	// cross-zero
	while (++i < w->step)
		if (*(w->outValue+i) != *(w->outValue+(i+1)) && i > 0 )
			*(cross+k) = i, cross = realloc(cross, k++*sizeof(int));
	// T/2 					
	i = 0;
	int *half = (int*)calloc(k,sizeof(int));
	*(half+0) = 0;
	while (++i < k)
		*(half+i) = (i < k) ? (*(cross+i)-*(cross+i-1))/2+*(cross+i-1) : *(cross+k-1);
	// T/4	
	int *quad = (int*)calloc(k+(k-1),sizeof(int));
	i = -1, j = 0;
	for (i = -1 ; i < (k+(k-1)) ; i+=2)
		*(quad+i) = *(half+j), *(quad+i+1) = *(cross+j++);		
	// out
	int l = 0, m = 0, n = 0;
	i = -1;
	while (++i < k+(k-1)) {

			x = w->amplitude / (*(quad+i+1)-*(quad+i)); 
		printf ("%lf ",x);
		j = *(quad+i)-1;
		while(++j < *(quad+i+1))
			*(w->outValue+n++) = (i%2 == 0) ? 0 + mask[m]*l++*x : mask[m]*(w->amplitude-l++*x);	
		m = (m == 3) ? 0 : m+1;
		l = 0;
	}
	free(cross);
	free(half);	 
}

*/

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
