#include <types.h>
#pragma force_active on

extern "C" {
void fn_80040518(void*, void*, u32, u32, u32);
void fn_801380BC(void*, void*);
extern f32 lbl_805A2A80;

struct Vec2f {
    union {
        struct { f32 x, y; };
        u32 words[2];
    };
};
struct Segment {
    Vec2f a, b;
};
struct Obj {
    u8 pad0[0x14];
    f32 val;
    u8 pad18[0x8];
    Vec2f res;
    u8 flag;
    u8 pad29[3];
    u32 w[4];
};

u8 fn_8013848C(void* arg0, void* arg1, const u8* arg2) {
    Obj* o = (Obj*)arg0;
    u32* a1 = (u32*)arg1;
    Segment* seg = (Segment*)arg1;
    u32 w0, w1, w2, w3;
    Vec2f tmp2, tmp1, prod, sum;
    f32 val;
    u8 flags;

    o->flag = 0;
    flags = arg2[0x2c];

    if (((flags >> 7) & 1) && (flags & 1) && ((flags >> 2) & 1)) {
        w0 = a1[0];
        w1 = a1[1];
        w2 = a1[2];
        w3 = a1[3];
        val = lbl_805A2A80;
        o->w[0] = w0;
        o->w[1] = w1;
        o->w[2] = w2;
        o->w[3] = w3;
        o->val = val;
        fn_80040518(arg1, arg0, w2, w1, w0);
        fn_801380BC(arg0, (void*)arg2);
        if (o->flag == 1) {
            f32 scale = o->val;
            prod.x = seg->b.x * scale;
            prod.y = seg->b.y * scale;
            tmp1.words[0] = prod.words[0];
            tmp1.words[1] = prod.words[1];
            sum.x = tmp1.x + seg->a.x;
            sum.y = tmp1.y + seg->a.y;
            tmp2.words[0] = sum.words[0];
            tmp2.words[1] = sum.words[1];
            o->res.x = tmp2.x;
            o->res.y = tmp2.y;
        }
    }

    return o->flag;
}
}
