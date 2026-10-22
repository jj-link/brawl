#pragma force_active on
#include <types.h>
#include <math.h>

extern "C" u32 fn_80111CB0(void*, void*);
extern "C" u32 fn_80134534(void*, u32);
extern "C" void getSegment__11grCollisionFP11clSegment2DP15grCollisionLine(void*, void*, void*);
extern "C" float rsqrtf__Ff(float);
extern float lbl_27_rodata_3C0[];

struct Vec2 {
    float x;
    float y;
};

struct Seg {
    Vec2 a;
    Vec2 b;
};

struct Ret {
    u8 pad[4];
    void* id;
};

class Holder {
public:
    virtual void f0();
    virtual Ret* get(u32);
};

struct Self {
    u8 pad[0x28];
    Holder* h;
};

struct QBits {
    u8 hi : 1;
    u8 rest : 7;
};

struct Local {
    u32 v;
    u8 pad0[4];
    Vec2 d;
    Seg seg;
    void* line;
    u32 x;
    void* grc;
    u8 b34;
    QBits q;
};

extern "C" float fn_27_283A0(Self* self, u32 flags, u32 arg2) {
    Local l;
    float* k = lbl_27_rodata_3C0;
    u32 mode;
    Ret* r;
    float len2;

    if (flags & 1) {
        mode = 0;
    } else if (flags & 8) {
        mode = 3;
    } else if (flags & 2) {
        mode = 1;
    } else {
        mode = 0;
        if (flags & 4) {
            mode = 2;
        }
    }

    r = self->h->get(arg2);
    l.v = fn_80134534(r->id, mode);
    l.line = 0;
    l.x = 0;
    l.grc = 0;
    l.b34 = 0;
    l.q.hi = 0;

    if (fn_80111CB0(&l.v, &l.line) == 0) {
        return k[0];
    }

    getSegment__11grCollisionFP11clSegment2DP15grCollisionLine(l.grc, &l.seg, l.line);

    l.d.x = l.seg.a.x - l.seg.b.x;
    l.d.y = l.seg.a.y - l.seg.b.y;
    len2 = l.d.x * l.d.x + l.d.y * l.d.y;

    if ((float)fabs(len2) <= k[10]) {
        return k[1];
    }
    return len2 * rsqrtf__Ff(len2);
}
