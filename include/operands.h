#ifndef OPERANDS_H
#define OPERANDS_H

struct waveform addWaves(struct generator *, struct waveform *, struct waveform *);
struct waveform subWaves(struct generator *, struct waveform *, struct waveform *);
struct waveform mulWaves(struct generator *, struct waveform *, struct waveform *);
struct waveform divWaves(struct generator *, struct waveform *, struct waveform *);

#endif
