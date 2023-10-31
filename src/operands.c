#include "variables.h"
#include "operands.h"
#include "create.h"

struct waveform addWaves(struct generator *g, struct waveform *w1, struct waveform *w2) {
	int i = -1;
	struct waveform r = operation(g, w1, w2);
	while (++i < g->step) {
		*(r.outValue+i) = *(w1->outValue+i) + *(w2->outValue+i); 	
	}
	return r;
}

struct waveform subWaves(struct generator *g, struct waveform *w1, struct waveform *w2) {
	int i = -1;
	struct waveform r = operation(g, w1, w2);
	while (++i < g->step)
		*(r.outValue+i) = *(w1->outValue+i) - *(w2->outValue+i); 
	return r;
}

struct waveform mulWaves(struct generator *g, struct waveform *w1, struct waveform *w2) {
	int i = -1;
	struct waveform r = operation(g, w1, w2);
	while (++i < g->step)
		*(r.outValue+i) = *(w1->outValue+i) * *(w2->outValue+i); 
	return r;
}

struct waveform divWaves(struct generator *g, struct waveform *w1, struct waveform *w2) {
	int i = -1;
	struct waveform r = operation(g, w1, w2);
	while (++i < g->step) 
		*(r.outValue+i) = (*(w2->outValue+i) == 0) ? 0 : *(w1->outValue+i) / *(w2->outValue+i); 		
	return r;
}
