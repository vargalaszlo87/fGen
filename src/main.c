#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fgen.h"

int main(int argc, char *argv[]) {

	(void)argc;
	(void)argv;
	
	// create a simulation
	simulation sim = {
		.step = 1e5,
		.simulationTime = 1e-3
	};
	
	// carrier signal
	waveform carrier = {
		.type = SIGNAL_SINE,
		.amplitude = 1,
		.frequency = 455e3,
		.offset = 0,
		.phase = 0
	};
	generate (&sim, &carrier);

	waveform voice = {
		.type = SIGNAL_SINE,
		.amplitude = 1,
		.frequency = 2e3,
		.offset = 1.5,
		.phase = 0
	};
	generate (&sim, &voice);

	waveform square = {
		.type = SIGNAL_SQUARE,
		.amplitude = 1.23,
		.frequency = 2e3,
		.offset = 1,
		.phase = M_PI / 2,
		.duty = 75
	};
	generate (&sim, &square);


	// make an 'out' waveform
	waveform out;
	
	// opreations
	out = mulWaves(&sim, &carrier, &voice);

	// write to stdout and CSV
	//showWaves(&out);
	writeCSV(&square);	
		
	return 0 ;
}
