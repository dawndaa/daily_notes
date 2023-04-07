// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

@24577
D = A
@0
M = D   // set R0 24577(max address)
@SCREEN
D = A
@1
M = D  // set R1  current address

(LOOP)

@KBD
D = M
@ELSE
D;JEQ  // if (R[0x6000] == 0) goto ELSE

//fill begin
@1
D = M
@0
D = D - M
@LOOP
D;JGT   // if (R1 - R0 > 0) goto LOOP (.i.e full)

@1
D = M
A = M
M = -1   // -1 = 全1
@1 
M = M + 1  // 地址加一

@LOOP
0;JMP
//fill end

(ELSE)
// clear begin
@SCREEN
D = A
@1
D = D - M
@LOOP
D;JGT

@1
D = M
A = M
M = 0
@1
M = M - 1  // 地址减一

@LOOP
0;JMP
// clear end