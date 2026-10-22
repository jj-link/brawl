#pragma force_active on
extern "C" void *fn_802F37D8(unsigned int arg0, void *arg1, void *arg2) {
    void *sel;
    signed char cond;
    int count;
    int i;
    int found;
    unsigned int base;
    int off;
    int a4c = *(int *)((char *)arg1 + 0x4c);
    int b4c = *(int *)((char *)arg2 + 0x4c);
    cond = (signed char)(a4c <= b4c);
    if (cond) {
        sel = arg1;
    } else {
        sel = arg2;
    }
    i = 0;
    found = 0;
    off = 0;
    count = *(int *)((char *)sel + 0x4c);
    while (i < count) {
        base = *(unsigned int *)(*(char **)((char *)sel + 0x48) + off);
        if (base <= arg0 && arg0 < base + *(unsigned short *)((char *)sel + 0x5e)) {
            found = 1;
            break;
        }
        off += 4;
        i++;
    }
    if ((cond != 0) ^ (found != 0)) {
        return arg2;
    }
    return arg1;
}
