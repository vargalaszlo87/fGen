#ifndef SIGNALS_H
#define SIGNALS_H

#include "create.h"

// generator
void generate(simulation *, waveform *);

// periodic signals 
void makeSine(struct simulation *, struct waveform *);
void makeSquare(struct simulation *, struct waveform *);
void makeTriangle(struct simulation *, struct waveform *);
void makeSawtooth(struct simulation *, struct waveform *);

// non-periodic signals 
void makeSqrt(struct simulation *, struct waveform *);
void makeLog(struct simulation *, struct waveform *);
void makeLog2(struct simulation *, struct waveform *);
void makeLog10(struct simulation *, struct waveform *);
void makeLin(struct simulation *, struct waveform *);

#endif
