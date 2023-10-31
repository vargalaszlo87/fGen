#ifndef SIGNALS_H
#define SIGNALS_H

/* periodic signals */
void makeSine(struct generator *, struct waveform *) ;
void makeSquare(struct generator *, struct waveform *);
/* non-periodic signals */
void makeSqrt(struct generator *, struct waveform *);
void makeLog(struct generator *, struct waveform *);
void makeLog2(struct generator *, struct waveform *);
void makeLog10(struct generator *, struct waveform *);
void makeLin(struct generator *, struct waveform *);

#endif
