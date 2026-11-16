#pragma force_active on

typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern "C" {
extern const f32 lbl_805A3240;
f32 fn_80193080(void*, f32);
u32 fn_801931AC(void*, f32);

struct Anim {
    char _0[4];
    s32 off4;
    char _8[0xC];
    u32 flags;
    u32 unk18;
    union { s32 off; f32 val; } u1c;
    union { s32 off; f32 val; } u20;
    s32 off24;
    char _28[8];
    u16 unk30;
};

struct Out {
    s32 unk0;
    f32 x;
    f32 y;
    u32 unkC;
};

void fn_801963D0(Anim* const* arg0, Out* out, f32 farg0) {
    Out* o = out;
    Anim* p = *arg0;
    u32 flags = p->flags;
    char* sub = p->off4 ? (char*)p + p->off4 : 0;
    f32 val;
    if (farg0 <= lbl_805A3240) {
        val = lbl_805A3240;
    } else {
        u32 t = *(u16*)(sub + 0x30);
        if ((f32)t <= farg0) {
            val = (f32)t;
        } else {
            val = farg0;
        }
    }
    o->unk0 = p->unk18;
    u32 sel1 = (flags >> 30) & 1;
    u32 sel31 = flags >> 31;
    f32 fx;
    f32 fy;
    u32 uc;
    if (flags & 0x20000000) {
        fx = p->u1c.val;
    } else {
        fx = fn_80193080((char*)p + p->u1c.off + 0x1c, farg0);
    }
    o->x = fx;
    if (sel1) {
        fy = p->u20.val;
    } else {
        fy = fn_80193080((char*)p + p->u20.off + 0x20, farg0);
    }
    o->y = fy;
    if (sel31) {
        uc = p->off24;
    } else {
        uc = fn_801931AC((char*)p + p->off24 + 0x24, val);
    }
    o->unkC = uc;
}
}
