#ifndef OPERANDS_H
#define OPERANDS_H

waveform addWaves(struct simulation *, struct waveform *, struct waveform *);
waveform subWaves(struct simulation *, struct waveform *, struct waveform *);
waveform mulWaves(struct simulation *, struct waveform *, struct waveform *);
waveform divWaves(struct simulation *, struct waveform *, struct waveform *);

#endif
