# WbLS

Water-based liquid scintillator (WbLS) is a novel detection medium that combines the positive
aspects of liquid scintillators, such as high light yield and low-threshold detection, with the superior sides of
pure water, such as minimal attenuation, directional reconstruction, and low-cost, into a single target. The
ability of its scintillator content to be tunable and loaded with several metal isotopes allows the cost-effective
execution of very broad physics programs for large-scale experiments. We create a custom tool for defining various WbLS cocktails in the Geant4 simulation package, envisioning that this material will be used extensively in this package in the future. With this tool, users can get various WbLS formulations as a G4Material object, including optical properties, with just a single line of code. 
             
## The package structure:   

_wbls_: This directory includes all required files for the definition of WbLS in Geant4. People who want to use WbLS should copy this directory to the source directory of their project and make the necessary adjustments in the CMakeList.txt file (See the CMakeList.txt in the provided example for help.).

_wbls/data_: This directory includes all data files for the chemical and optical properties of WbLS products.

_wbls/macros_: This directory includes a macro file for each WbLS product. Users can control all products' properties via user interface commands.

_wbls/include_: This directoy includes c++ header files for the definition of WbLS.

_wbls/src_: This directory includes c++ source files for the definition of WbLS.

_example_: This directory includes an example Geant4 application that demonstrates the use of various WbLS products. 

## Tested on 

* Os: Linux (Ubuntu 22.04.2 LTS)
* Architecture: x86_64
* Compiler: GCC 11.3.0
* Geant4.11.1.1

## How to run the provided example applications?   
  
1. Go to the directory where you installed the WbLS in your system.
  ```bash	
   cd path/To/WbLS
  ```
  
2. Create a directory named example-build in the same directory as example. 
  ```bash
   mkdir example-build
   ```

3. Now go inside this build directory and run CMake to generate the Makefiles needed to build the application. Two arguments are 
passed to CMake. The first argument to CMake is the path to the source directory that includes the CMakeList.txt file. The second argument is the path to the build directory where the generated make files will be located. CMake will now run to configure the build and generate Makefiles.
```bash
  cd example-build
  cmake -S ../example -B .
 ```
5. With the Makefile available, you can now build by simply running make: 
  ```bash
   make  
  ```
5. The application is now ready to run. If you now list the contents of your build directory, you will notice that the executable example has been created. The program can be executed in two modes: interactive and batch. To run in an interactive mode:
  ```bash
   ./example
```
 
 ## Contacts 

If you have any questions or wish to notify of updates and/or modification please contact: \
Mustafa Kandemir (mustafa.kandemir@erdogan.edu.tr)

