#pragma force_active on

extern "C" int fn_801B9260(unsigned int x, int kind) {
    int r = 0;
    switch (kind) {
    case 0:
        r = (x >> 3) * 14;
        x = x & 7;
        if (x != 0) {
            r += (x - 1) * 2;
        }
        break;
    case 25:
        r = x;
        break;
    case 10:
        r = x >> 1;
        break;
    }
    return r;
}
