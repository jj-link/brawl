#pragma force_active on

extern "C" {
extern const unsigned char lbl_80407BD0[];
extern const unsigned char lbl_80407A40[];

int exchangeGmCharacterKindToMuCharKind__6muMenuFiii(int c, int, int) {
    const unsigned char* p = lbl_80407BD0;
    int idx;
    int i;

    for (i = 0, idx = 0; i < 7; i++) {
        if (c == p[0])
            return (lbl_80407BD0 + idx * 2)[1];
        p += 2;
        idx++;
    }

    p = lbl_80407A40;
    for (i = 0, idx = 0; i < 4; i++) {
        if (c == p[0]) goto done;
        idx++;
        if (c == p[3]) goto done;
        idx++;
        if (c == p[6]) goto done;
        idx++;
        if (c == p[9]) goto done;
        idx++;
        if (c == p[12]) goto done;
        idx++;
        if (c == p[15]) goto done;
        idx++;
        if (c == p[18]) goto done;
        idx++;
        if (c == p[21]) goto done;
        idx++;
        if (c == p[24]) goto done;
        p += 27;
        idx++;
    }

done:
    return idx;
}
}
