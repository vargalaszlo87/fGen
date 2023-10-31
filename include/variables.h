#ifndef VARIABLES_H
#define VARIABLES_H

#ifndef M_PI
#define M_PI 3.14159265358979
#endif

typedef struct waveform {
	float amplitude;
	float frequency;
	float simulationTime;
	signed int step;
	float samplingTime;
	float *outTime;
	float *outValue;
	int result;	
} _waveform;

typedef struct generator {
	int step;
	float simulationTime;
} _generator;

#endif
