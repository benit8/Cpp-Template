# Project
C++ template project

Includes:
- CMake lists
- Command-line option parser
- General purpose lexing base class
- Basic logging
- Unit tests, with [Criterion](https://github.com/Snaipe/Criterion)

## Untemplatize the project headers
Edit the `do` script at the root of the project and set the `project_name` variable. Then run
```sh
./do init
```
This will replace the project name and set the year in all file headers.

## Build
```sh
./do
```
or
```sh
./do build
```

## Run
```sh
./do run
```
Arguments after `run` will get passed to the binary.

## Tests
This project includes unit tests, run them with
```sh
./do test
```

## Authors
- [Benoît Lormeau](mailto:blormeau@outlook.com)
