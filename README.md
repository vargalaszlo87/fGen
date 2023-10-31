
# fGen

This is an user friendly function generator in C. You can simple way generate different waveforms and do operations with them.




## Features


**`SIMULATION`**
- You can set the **simulation time**
- You can add the number of **simulaton steps**

**`WAVEFORMS`**

- **periodic** signals: *sine, square* 
- **non-periodic** signals: *square root, Log, Log2, Log10, Lin*


**`OPERATIONS`**
- **math:** *add, sub, mul, div*


## Getting started

To use this repository, you will need:
- GCC (or similar C compiler)

#### Clone source

```
git clone https://github.com/vargalaszlo87/fGen.git
```

#### Quick build

If you use **`Windows`**

:red_circle: Important! Check the `gcc --help` command in your Command Prompt. If it doesn't work you need add GCC to system variable (PATH).
```
install.bat
```

If you use **`Linux`**

```
install.sh
```

#### Self compiling
If you use **`Windows`**

```
gcc -c src/main.c -o build/main.o -I"include"
gcc -c src/signals.c -o build/signals.o -I"include" 
gcc -c src/operands.c -o build/operands.o -I"include" 
gcc -c src/outputs.c -o build/outputs.o -I"include" 
gcc -c src/adjust.c -o build/adjust.o -I"include"
gcc -c src/create.c -o build/create.o -I"include"
gcc build/main.o build/signals.o build/outputs.o build/adjust.o build/create.o -o bin/fGen.exe
```

If you use **`Linux`**

```
gcc -c src/main.c -o build/main.o -I"include" -lm
gcc -c src/signals.c -o build/signals.o -I"include" -lm
gcc -c src/operands.c -o build/operands.o -I"include" -lm
gcc -c src/outputs.c -o build/outputs.o -I"include" -lm
gcc -c src/adjust.c -o build/adjust.o -I"include" -lm
gcc -c src/create.c -o build/create.o -I"include" -lm
gcc build/main.o build/signals.o build/outputs.o build/adjust.o build/create.o -o bin/fGen
```
## Usage

Insert your headers:
```C
#include "fgen.h"
```
Create a simulation:
```C
struct generator g;
g.step = 10000;               /* number of steps */
g.simulationTime = 0.1755;    /* time in seconds */
```
Create a waveform:
```C
struct waveform signal;
signal.amplitude = 230;       /* set amplitude */
signal.frequency = 120;       /* set frequency */
makeSine(&g, &signal);
```
Generate an output:
```C
showWaves(&signal);
```

## Example

src/main.c file:

```C
#include <stdio.h>
#include <stdlib.h>

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

```
## License

Distributed under the [MIT](https://choosealicense.com/licenses/mit/) License. See `LICENSE.txt` for more information.




## Contact

Varga Laszlo - https://vargalaszlo.com - mail@vargalaszlo.com.com

Project Link: https://github.com/vargalaszlo87/fGen

[![portfolio](https://img.shields.io/badge/my_portfolio-000?style=for-the-badge&logo=ko-fi&logoColor=white)](http://vargalaszlo.com)