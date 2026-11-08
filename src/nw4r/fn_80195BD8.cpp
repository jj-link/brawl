#pragma force_active on
struct F4 { float x, y, z, w; };
struct Mat3x4 { F4 row0; F4 row1; F4 row2; };
extern float lbl_805A31F0;
extern const float lbl_805A31F4;
extern "C" void fn_801EC184(void*, void*);
extern "C" void fn_80195BD8(int* flags, const Mat3x4* src) {
    int r5 = 0;
    int r6;
    int tmp = 0;
    if (lbl_805A31F4 == src->row0.x && lbl_805A31F0 == src->row0.y &&
        lbl_805A31F0 == src->row0.z && lbl_805A31F0 == src->row1.x &&
        lbl_805A31F4 == src->row1.y && lbl_805A31F0 == src->row1.z &&
        lbl_805A31F0 == src->row2.x && lbl_805A31F0 == src->row2.y) tmp = 1;
    if (tmp != 0 && lbl_805A31F4 == src->row2.z) r5 = 1;
    r6 = 0;
    tmp = 0;
    if (lbl_805A31F0 == src->row0.w && lbl_805A31F0 == src->row1.w) tmp = 1;
    if (tmp != 0 && lbl_805A31F0 == src->row2.w) r6 = 1;
    if (r5 != 0) {
        if (r6 != 0) {
            int f = *flags | 0x64;
            *flags = f;
            if (f & 8) *flags = f | 2;
        } else *flags = (*flags | 0x20) & ~0x46;
    } else if (r6 != 0) *flags = (*flags | 0x40) & ~0x26;
    else *flags &= ~0x66;
    fn_801EC184((void*)src, (char*)flags + 0x1C);
    *flags &= 0x7FFFFFFF;
}