#pragma force_active on
typedef unsigned short u16;
typedef unsigned long u32;

extern u16* __peReg;

typedef struct {
    u16 x : 11;
    u16 c : 1;
    u16 b : 3;
    u16 a : 1;
} Bits;

void fn_801F0BEC(u32 a, u32 b, u32 c) {
    union {
        u16 v;
        Bits f;
    } u;
    u.v = 0;
    u.f.a = a;
    u.f.b = b;
    u.f.c = c;
    *__peReg = u.v;
}
