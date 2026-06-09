#include "variables.h"
#include "operands.h"
#include "create.h"

// general function

struct waveform binOperation(
	struct generator *g,
	struct waveform *w1,
	struct waveform *w2,
	double (*op)(double, double)) 
	{
		int i = -1;
		struct waveform r = operation(g, w1, w2);	
		while (++i < g->step) {
			*(r.outValue+i) = op(w1->outValue[i], w2->outValue[i]);
		}
		return r;
}

// callbacks

double operationAdd(double a, double b) {
		return a + b;
}

double operationSub(double a, double b) {
		return a - b;
}

double operationMul(double a, double b) {
		return a * b;
}

double operationDiv(double a, double b) {
		return (b == 0) ? 0 : a / b;
}

// interfaces

struct waveform addWaves(struct generator *g, struct waveform *w1, struct waveform *w2) {
	return binOperation(g, w1, w2, operationAdd);
}

struct waveform subWaves(struct generator *g, struct waveform *w1, struct waveform *w2) {
	return binOperation(g, w1, w2, operationSub);
}

struct waveform mulWaves(struct generator *g, struct waveform *w1, struct waveform *w2) {
	return binOperation(g, w1, w2, operationMul);
}

struct waveform divWaves(struct generator *g, struct waveform *w1, struct waveform *w2) {
	return binOperation(g, w1, w2, operationDiv);
}
