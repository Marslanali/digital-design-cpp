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





