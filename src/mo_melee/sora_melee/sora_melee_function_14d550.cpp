#pragma force_active on
extern "C" int fn_27_14D550(int c) {
    if (c == 0x2a) {
        goto yes;
    }
    if (c == 0x2b) {
        goto yes;
    }
    if (c == 0x2d) {
        goto yes;
    }
    if (c == 0x2e) {
        goto yes;
    }
    if ((unsigned int)(c - 0x30) > 1) {
        goto no;
    }
yes:
    return 1;
no:
    return 0;
}
