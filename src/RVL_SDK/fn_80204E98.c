#pragma force_active on
typedef unsigned int u32;

extern int lbl_805A3970;

void fn_80204E98(u32* p, u32 a, u32 b) {
    p[0] = (u32)&lbl_805A3970;
    p[1] = a;
    p[2] = b;
    p[3] = 0;
}
