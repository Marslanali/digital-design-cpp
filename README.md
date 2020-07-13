# Digitaldesign

### Build code

```
cd digitaldesign
mkdir build
cd build
cmake ..
make
```

### Run the Subtractor 
```
./digitaldesign /home/arslan/CLionProjects/digitaldesign/data/sub64.txt
```


### Some Terminal Outputs 
```
No. of gates: 439
No. of wires: 567


No. of inputs: 2
No. of input bits: 64


No. of outputs: 1
No. of output bits: 64


Input A (64 bits): 
0010101101100010101010101000101010101001010110110011011110001010

Input B (64 bits): 
0000010101101100010101010101000101010101001010110110011011110000

No. of XOR: 313
No. of AND: 63
No. of INV: 63

```


### 64 bit output Subtractor

```
Wires Indexes:

566 565 564 563 562 561 560 559 558 557 556 555 554 553 552 551 550 549 548 547 546 545 544 543 542 541 540 539 538 537 536 535 534 533 532 531 530 529 528 527 526 525 524 523 522 521 520 519 518 517 516 515 514 513 512 511 510 509 508 507 506 505 504 503 

64 bit output on those Indexes:

0010010111110110010101010011100101010100001011111101000010011010

```




### Run The Adder
```
./digitaldesign /home/arslan/CLionProjects/digitaldesign/data/adder64.txt
```


### Some Terminal Outputs 
```
No. of gates: 376
No. of wires: 504


No. of inputs: 2
No. of input bits: 64


No. of outputs: 1
No. of output bits: 64


Input A (64 bits): 
0010101101100010101010101000101010101001010110110011011110001010

Input B (64 bits): 
0000010101101100010101010101000101010101001010110110011011110000

No. of XOR: 313
No. of AND: 63
No. of INV: 0

```


### 64-bit output Adder

```
Wires Indexes:

503 502 501 500 499 498 497 496 495 494 493 492 491 490 489 488 487 486 485 484 483 482 481 480 479 478 477 476 475 474 473 472 471 470 469 468 467 466 465 464 463 462 461 460 459 458 457 456 455 454 453 452 451 450 449 448 447 446 445 444 443 442 441 440 

64 bit output on those Indexes:

0011000011001110111111111101101111111110100001101001111001111010

```

# Building Code on Windows with CLION, CMAKE


### Prerequisite

The program requires:

  - MinGW 
  - GCC 
  - Cmake
  - GNU MAKE
  - BOOST  

### MinGW installation

Make sure latest to download latest version, see https://sourceforge.net/projects/mingw-w64/ for download.
Run the MinGW executable for the installation, and once completed, we have to add ENV in advanced system setting. 

<p align="left">
   <img src="screen-shots/env.jpg" width ="300" height="300"/>  
  <br/>
  Fig. ENV for MinGW in windows
</p>

This will allows you to test GCC either from windows power shell or windows cmd.
To verify GCC is installed correctly, open Power shell as an admininstrator and type:

```
gcc --version

```

You will see your version number, if not, check your environment variable again. 


### CMake Installation

Make sure latest to download latest version, see https://cmake.org/download/ for download.
Run the CMake executable for the installation, and once completed, we have to add ENV in advanced system setting. 

<p align="left">
   <img src="screen-shots/env.jpg" width ="300" height="300"/>  
  <br/>
  Fig. ENV for CMake in windows
</p>

This will allows you to test CMake either from windows power shell or windows cmd.
To verify CMake is installed correctly, open Power shell as an admininstrator and type:

```
cmake --version

```

You will see your version number, if not, check your environment variable again. 


### GNU MAKE Installation

Make sure latest to download latest pre-built binaries version, see http://gnuwin32.sourceforge.net/packages/ for download.
Run the GNU MAKE setup executable file for the installation, and once completed, we have to add ENV in advanced system setting. 

<p align="left">
   <img src="screen-shots/env.jpg" width ="300" height="300"/>  
  <br/>
  Fig. ENV variable for GNU MAKE in windows
</p>

This will allows you to test & run make either from windows power shell or windows cmd.
To verify GNU make is installed correctly, open Power shell as an admininstrator and type:

```
make --version

```

You will see your version number, if not, check your environment variable again using below screenshots.



<p align="left">
   <img src="screen-shots/environement.jpg" width ="300" height="300"/>  
  <br/>
  Fig. ALL ENV variable in windows
</p>


<p align="left">
   <img src="screen-shots/gcc.jpg" width ="300" height="300"/>  
  <br/>
  Fig. ENV variable for GNU GCC in windows
</p> 


### BOOST installation

Make sure latest to download latest version, see https://sourceforge.net/projects/boost/files/boost-binaries/1.55.0/ for download.
Unzip and place all file under C:/Program Files/boost_1_66_0, and once completed, we can used it usign CMakeList.txt in our source code.


```
find_package(Boost 1.34)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(digitaldesign  ${PROJECT_SOURCE_DIR}/main.cpp)

    target_link_libraries(digitaldesign ${Boost_LIBRARIES})

endif()


```

The CMake message tab on CLION should print like this:

```
Found Boost: C:/Program Files/boost_1_66_0 (found suitable version "1.66.0", minimum required is "1.34")
-- Configuring done
-- Generating done
-- Build files have been written to: C:/Users/Arslan Ali/CLionProjects/test/cmake-build-debug

```

### Compile and Run


open cmd or power shell as an administrator, and go to the CLION project directory


```
cd digitaldesign
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
make

```

The flag `-G "MinGW Makefiles"` is necessary if you are using power shell or cmd. 

### Run The Adder
```
& ".\digitaldesign.exe" 'C:\Users\Arslan Ali\CLionProjects\digitaldesign\data\adder64.txt'
```


# Building Code on Windows with Ubuntu Shell


### Prerequisite

The program requires:

  - GCC/g++
  - Cmake
  - BOOST  

Install using apt-get in Ubunut Shell in windows

```
sudo apt install g++ 

sudo apt install cmake 

sudo apt install libboost-dev

 ```
