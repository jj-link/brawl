#include <types.h>
#pragma force_active on
extern "C" {
extern int lbl_8059FFC0;
extern float lbl_805A1400, lbl_805A1434, lbl_805A1444, lbl_805A1448, lbl_805A144C, lbl_805A1450, lbl_805A145C;
struct Blk12 { int w[12]; };
struct Pair { int w[2]; };
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_80019FEC();
void fn_801ECE60(void*, float, float, float, float);
void fn_801ECF4C(void*, float, float, float, float, float, float);
void fn_8003F898(void*, void*);
void fn_8003E46C(void*, void*, void*);
void fn_8001A194(int idx, const float* src, float* dst) {
    Blk12 cp;
    float sp78[16];
    float sp38[16];
    float v[4];
    float projected[4];
    float t[4];
    register f32 a,b,c,d,e,f;
    if (lbl_8059FFC0 == 0 && lbl_8059FFC0 == 0 && __nw__FUlQ25Heaps8HeapType(0x740, 1) != 0) fn_80019FEC();
    char* obj = (char*)lbl_8059FFC0 + idx * 0x134;
    if (*(int*)(obj + 0x100) == 1)
        fn_801ECE60(sp38, lbl_805A1434 * *(float*)(obj + 0xd8), *(float*)(obj + 0xe4), *(float*)(obj + 0xdc), *(float*)(obj + 0xe0));
    else
        fn_801ECF4C(sp38, lbl_805A1444, lbl_805A1448, lbl_805A144C, lbl_805A1450, *(float*)(obj + 0xdc), *(float*)(obj + 0xe0));
    fn_8003F898(sp38, sp78);
    ((Pair*)&cp)[0] = ((Pair*)obj)[0];
    float z = src[2], y = src[1], x = src[0];
    ((Pair*)&cp)[1] = ((Pair*)obj)[1];
    ((Pair*)&cp)[2] = ((Pair*)obj)[2];
    ((Pair*)&cp)[3] = ((Pair*)obj)[3];
    ((Pair*)&cp)[4] = ((Pair*)obj)[4];
    ((Pair*)&cp)[5] = ((Pair*)obj)[5];
    v[0] = x; v[1] = y; v[2] = z; v[3] = lbl_805A1400;
    fn_8003E46C(&cp, v, v);
    register float* m = sp78;
    register float* in = v;
    register float* out = projected;
    register float* tp = t;
    asm { psq_l a, 8(m), 0, 0 }
    asm { psq_l e, 0(in), 0, 0 }
    asm { psq_l b, 0(m), 0, 0 }
    asm { ps_muls0 c, a, e }
    asm { psq_l a, 24(m), 0, 0 }
    asm { ps_muls0 d, b, e }
    asm { psq_l b, 16(m), 0, 0 }
    asm { psq_l f, 8(in), 1, 0 }
    asm { ps_madds1 c, a, e, c }
    asm { psq_l a, 40(m), 0, 0 }
    asm { ps_madds1 d, b, e, d }
    asm { psq_l b, 32(m), 0, 0 }
    asm { ps_madds0 c, a, f, c }
    asm { psq_l a, 56(m), 0, 0 }
    asm { ps_madds0 d, b, f, d }
    asm { psq_l b, 48(m), 0, 0 }
    asm { ps_add c, c, a }
    asm { ps_add d, d, b }
    float one = lbl_805A1400;
    float sy;
    float sx = lbl_805A1450;
    sy = lbl_805A145C;
    asm { psq_st c, 8(out), 0, 0 }
    asm { psq_st d, 0(out), 0, 0 }
    f = projected[3];
    f = one / f;
    asm { ps_muls0 d, d, f }
    asm { ps_muls0 f, c, f }
    asm { psq_st d, 0(tp), 0, 0 }
    d = t[0];
    d = d + one;
    float rx = d * sx;
    asm { psq_st f, 8(tp), 0, 0 }
    c = t[1];
    c = one - c;
    float ry = c * sy;
    float tz = t[2];
    float tw = t[3];
    dst[2] = tz;
    dst[0] = rx;
    dst[1] = ry;
    projected[2] = tz;
    projected[3] = tw;
    projected[0] = rx;
    projected[1] = ry;
}
}
