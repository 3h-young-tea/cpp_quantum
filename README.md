# Quantum in C++

A minimal C++ quantum bit simulator for 1 and 2 qubits.  
Designed for experimentation and competitions, including Microsoft Q# style challenges.

## Original Intention

I hate .net and C#.

## Features

- 1-qubit gates: Hadamard, X, Y, Z
- 2-qubit gates: Hadamard, X, CNOT
- Qubit collapse (measurement)
- Print state in human-readable format (`std::ostream` or `FILE*`)

## Quick Start

Include the header:

```cpp
#include "quantum.hpp"
````

## Compilation

```sh
g++ -o main main.cpp -std=c++14 -O2
```

## License

This project is licensed under the **GNU Affero General Public License v3.0 (AGPLv3)**.
See [LICENSE](LICENSE) for full details.
