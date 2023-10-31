#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fgen.h"

int main(int argc, char *argv[]) {
	
	// create a simulation
	struct generator g;
	g.step = 10000;
	g.simulationTime = 0.1755;
	
	// create a sine signal
	struct waveform signal;
	signal.amplitude = 230;
	signal.frequency = 120;
	makeSine(&g, &signal);

	// crate a sine noise-signal
	struct waveform noise;
	noise.amplitude = 23;
	noise.frequency = 5000;
	makeSine(&g, &noise);

	// create a ramp (sqrt function)
	struct waveform ramp;
	makeSqrt(&g, &ramp);

	// make an 'out' waveform
	struct waveform out;
	
	// add two signals (out = signal + noise)
	// multiply two signals (out = out * ramp)
	out = addWaves(&g, &signal, &noise);
	out = mulWaves(&g, &out, &ramp);

	// write to stdout and CSV
	showWaves(&out);
	writeCSV(&out);	
		
	return 0 ;
}
