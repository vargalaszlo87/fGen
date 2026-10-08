
# fGen

This is an user friendly function generator in C. You can simple way generate different waveforms and do operations with them.




## Features


**`SIMULATION`**
- You can set the **simulation time**
- You can add the number of **simulaton steps**

**`WAVEFORMS`**

- **periodic** signals: *sine, square, triangle* 
- **non-periodic** signals: *square root, Log, Log2, Log10, Lin*


**`OPERATIONS`**
- **math:** *add, sub, mul, div*

**`OUTPUTS`**
- **showWaves:** *makes a list with two columns in console*
- **writeCSV:** *makes a CSV file with content of "showWaves"*
- **writeHeader:** *makes a standard C header file with two arrays*


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
	// create a simulation
	simulation sim = {
		.step = 1e5,
		.simulationTime = 1e-3
	};
	
```
Create a waveform:
```C
	// carrier signal
	waveform carrier = {
		.type = SIGNAL_SINE,
		.amplitude = 1,
		.frequency = 455e3,
		.offset = 0,
		.phase = 0
	};
	generate (&sim, &carrier);
```
Generate an output:
```C
showWaves(&carrier);
```

## Example

src/main.c file:

```C
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

	// make an 'out' waveform
	waveform out;
	
	// opreations
	out = mulWaves(&sim, &carrier, &voice);

	// write to stdout and CSV
	showWaves(&out);
	writeCSV(&out);	
		
	return 0 ;
}

```
## License

Distributed under the [MIT](https://choosealicense.com/licenses/mit/) License. See `LICENSE.txt` for more information.




## Contact

Varga Laszlo - https://vargalaszlo.com - mail@vargalaszlo.com

Project Link: https://github.com/vargalaszlo87/fGen

[![portfolio](https://img.shields.io/badge/my_portfolio-000?style=for-the-badge&logo=ko-fi&logoColor=white)](http://vargalaszlo.com)
