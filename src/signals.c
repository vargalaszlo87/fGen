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

		case SIGNAL_SAWTOOTH:
			makeSawtooth(s, w);
			break;

		case SIGNAL_REVERSE_SAWTOOTH:
			makeReverseSawtooth(s, w);
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

		case SIGNAL_CHIRP:
			makeChirp(s, w);
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
				2 * M_PI * (float)w->frequency * i * w->samplingTime + w->phase);	
}

void makeSquare(struct simulation *s, struct waveform *w) {
    // default duty
	if (w->duty <= 0 || w->duty >= 100)
		w->duty = 50;

    making(s, w);
    float period = 1.0f / w->frequency;
    for (int i = 0; i < w->step; i++) {
        float t = i * w->samplingTime;
        float posInPeriod = fmod(t, period);
        float dutyTime =
            period * w->duty / 100.0f;
        *(w->outValue + i) =
            w->offset +
            ((posInPeriod < dutyTime)
                ? w->amplitude
                : -w->amplitude);
    }
}

void makeTriangle(struct simulation *s, struct waveform *w) {
    int i;
    making(s, w);
    for (i = 0; i < w->step; i++) {

        double t =
            i * w->samplingTime;
        double phaseTime =
            w->phase /
            (2.0 * M_PI * w->frequency);
        double period =
            1.0 / w->frequency;
        double x =
            fmod(
                t + phaseTime,
                period
            ) / period;

        double triangle =
            4.0 * fabs(x - 0.5) - 1.0;
        w->outValue[i] =
            w->offset
            - w->amplitude
            * triangle;
    }
}

void makeSawtooth(struct simulation *s, struct waveform *w) {
    int i;
    making(s, w);
    for (i = 0; i < w->step; i++) {

        double t =
            i * w->samplingTime;
        double phaseTime =
            w->phase /
            (2.0 * M_PI * w->frequency);
        double period =
            1.0 / w->frequency;
        double x =
            fmod(
                t + phaseTime,
                period
            ) / period;
        double saw =
            2.0 * x - 1.0;
        w->outValue[i] =
            w->offset +
            w->amplitude *
            saw;
    }
}

void makeReverseSawtooth(struct simulation *s, struct waveform *w) {
    int i;
    makeSawtooth(s, w);
    for (i = 0; i < w->step; i++) {
        w->outValue[i] =
            2.0 * w->offset
            - w->outValue[i];
    }

	printf ("\n\n%lf\n\n",w->duty);
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

// chirp

void makeChirp(struct simulation *s, struct waveform *w) {
	// precheck
	if (w->endFrequency == 0)
		w->endFrequency = w->frequency;

    making(s, w);
    float T = s->simulationTime;
    float k = (w->endFrequency - w->frequency) / T;
    for (int i = 0; i < w->step; i++) {
        float t =
            i * w->samplingTime;
        float phase =
            2.0f * M_PI *
            (
                w->frequency * t +
                0.5f * k * t * t
            );
        w->outValue[i] =
            w->offset +
            w->amplitude *
            sinf(phase + w->phase);
    }
}
