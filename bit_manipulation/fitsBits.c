int fitsBits(int x, int n) {
    int shift = 32 + (~n + 1);
    return !(((x << shift) >> shift) ^ x);
}
