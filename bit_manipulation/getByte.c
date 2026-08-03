int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}
