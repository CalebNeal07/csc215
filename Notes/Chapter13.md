# Buffered Input/Output

The author advises saving backups of old code on a secondary drive using the `PIP` command. Additionally, when editing existing files it is often preferable to enter new text into `.LIB` files which `ED` will recognize these and insert them into the editor buffer at the editor pointer's current position when the user uses the read, `R`, command.

## Using `.LIB` files
Key in the files `CH13.LIB` & `TESTC13.LIB`. Once these files have been entered, open `CPMIO.ASM` navigate to the current `START1` label and replace it with the new one in `TESTC13.LIB` by typing `RTESTC13`. Insert `CH13.LIB` anywhere later in the program that doesn't interrupt another subroutine.

> CPMIO.ASM
```
; CP/M I/O SUBROUTINES  10 NOV 24

; ASCII CHARACTERS
CR      EQU     0DH
LF      EQU     0AH
CTRLZ   EQU     1AH

; CP/M BDOS FUNCTIONS
RCONF   EQU     1
WCONF   EQU     2

; CP/M ADDRESSES
RBOOT   EQU     0
BDOS    EQU     5
TPA     EQU     100H

        ORG     TPA

START:  LXI     SP,STAK
START1: CALL    CCRLF
        LXI     H,SINON
        CALL    COMSG
START2: CALL    CIMSG
        CALL    CCRLF
        LXI     H,INBUF+2
        CALL    COMSG
        CALL    CCRLF
        JMP     START2

SINON:  DB      'SIGN-ON MESSAGE',CR,LF,0
; CONSOLE CHARACTER INTO REGISTER A MASKED TO 7 BITS
CI:     PUSH    B
        PUSH    D
        PUSH    H
        MVI     C,RCONF
        CALL    BDOS
        ANI     7FH
        POP     H
        POP     D
        POP     B
        RET

; CHARACTER IN REGISTER A OUTPUT TO CONSOLE
CO:     PUSH    B
        PUSH    D
        PUSH    H
        MVI     C,WCONF
        MOV     E,A
        CALL    BDOS
        POP     H
        POP     D
        POP     B
        RET

; CARRIAGE RETURN, LINE FEED TO CONSOLE
CCRLF:  MVI     A,CR
        CALL    CO
        MVI     A,LF
        JMP     CO

; MESSAGE POINTED TO BY HL OUT OF CONSOLE
COMSG:  MOV     A,M
        ORA     A
        RZ
        CALL    CO
        INX     H
        JMP     COMSG

; INPUT CONSOLE MESSAGE INTO BUFFER
CIMSG:  PUSH    B
        PUSH    D
        PUSH    H
        LXI     H,INBUF+1
        MVI     M,0
        DCX     H
        MVI     M,80
        XCHG
        MVI     C,RBUFF
        CALL    BDOS
        LXI     H,INBUF+1
        MOV     E,M
        MVI     D,0
        DAD     D
        INX     H
        MVI     M,0
        POP     H
        POP     D
        POP     B
        RET

INBUF:  DS      83; SET UP A STACK SPACE
        DS      64
STAK:   DB      0

        END
```

This new program is an upgrade of the one we made in chapter 12. The new features to note are:
  1. `CCRLF` uses the `CO` routine we made to insert a carriage return and make the program answer on a new line.
  2. `COMSG` is like `CO` but displays a full message instead of just a single character. It does this by leveraging the `M` register and it returns when it catches a zero byte.
  3. `CIMSG` Writes a line message with `INBUF`

## Debugging

`DDT` can be used to debug user programs. It functions by loading into the TPA and then moving itself higher up and modifies BDOS to so that it catches any I/O accesses that your program tries to make. Within `DDT` we can use `G` to go to and execute instructions at specific memory addresses and `X$` to examine the register specified at "$", e.x. `XA` examines the contents of the `A` register.