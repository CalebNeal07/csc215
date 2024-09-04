# 16 Bit Addition

| Instruction | Binary Representation      |
| ----------- | -------------------------- |
| LDA 0x30    | 00111010 00110000 00000000 |
| MOV B<-A    | 01000111                   |
| LDA 0x32    | 00111010 00110010 00000000 |
| ADD B       | 10000000                   |
| STA 0x40    | 00110010 01000000 00000000 |
| LDA 0x31    | 00111010 00110001 00000000 |
| MOV B<-A    | 01000111                   |
| LDA 0x33    | 00111010 00110011 00000000 |
| ADC B       | 10001000                   |
| STA 0x41    | 00110010 01000001 00000000 |
| JMP $       | 11000011 00010110 00000000 |

This program is extremely similar to what we did last class with one small difference,
we're using 16 bit numbers. The
