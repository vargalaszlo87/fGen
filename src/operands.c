#include "variables.h"
#include "operands.h"
#include "create.h"

// seneral function

struct waveform binOperation(
	struct simulation *s,
	struct waveform *w1,
	struct waveform *w2,
	double (*op)(double, double)) 
	{
		int i = -1;
		struct waveform r = operation(s, w1, w2);	
		while (++i < s->step) {
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

struct waveform addWaves(struct simulation *s, struct waveform *w1, struct waveform *w2) {
	return binOperation(s, w1, w2, operationAdd);
}

struct waveform subWaves(struct simulation *s, struct waveform *w1, struct waveform *w2) {
	return binOperation(s, w1, w2, operationSub);
}

struct waveform mulWaves(struct simulation *s, struct waveform *w1, struct waveform *w2) {
	return binOperation(s, w1, w2, operationMul);
}

struct waveform divWaves(struct simulation *s, struct waveform *w1, struct waveform *w2) {
	return binOperation(s, w1, w2, operationDiv);
}
