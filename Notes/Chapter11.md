# Chapter 11
This chapter is the first proper utilization of the CP/M system. 
The exercise presented in this chapter will show us how to write an 
ASM program that excutes in the TPA by itself.

### A Couple Things to Now
1. There are two control keys used in this exerciese Ctrl-Z & Ctrl-I.
2. Assembly programs should be typed in upper case so caps lock is your friend

## Writing the Program
1. Start by entering by typing `A:ED TEST.ASM`
2. When in command mode `-V` removes line numbers and `I` puts you into insert mode
3. Enter insert mode
4. Type the following program using the Tab/Ctrl-I keys between columns
```
BDOS    EQU     5
WCONF   EQU     2
        ORG     100H
        MVI     C,WCONF
        MVI     E,'$'
        CALL    BDOS
        JMP     0
        END 
```

> [!IMPORTANT]
> If you make a mistake while writing a program you can navigate to the line you want to edit, and use `S` command to substitute in the correction.

ED will also write a `FOO.BAK` file when editing an existing file that can be used to restore a file.

## Assembling the Program

Running `ASM TEST` will assemble the program, presuming there are no errors with the code.
The ASM command can also be modified by three options after the file name. 
`ASM TEST.123`
1. The drive to read the source file from
2. The drive to write the `.HEX` file to
3. The drive to write the `.PRN` file to 

## Running the Program

The assembler outputs a `.HEX` file and a `.PRN` file. 
The `.HEX` file is the primary output and contains the executable and some additional details to allow the file to be transmitted between computers.
`LOAD.COM`'s job is to convert `.HEX` files into `.COM` executables.

In our case we want to run `LOAD TEST` to generate a `TEST.COM` file that will execute the code we wrote.


