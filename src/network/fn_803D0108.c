#pragma force_active on
#pragma optimization_level 1
int fn_803D4808(int arg0);

int fn_803D0108(int arg0, unsigned int arg1) {
    int count;
    unsigned int one;
    int sh;
    int tmp;
    int base;
    int y;

    one = 1;
    count = 0;
    if (arg1 & (one << count)) {
        count = 1;
    }
    sh = 1;
    if (arg1 & (one << sh)) {
        count += 1;
    }
    sh = 2;
    if (arg1 & (one << sh)) {
        count += 1;
    }
    sh = 3;
    if (arg1 & (one << sh)) {
        count += 1;
    }
    sh = 4;
    if (arg1 & (one << sh)) {
        count += 1;
    }
    sh = 5;
    if (arg1 & (one << sh)) {
        count += 1;
    }
    sh = 6;
    if (arg1 & (one << sh)) {
        count += 1;
    }
    tmp = fn_803D4808(arg0);
    tmp = tmp * count;
    base = count << 5;
    base = (base + 0x1F) & ~0x1F;
    y = tmp + 0x1F;
    tmp = base + 0x10000;
    tmp = tmp + (y & ~0x1F);
    return tmp - 0x7DA0;
}
