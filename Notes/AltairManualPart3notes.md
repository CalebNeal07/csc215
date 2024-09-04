# Part 3

[Book](https://ubuntourist.codeberg.page/Altair-8800/part-3.html)

Table of Contents
1. [Front Panel Switches & LEDs](#Front-Panel-Switches)
2. [Loadong a Program](#Loading-a-Program)
3. [Using the Memory](#Using-the-Memory)
4. [Addressing Memory](#Addressing-Memory)
5. [Operating Hints](#Operating-Hints)

## Front Panel Switches & LEDs

### Front Panel Switches
- `ON-OFF`: Self-explanatory
- `STOP-RUN`: When in the run position the Altair runs the program
- `SINGLE STEP`: Runs a single instruction each time its triggered
- `EXAMINE-EXAMINE NEXT`: Examine displays the state of the DATA/ADDRESS switches. When switch it displays the value at the next address
- `DEPOSIT-DEPOSIT NEXT`: Deposits data into the perviosly deisgnated address
- `RESET-CLR`: Resets the program counter to the zero memory address
- `PROTECT-UNPROTECT`: Changes if mempry contents are allowed to be altered
- `AUX`: Unused
- `DATA/ADDRESS`: Controls the memory address (15-0) and data (7-0) used in the `EXAMINE-EXAMINE NEXT` action

### Indicator LEDs
 - `ADDRESS`: Shows the memory address being examined or modified
 - `DATA`: Shows the data at `ADDRESS`
 - `INTE`: Indicates if an interupt has been triggered
 - `PROT`: Indicates if the memory is protected
 - `WAIT`: Shows if the CPU is in a wait state
 - `HLDA`: Shows if a hold has been acknowledged

### States LEDs
 - `MEMR`: The memory bus will be used for memory read data
 - `INP`: Input device address
 - `M1`: Shows if the CPU is processing th first cycle of an instrution
 - `OUT`: Memory address of output device
 - `HLTA`: Shows if a halt instruction has executed
 - `STACK`: Stack address
 - `WO`: If the operation will be a write/ouput function
 - `INT`: An interrupt request has been acknowledged

## Loading a Program
 - The computer needs percies steps to tell it exactly what to do
 - You need to deciede where in memory the program, the data, and the result will be stored
   Here's a simple program:
  |  Instruction  |  Corresponding Bit Pattern |
  |---------------|----------------------------|
  | LDA 0x80 0x00 | 00111010 10000000 00000000 |
  | MOV (A->B)    | 01000111                   |
  | LDA 0x81 0x00 | 00111010 10000001 00000000 |
  | ADD (B+A)     | 10000000                   |
  | STA 0x82 0x00 | 00110010 10000010 00000000 |
  | JMP 0x00 0x00 | 11000011 00000000 00000000 |

 - This program can be loaded by hitting reset, inputting the first byte of data, depositing it, inputting the next byte hitting deposit next and repeating the process for the rest of the program.
 - Then add the numbers you want to add to the addresses 0x80 & 0x81

## Using the Memory

## Addressing Memory

## Operating Hints
