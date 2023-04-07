@256
D = A
@0
M = D
@17
D = A
@0
A = M
M = D
@0
M = M + 1
@17
D = A
@0
A = M
M = D
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
D = M - D
@TRUE0
D;JEQ
@0
A = M
M = 0
@END0
0;JMP
(TRUE0)
@0
A = M
M = -1
(END0)
@0
M = M + 1
@17
D = A
@0
A = M
M = D
@0
M = M + 1
@16
D = A
@0
A = M
M = D
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
D = M - D
@TRUE1
D;JEQ
@0
A = M
M = 0
@END1
0;JMP
(TRUE1)
@0
A = M
M = -1
(END1)
@0
M = M + 1
@16
D = A
@0
A = M
M = D
@0
M = M + 1
@17
D = A
@0
A = M
M = D
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
D = M - D
@TRUE2
D;JEQ
@0
A = M
M = 0
@END2
0;JMP
(TRUE2)
@0
A = M
M = -1
(END2)
@0
M = M + 1
@892
D = A
@0
A = M
M = D
@0
M = M + 1
@891
D = A
@0
A = M
M = D
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
D = M - D
@TRUE3
D;JLT
@0
A = M
M = 0
@END3
0;JMP
(TRUE3)
@0
A = M
M = -1
(END3)
@0
M = M + 1
@891
D = A
@0
A = M
M = D
@0
M = M + 1
@892
D = A
@0
A = M
M = D
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
D = M - D
@TRUE4
D;JLT
@0
A = M
M = 0
@END4
0;JMP
(TRUE4)
@0
A = M
M = -1
(END4)
@0
M = M + 1
@891
D = A
@0
A = M
M = D
@0
M = M + 1
@891
D = A
@0
A = M
M = D
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
D = M - D
@TRUE5
D;JLT
@0
A = M
M = 0
@END5
0;JMP
(TRUE5)
@0
A = M
M = -1
(END5)
@0
M = M + 1
@32767
D = A
@0
A = M
M = D
@0
M = M + 1
@32766
D = A
@0
A = M
M = D
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
D = M - D
@TRUE6
D;JGT
@0
A = M
M = 0
@END6
0;JMP
(TRUE6)
@0
A = M
M = -1
(END6)
@0
M = M + 1
@32766
D = A
@0
A = M
M = D
@0
M = M + 1
@32767
D = A
@0
A = M
M = D
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
D = M - D
@TRUE7
D;JGT
@0
A = M
M = 0
@END7
0;JMP
(TRUE7)
@0
A = M
M = -1
(END7)
@0
M = M + 1
@32766
D = A
@0
A = M
M = D
@0
M = M + 1
@32766
D = A
@0
A = M
M = D
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
D = M - D
@TRUE8
D;JGT
@0
A = M
M = 0
@END8
0;JMP
(TRUE8)
@0
A = M
M = -1
(END8)
@0
M = M + 1
@57
D = A
@0
A = M
M = D
@0
M = M + 1
@31
D = A
@0
A = M
M = D
@0
M = M + 1
@53
D = A
@0
A = M
M = D
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
M = D + M
@0
M = M + 1
@112
D = A
@0
A = M
M = D
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
M = M - D
@0
M = M + 1
@0
M = M - 1
A = M
M = -M
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
M = D & M
@0
M = M + 1
@82
D = A
@0
A = M
M = D
@0
M = M + 1
@0
M = M - 1
A = M
D = M
@0
M = M - 1
A = M
M = D | M
@0
M = M + 1
@0
M = M - 1
A = M
M = !M
@0
M = M + 1
