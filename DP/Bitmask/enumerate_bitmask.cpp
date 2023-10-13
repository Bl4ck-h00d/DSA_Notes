/**
 * IMPORTANT
 *
 * Enumerating all submasks of a given mask
 * Given a bitmask m, you want to efficiently iterate through all of its submasks, that is, masks s in which only bits that were included in mask m are set.
 *
 */

for (int s = m; s; s = (s - 1) & m)
... you can use s...

    /*
        Count setbits-

        int k=__builtin_popcount(s)
    */

    // https: // leetcode.com/problems/parallel-courses-ii/