#include "variables.h"
#include "adjust.h"

void inverse(struct waveform *w) {
	int i = -1;	
	while (++i < w->step) 
		*(w->outValue+i) *= -1;	
}
