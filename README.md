# Digitaldesign

### Build code

```
cd digitaldesign
mkdir build
cd build
cmake ..
make
```

### Online Calculator/Links:

```
1. Online Calculator link: https://www.rapidtables.com/calc/math/binary-calculator.html

2. Binary to Decimal Convert link: https://www.rapidtables.com/convert/number/binary-to-decimal.html

3. No. of bits count link: https://wordcounter.net/

4. And finally link for comparing outputs: https://text-compare.com/
```

### Questions & Answers


### a)
replace constants XOR/AND/INV with enum


### b)

In circuit.cpp/h, you have 2 methods : read_inputs_A and read_inputs_b: Can you make one overloaded method.

Ans:

For both `read_inputs_A` and `read_inputs_b` they are returning pointer to array. If I will make one overloaded method,
than I cannot return the pointer to two arrays (separately) i.e. only one array pointer can return at a time `return char_array1`. 

Also there are some circuits which only uses one input, that is why I make two separate `read_inputs_A` and `read_inputs_b` functions. 

PS!. WE cannot return whole array, instead we can return pointer to that array, and then increment pointer to see all elements of the array. In case of
Vector, Yes we can return Whole Vector. 

### c)

c) in main.cpp, you have constants at the beginning: can you make them to a separate file. refer https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header
(donot use namespaces for now)

### d)

read_inputs_A (or B): You are returning static char. There should be better way of doing this I think. Is it correct to create static char inside a method and return it?

### e)

In ReadData::get_data: line 20 I think you should throw an exception if an error happens while opening file.

### f)

circuits::arithmetic_functions: can you throw exceptions if data_list[k].size is different from 5 or 6)
in both e and f: while throwing the exceptions, pl make sure to print the stack trace (that gives lines numbers, file/method names)

### g)

Question: In circuits.cpp: line 263: what are you doing? what does wires_vec represent (I mean each element is unsignd_vec which is 2 bytes? that is expensive memory. Can we just live with vector of bits/boolean to save memory; if so, how can you convert vector of booleans into std::string)


### h)

In circuit.cpp::display_output: line 319: Why are you maintaining 2 vectors (index1 and index2). It appears like you can have only vector because the indices you are storing are sequential. Pl suggest

### i)

Can you check negation for following value (inputA) and cross compare with the value in rapidtables.com. Some thing doesnt look right to me.

0010101101100010101010101000101010101001010110110011011110001010

### j)

let us talk about 2 things in circuit.cpp after you are done with the above (may be around your dinner time)
