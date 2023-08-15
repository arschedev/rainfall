# 👨‍💻 rainfall
#### Matrix digital rain in terminal from [scratch](#lib)
![rainfall](./rainfall.gif)

## Installation
#### Platforms
- Linux
- Windows (WSL)
- macOS ([Building](#building))

```sh
# Linux/WSL
git clone https://github.com/arschedev/rainfall.git
cd rainfall
./build -install
```

#### Without installation
```sh
# Linux/WSL
git clone https://github.com/arschedev/rainfall.git
cd rainfall

./bin/rainfall
```

## Building
#### Dependencies
- gcc

###### Optional:
- valgrind
- quom
- cloc
```sh
# download
git clone https://github.com/arschedev/rainfall.git

# build
cd rainfall
./build

# install
./build -install
```

## How to use
After installation run `rainfall` in your terminal

## lib
Made for Linux. Will probably work for macOS.

Responsible for all the graphics and utilities used in *rainfall*, like rendering, multithreading, signal handling, RNG, etc.

`lib.h` being an entry point

`single/lib.h` a single include header file
