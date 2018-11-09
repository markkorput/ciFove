# ciFove
[Cinder](https://libcinder.org/) block (plugin) for the [Fove VR Headset](https://www.getfove.com/)

## Installation
This repository contains cinder block, see the [official cinder documentation](https://libcinder.org/docs/guides/cinder-blocks/index.html) on how to work with Cinder blocks.

The Fove SDK is included in the the repository, but (at the moment of writing) only supports the Windows platform. The ciFove block is written in a way that allows you to compile and run you Cinder application on other platforms as well, replacing the Fove SDK implementation with a function-less mock implementation.


## Building your Cinder application with ciFove

We recommend using CMake configurations for your Cinder project, as it lets you both build from the command line as well as generate platform-specific roject files -among others- Visual Studio and XCode.

** First make sure ciFove is added to your project's CMakeLists.txt file **

See the CMakeLists.txt examples in this repo (TODO: add links)

_Using make_
```bash
cd <into/your/app/folder>
mkdir build
cd build
cmake ../proj/cmake
make -j4
```

_Using Visual Studio_
```bash
cd <into/your/app/folder>
mkdir build
cd build
cmake ../proj/cmake -G "Visual Studio 10 Win64"
# Open the generated Visual Studio Solution Project
```

_Using XCode_
```bash
cd <into/your/app/folder>
mkdir build
cd build
cmake ../proj/cmake -GXcode
# Open the generated XCode project
```

## API Usage
TODO
