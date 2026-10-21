#pragma force_active on

extern "C" {
extern unsigned char lbl_80455458[];

int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int c, int, int) {
    const unsigned char* p = lbl_80455458;
    int idx;
    int i;

    for (i = 0, idx = 0; i < 5; i++) {
        if (c == p[0] || c == p[1]) goto done;
        idx++;
        if (c == p[0x10] || c == p[0x11]) goto done;
        idx++;
        if (c == p[0x20] || c == p[0x21]) goto done;
        idx++;
        if (c == p[0x30] || c == p[0x31]) goto done;
        idx++;
        if (c == p[0x40] || c == p[0x41]) goto done;
        idx++;
        if (c == p[0x50] || c == p[0x51]) goto done;
        idx++;
        if (c == p[0x60] || c == p[0x61]) goto done;
        idx++;
        if (c == p[0x70] || c == p[0x71]) goto done;
        p += 0x80;
        idx++;
    }

done:
    return idx;
}
}
