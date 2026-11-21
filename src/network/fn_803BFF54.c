#pragma force_active on
int fn_803BFF54(unsigned char *buf, unsigned int value) {
    unsigned int i, base, divisor, rem;
    if (buf == 0) return 10;
    i = 7;
    base = 10;
    divisor = 1;
    while (i > 1 && value != 0) {
        rem = value % base;
        if (rem) {
            value -= rem;
            rem /= divisor;
            buf[i] += (signed char)rem;
        }
        base *= 10;
        i--;
        divisor *= 10;
    }
    return 0;
}
