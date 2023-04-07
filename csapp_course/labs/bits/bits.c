/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 */

extern int printf(const char *, ...);

/* Edit the functions below.  Good luck!  */
// 2
/*
 * implication - given input x and y, which are binaryh
 * (taking  the values 0 or 1), return x -> y in propositional logic -
 * 0 for false, 1 for true
 *
 * Below is a truth table for x -> y where A is the result
 *
 * |-----------|-----|
 * |  x  |  y  |  A  |
 * |-----------|-----|
 * |  1  |  1  |  1  |
 * |-----------|-----|
 * |  1  |  0  |  0  |
 * |-----------|-----|
 * |  0  |  1  |  1  |
 * |-----------|-----|
 * |  0  |  0  |  1  |
 * |-----------|-----|
 *
 *
 *   Example: implication(1L,1L) = 1L
 *            implication(1L,0L) = 0L
 *   Rating: 2
 */
long implication(long x, long y) {
    return !(x & (x ^ y));
}
/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96L) = 0x20L
 *   Rating: 2
 */
long leastBitPos(long x) {
    if (x == 0)
        return 0;

    long mask = 0x1L;
    while ((x & mask) == 0L)
        mask <<= 1;
    return mask;
}
/*
 * di5stinctNegation - returns 1 if x != -x.
 *     and 0 otherwise
 *   Rating: 2
 */
long distinctNegation(long x) {
    return !(x == ~x + 1); // -x = ~x + 1;
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 64
 *   Examples: fitsBits(5,3) = 0L, fitsBits(-4,3) = 1L
 *   Rating: 2
 */
long fitsBits(long x, long n) {
    long shift = 1L << (n - 1);
    if (x >= -shift && x <= (shift - 1))
        return 1;
    return 0;
}
// 3
/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0, 5 = 4 + 1,
 *  avoiding errors due to overflow
 *  Examples:
 *    trueFiveEighths(11L) = 6L
 *    trueFiveEighths(-9L) = -5L
 *    trueFiveEighths(0x3000000000000000L) = 0x1E00000000000000L (no overflow)
 *  Rating: 4
 */
long trueFiveEighths(long x) {
    return x / 8 * 5 + ((x % 8) * 5 / 8);
}
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x8000000000000000L,0x8000000000000000L) = 0L, overflow
 *            addOK(0x8000000000000000L,0x7000000000000000L) = 1L, otherwise
 *   Rating: 3
 */
long addOK(long x, long y) {
    if ((x >= 0L && y <= 0L) || (x <= 0L && y >= 0L))
        return 1L;
    else if (x >= 0L && y >= 0L)
        return x <= ~(1L << 63) - y;
    else
        return x >= (1L << 63) - y;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5L) = 0L, isPower2(8L) = 1L, isPower2(0) = 0L
 *   Note that no negative number is a power of 2.
 *   Rating: 3
 */
long isPower2(long x) {
    if (x <= 0)
        return 0L;
    long mask = 0x1L;
    int cnt = 0;
    for (int i = 0; i < 64; ++i) {
        if (x & mask)
            ++cnt;
        x >>= 1;
    }
    return cnt == 1;
}
/*
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 63
 *   Examples:
 *      rotateLeft(0x8765432187654321L,4L) = 0x7654321876543218L
 *   Rating: 3
 */
long rotateLeft(long x, long n) {
    return (x << n) | ((x >> (64 - n)) & ((1L << n) - 1));
}
// 4
/*
 * isPalindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPalindrome(0x6F0F0123c480F0F6L) = 1L
 *   Rating: 4
 */
long isPalindrome(long x) {
    unsigned long l = 0x8000000000000000L, r = 0x1L;
    for (int i = 0; i < 32; ++i) {
        if ((x & l) != ((x & r) << (63 - 2 * i))) {
            return 0L;
        }
        l >>= 1, r <<= 1;
    }
    return 1L;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5L) = 0L, bitParity(7L) = 1L
 *   Rating: 4
 */
long bitParity(long x) {
    int cnt = 0;
    long mask = 0x1L;
    for (int i = 0; i < 64; ++i) {
        if ((mask & x) == 0L) {
            ++cnt;
        }
        mask <<= 1;
    }
    return cnt % 2;
}
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Rating: 4
 * if x & 0x8000000000000000 == 0L return x; otherwise, ~x + 1;
 */
long absVal(long x) {
    if (x & 0x8000000000000000L)
        return ~x + 1;
    return x;
}
