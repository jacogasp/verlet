# Verlet Simulation

## Requirements
In order to compile you need CMake and SFML 2.5 or greater

```bash
# Mac
brew install cmake sfml

# Ubuntu
sudo apt install cmake sfml
```

## Build and Run

```bash
cd verlet
mkdir build
cd build
# Configure
cmake ../
# Build
cmake --build . -j4
```

```bash
./Verlet
```