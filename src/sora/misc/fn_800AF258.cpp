#pragma force_active on
extern "C" {
extern unsigned char lbl_80455458[];

int exchangeMuCharKindToMuSelchkind__6muMenuFiii(int c, int, int) {
    const unsigned char* p = lbl_80455458;
    int idx;
    int i;
    for (i = 0, idx = 0; i < 4; i++) {
        if (c == p[2]) goto done;
        idx++;
        if (c == p[0x12]) goto done;
        idx++;
        if (c == p[0x22]) goto done;
        idx++;
        if (c == p[0x32]) goto done;
        idx++;
        if (c == p[0x42]) goto done;
        idx++;
        if (c == p[0x52]) goto done;
        idx++;
        if (c == p[0x62]) goto done;
        idx++;
        if (c == p[0x72]) goto done;
        idx++;
        if (c == p[0x82]) goto done;
        idx++;
        if (c == p[0x92]) goto done;
        p += 0xa0;
        idx++;
    }
done:
    return idx;
}
}