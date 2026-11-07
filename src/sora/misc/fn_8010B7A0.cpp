#include <types.h>
#pragma force_active on
extern const float lbl_805A2870;
struct Obj {
    u32 a[85];
    u32 b[7];
    u8 pad[0xcc];
    u32 c;
    u32 d[50];
    u32 e;
    u32 f;
    u8 g[50];
    u8 pad2[6];
    float h, i;
    u32 pad3;
    float j, k, l;
    u8 pad4;
    u8 m, n;
};
extern "C" void fn_8010B7A0(Obj* o) {
    u32* p = o->a;
    u32 idx = 0;
    for (int i = 0; i < 2; ++i) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        p[8] = 0;
        p[9] = 0;
        p[10] = 0;
        p[11] = 0;
        p[12] = 0;
        p[13] = 0;
        p[14] = 0;
        p[15] = 0;
        p[16] = 0;
        p[17] = 0;
        p[18] = 0;
        p[19] = 0;
        p[20] = 0;
        p[21] = 0;
        p[22] = 0;
        p[23] = 0;
        p[24] = 0;
        p[25] = 0;
        p[26] = 0;
        p[27] = 0;
        p[28] = 0;
        p[29] = 0;
        p[30] = 0;
        p[31] = 0;
        p[32] = 0;
        p[33] = 0;
        p[34] = 0;
        p[35] = 0;
        p[36] = 0;
        p[37] = 0;
        p[38] = 0;
        p[39] = 0;
        idx += 40;
        p += 40;
    }
    u32* tail = &o->a[idx];
    tail[0] = 0;
    tail[1] = 0;
    tail[2] = 0;
    tail[3] = 0;
    tail[4] = 0;
    o->b[0] = 0;
    o->b[1] = 0;
    o->b[2] = 0;
    o->b[3] = 0;
    o->b[4] = 0;
    o->b[5] = 0;
    o->b[6] = 0;
    o->c = 0;
    for (int i = 0; i < 50; ++i) {
        o->d[i] = 0;
        o->g[i] = 0;
    }
    o->h = lbl_805A2870;
    o->i = lbl_805A2870;
    o->j = lbl_805A2870;
    o->k = lbl_805A2870;
    o->l = lbl_805A2870;
    o->f = 13;
    o->e = 0;
    o->m = 1;
    o->n = 1;
}