#include "variables.h"
#include "adjust.h"

void inverse(struct waveform *w) {
	int i = -1;	
	while (++i < w->step) 
		*(w->outValue+i) *= -1;	
}

void offset(struct waveform *w, float o) {
	int i = -1;	
	while (++i < w->step) 
		*(w->outValue+i) += o;		
}
