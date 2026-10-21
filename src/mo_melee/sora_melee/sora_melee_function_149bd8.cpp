#pragma force_active on
extern const int lbl_27_rodata_14D8[][4];

extern "C" int fn_27_149BD8(int idx, int *out) {
    struct Entry { int v[4]; };
    Entry e = *(const Entry *)lbl_27_rodata_14D8[idx];
    int n = 0;
    if (e.v[0] != -1) {
        out[(unsigned char)n] = e.v[0];
        n++;
    }
    if (e.v[1] != -1) {
        out[(unsigned char)n] = e.v[1];
        n++;
    }
    if (e.v[2] != -1) {
        out[(unsigned char)n] = e.v[2];
        n++;
    }
    if (e.v[3] != -1) {
        out[(unsigned char)n] = e.v[3];
        n++;
    }
    return n;
}
