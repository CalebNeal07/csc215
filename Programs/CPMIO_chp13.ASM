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
