![wqe](https://avatars1.githubusercontent.com/u/7837709?s=400&amp;v=4)

Gempyre
=====
UI Framework
-------------

Gempyre is a UI multiplatform framework. Supporting Windows, Mac OSX, Linux, Raspberry OS and Android. Gempyre is minimalistic and simple; It is a UI framework without widgets - instead, the UI is composed using common web tools and frameworks. Therefore Gempyre is small, easy to learn and quick to take in use.
 
For the application, Gempyre let engine to be implemented using C++ (or Python), the UI can be constructed using CSS and HTML like any front end. All common tools from the web technologies are be available. Gempyre library provides a simple and easy C++ API for a  application development and the whole API is only a few dozen calls.

Gempyre is intended for applications that has a solid C++ core (or C), and allows rapid UI development without extra hassle with platform specific UI development. 

Gempyre is multiplatform, its core is written using C++17  (tested OSX (CLang), Ubuntu (gcc), Raspberry OS (gcc) and Windows 10 (MSVC and MinGW) ). The Gempyre framework can be downloaded at Github under MIT license.

Gempyre itself does not contain an application window. The UI is drawn using external application. Some OSes defaults to system browser, some Python webview. However that is fully configurable per application. 

Gempyre is a library that is linked with the application, except for Android, see [Gempyre-Android](https://github.com/mmertama/Gempyre-Android). For Python, install [Gempyre-Python](https://github.com/mmertama/Gempyre-Python) on top of Gempyre library.


### Gempyre API 

* gempyre.h, everything that basic application needs.
* gempyre_utils.h, miscellaneous collection or function that helps writing applications. 
* gempyre_graphics.h,  helps developing graphics intensive applications and games.
* gempyre_client.h, provides file dialogs for Gempyre application. 

LINK_TO_DOXYGEN - https://dev.to/denvercoder1/using-github-actions-to-publish-doxygen-docs-to-github-pages-177g

### Linux

* Run
  ```bash
  linux_install.sh
  ```
  
### Mac OSX

* Run
  ```bash
   osx_install.sh
  ```
 
### Windows

* Install git bash from https://gitforwindows.org/
* Run git clone https://github.com/mmertama/Gempyre.git on git bash console.

#### MSVC

* Install cmake https://cmake.org/download/ (let it to be added in path)
* Install Visual Studio https://docs.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=vs-2019, and pick Desktop development with C++
* Install Python (latest, yet tested mostly with 3.10, but 3.6 >= shall be ok) https://www.python.org/downloads/windows/
* From Windows menu, Visual Studio: Open "x64 Native Tools Command Prompt for VS 2019" (later propably ok)
* Run 
   ```bat
    msvc_install.bat
   ```

#### MinGW

* Make sure you are using the right MinGW shell (Msys minGW 64-bit - one with blue icon (Not brown or cyan :-))
* See Instructions https://www.devdungeon.com/content/install-gcc-compiler-windows-msys2-cc
* Ensure Ninja is installed "packman -s base-devel gcc vim cmake ninja"
* Run
  ```bash
  mingw_install.sh
  ```
 
### Raspberry OS

 * Requires Rasberry OS Bullseye (older is ok, but you need more recent gcc in order to build C++17). Tested Raspberry Pi 3 and Raspberry Pi 4.  
 * Quite late Cmake is required, here are [snap instructions](https://snapcraft.io/install/cmake/raspbian#install).
 * Run
  ```bash
        pi@raspberrypi:~/Development/Gempyre ./raspberry_install.sh
   ```
 * When building on Raspberry, please pass -DRASPBERRY=1 for your cmake call. E.g. 
  ```bash
         pi@raspberrypi:~/Development/Tilze/build $ cmake .. -DRASPBERRY=1
   ```     

 ### Some example projects using Gempyre
 
 * [Examples](https://github.com/mmertama/Gempyre/tree/raspberry/examples)
 * [mandelbrot-Gempyre](https://github.com/mmertama/mandelbrot-Gempyre)
 * [treeview-Gempyre](https://github.com/mmertama/treeview-Gempyre)
 * [hexview-Gempyre](https://github.com/mmertama/hexview-Gempyre)
 * [calc-Gempyre](https://github.com/mmertama/calc-Gempyre)

 
 
 Some future development directions
---------------------

* Update / improve documentation (C++ and Python)  
* Binary releases (Maybe installer / some packet manager support / pip)
* Support for secure web socket (nice for remote UIs)
* Testing coverage and perf measurements.
* JS testing  

maybe not
* Flatbuffer/protobuf instead of JSON
* Using WASM instean of JS
* POC of Gempyre-Android style architecture also in core.git


Late updates
----------------

### 2021 1

* Proper build and install with cmake
* Use GTest for API testing
* Rewrote timers + other smaller fixes

### 2021 2

* Lot of fixes and some new utils
* Native application window for OSX, Linux and Windows are using [Hiillos] (https://github.com/mmertama/Hiillos)                        

### 2022 1

* Lot of fixes
* CI using Github actions 

### 2022 2

* Lot of fixes
* Raspberry, and imporoved MinGW support

### 2023 1
* Lot of fixed
* API changes and harmonize with GemGui-rs
* Testing coverage

### 2023 2
* Python UI fixes
* Performance update
* Refactoring internals
* Ready to change uwebsockets to libwebsockets or websockets++. (however not completed)
* Pedantic and Sanizers
* Supress external libry warnings (except MSVC not working, it seems :-/ )

Copyright Markus Mertama 2020, 2021, 2022, 2023

