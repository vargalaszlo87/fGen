#ifndef VARIABLES_H
#define VARIABLES_H

#ifndef M_PI
#define M_PI 3.14159265358979
#endif

typedef enum {
    SIGNAL_SINE,
    SIGNAL_SQUARE,
    SIGNAL_TRIANGLE,
	SIGNAL_SAWTOOTH,
	SIGNAL_REVERSE_SAWTOOTH,
    SIGNAL_SQRT,
    SIGNAL_LIN,
	SIGNAL_LOG,
	SIGNAL_LOG2,
	SIGNAL_LOG10
} signalType;

typedef struct waveform {
	// type
	signalType type;

	// external variables
	float amplitude;		// [V]
	float frequency;		// [Hz]
	float offset;			// [V]
	float phase;			// [rad]

	// internal variables
	float simulationTime;	// [s]
	float samplingTime;		// [s]
	signed int step;
	float *outTime;
	float *outValue;
	int result;	
} waveform;

typedef struct simulation {
	int step;
	float simulationTime;
} simulation;

#endif
