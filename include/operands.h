#ifndef OPERANDS_H
#define OPERANDS_H

struct waveform addWaves(struct simulation *, struct waveform *, struct waveform *);
struct waveform subWaves(struct simulation *, struct waveform *, struct waveform *);
struct waveform mulWaves(struct simulation *, struct waveform *, struct waveform *);
struct waveform divWaves(struct simulation *, struct waveform *, struct waveform *);

#endif
