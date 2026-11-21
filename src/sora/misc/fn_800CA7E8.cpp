#pragma force_active on
#pragma optimization_level 0
#pragma opt_dead_code on

#include <types.h>

struct Blk {
    u8 b[13];
    u8 pad;
    u16 h[9];
    u8 c[2];
    u16 d;
};

struct Obj {
    u8 pad0[0xFC9];
    u8 flag;
    u8 pad1[0x36];
    Blk d0;
    Blk d1;
};

extern "C" void fn_800CA7E8(Obj* dst, const Blk* src, u16 t0, unsigned int t1) {

    dst->d0.b[0] = src->b[0];
    dst->d0.b[1] = src->b[1];
    dst->d0.b[2] = src->b[2];
    dst->d0.b[3] = src->b[3];
    dst->d0.b[4] = src->b[4];
    dst->d0.b[5] = src->b[5];
    dst->d0.b[6] = src->b[6];
    dst->d0.b[7] = src->b[7];
    dst->d0.b[8] = src->b[8];
    dst->d0.b[9] = src->b[9];
    dst->d0.b[10] = src->b[10];
    dst->d0.b[11] = src->b[11];
    dst->d0.b[12] = src->b[12];
    t0 = src->h[0];
    t1 = src->h[1];
    dst->d0.h[0] = t0;
    dst->d0.h[1] = t1;
    t0 = src->h[2];
    t1 = src->h[3];
    dst->d0.h[2] = t0;
    dst->d0.h[3] = t1;
    t0 = src->h[4];
    t1 = src->h[5];
    dst->d0.h[4] = t0;
    dst->d0.h[5] = t1;
    t0 = src->h[6];
    t1 = src->h[7];
    dst->d0.h[6] = t0;
    dst->d0.h[7] = t1;
    dst->d0.h[8] = src->h[8];
    dst->d0.c[0] = src->c[0];
    dst->d0.c[1] = src->c[1];
    dst->d0.d = src->d;

    dst->d1.b[0] = src->b[0];
    dst->d1.b[1] = src->b[1];
    dst->d1.b[2] = src->b[2];
    dst->d1.b[3] = src->b[3];
    dst->d1.b[4] = src->b[4];
    dst->d1.b[5] = src->b[5];
    dst->d1.b[6] = src->b[6];
    dst->d1.b[7] = src->b[7];
    dst->d1.b[8] = src->b[8];
    dst->d1.b[9] = src->b[9];
    dst->d1.b[10] = src->b[10];
    dst->d1.b[11] = src->b[11];
    dst->d1.b[12] = src->b[12];
    t0 = src->h[0];
    t1 = src->h[1];
    dst->d1.h[0] = t0;
    dst->d1.h[1] = t1;
    t0 = src->h[2];
    t1 = src->h[3];
    dst->d1.h[2] = t0;
    dst->d1.h[3] = t1;
    t0 = src->h[4];
    t1 = src->h[5];
    dst->d1.h[4] = t0;
    dst->d1.h[5] = t1;
    t0 = src->h[6];
    t1 = src->h[7];
    dst->d1.h[6] = t0;
    dst->d1.h[7] = t1;
    dst->d1.h[8] = src->h[8];
    dst->d1.c[0] = src->c[0];
    dst->d1.c[1] = src->c[1];
    dst->d1.d = src->d;

    dst->flag |= 0x40;
}
