#pragma force_active on
extern "C" int fn_801B91F4(int r3, int r4, int r5) {
    if (r3) {
        r3 += 0x80000000;
    }
    int r0 = 0;
    switch (r5) {
    case 0: {
        int tmp = r4 - r3 * 2;
        r0 = (tmp & 0xF) + (((unsigned)tmp >> 4) * 14) - 2;
        break;
    }
    case 25:
        r0 = r4 - r3;
        break;
    case 10:
        r0 = r4 - ((unsigned)r3 >> 1);
        break;
    }
    return r0;
}