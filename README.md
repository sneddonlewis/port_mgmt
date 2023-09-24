[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.]
(http://www.repostatus.org/badges/latest/active.svg)](http://www.repostatus.org/#active)
[![CI](https://github.com/sneddonlewis/port_mgmt/actions/workflows/ci.yml/badge.svg)]
(https://github.com/sneddonlewis/port_mgmt/actions/workflows/ci.yml)

# Portfolio Management


## Structure
``` text
.
├── CMakeLists.txt
├── app
│   └── main.cpp
├── include
│   ├── example.h
├── src
│   └── example.cpp
└── tests
    ├── dummy.cpp
    └── main.cpp
```

## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Example:

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
make
./main
make test      # Makes and runs the tests.
make coverage  # Generate a coverage report.
make doc       # Generate html documentation.
```

