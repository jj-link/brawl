#pragma force_active on

extern "C" {
extern const unsigned char lbl_80406968[];

unsigned char fn_8004F324(unsigned int c) {
    const unsigned char* p = lbl_80406968;
    int idx;
    int i;

    for (i = 0, idx = 0; i < 14; i++) {
        if (c == p[0])
            return (lbl_80406968 + idx * 4)[1];
        p += 4;
        idx++;
    }

    return 0x3E;
}
}
