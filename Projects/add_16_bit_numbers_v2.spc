# Start by loading 2 16-bit integers stored in addresses 0x30 and 0x31, and
# 0x40 and 0x41 into registers B and C, H and L
3A # LDA - load most significant byte of first addend to accumulator
31
00
47 # MOV (A->B) - move to register B
3A # LDA - load least significant byte of first addend to accumulator
30
00
4F # MOV (A->C) - move to register C
2A # LHDL - load both bytes of second addend to H and L registers
40
00
09 # DAD BC - add register pair BC to pair HL and store result in HL
22 # SHLD
50
00
76 # Halt
===
31:01
30:F5
41:10 # Reversed compared to previous example
40:0D
