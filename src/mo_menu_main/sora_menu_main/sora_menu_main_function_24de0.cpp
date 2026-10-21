#pragma force_active on
extern "C" {
extern const unsigned char lbl_2_rodata_D78[];

int fn_2_24DE0(int c) {
    const unsigned char* p = lbl_2_rodata_D78;
    int idx;
    int i;
    for (i = 0, idx = 0; i < 5; i++) {
        if (c == p[0]) goto done;
        idx++;
        if (c == p[1]) goto done;
        idx++;
        if (c == p[2]) goto done;
        idx++;
        if (c == p[3]) goto done;
        idx++;
        if (c == p[4]) goto done;
        idx++;
        if (c == p[5]) goto done;
        idx++;
        if (c == p[6]) goto done;
        p += 7;
        idx++;
    }
done:
    return idx;
}
}
