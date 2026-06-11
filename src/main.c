#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fgen.h"

int main(int argc, char *argv[]) {
	
	// create a simulation
	simulation sim;
	sim.step = 10000;
	sim.simulationTime = 0.1755;
	
	// create a sine signal
	waveform signal = {0};
	signal.amplitude = 230;
	signal.frequency = 120;
	makeSine(&sim, &signal);	

	// crate a sine noise-signal
	waveform noise;
	noise.amplitude = 23;
	noise.frequency = 5000;
	noise.offset = 2;
	noise.phase = 3;
	makeSine(&sim, &noise);

	// create a ramp (sqrt function)
	waveform ramp;
	makeSqrt(&sim, &ramp);

	// make an 'out' waveform
	waveform out;
	
	// add two signals (out = signal + noise)
	// multiply two signals (out = out * ramp)
	out = addWaves(&sim, &signal, &noise);
	out = mulWaves(&sim, &out, &ramp);

	// write to stdout and CSV
	showWaves(&out);
	writeCSV(&out);	
		
	return 0 ;
}
