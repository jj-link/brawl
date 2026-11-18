#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

struct GXColor {
    u8 r, g, b, a;
};

struct Rect {
    f32 x0, y0, x1, y1;
};

struct Ctx {
    u8 pad0[0xB8];
    void* unkB8;
    u8 pad1[0x2A0 - 0xBC];
    s32 unk2A0;
    u8 pad2[0x558 - 0x2A4];
    f32 unk558;
    f32 unk55C;
    u32 unk560;
    u32 unk564;
    u8 pad3[0x570 - 0x568];
    GXColor c570;
    GXColor c574;
    GXColor c578;
    void* chan57C;
    GXColor c580;
    GXColor c584;
    GXColor c588;
    GXColor c58C;
    GXColor c590;
    u8 unk594;
    u8 pad4[0x598 - 0x595];
    f32 unk598;
    f32 unk59C;
    f32 unk5A0;
    f32 unk5A4;
};

extern "C" void fn_800B6A04(void* a, void* b, u32 c, u32 d);
extern "C" void fn_80191AA4(void* channels, u32 chan, GXColor color);

extern "C" const f32 lbl_805A2418;
extern "C" const f32 lbl_805A23B0;
extern "C" const f32 lbl_805A23C0;
extern "C" const f32 lbl_805A2420;
extern "C" const f32 lbl_805A241C;
extern "C" const f32 lbl_805A2424;
extern const double lbl_805A23B8;

static inline s32 isNaNBits(f32* p) {
    u32 bits = *(u32*)p;
    s32 res = 0;
    if (((bits >> 23) & 0xFF) == 0xFF && (bits & 0x7FFFFF) != 0) {
        res = 1;
    }
    return res;
}

static inline s32 checkRects(Ctx* self, Rect* p, s32 count) {
    for (s32 i = 0; i < count; i++) {
        if (self->unk5A4 < p->x1 && p->y1 < self->unk5A0 &&
            self->unk598 < p->y0 && p->x0 < self->unk59C) {
            return 1;
        }
        p++;
    }
    return 0;
}

static inline void setPair(void* chan, const GXColor* c0, const GXColor* c1, s32 alpha) {
    GXColor c;
    c.r = c0->r;
    c.g = c0->g;
    c.b = c0->b;
    c.a = (u8)((c0->a * alpha) / 255);
    fn_80191AA4(chan, 2, c);
    c.r = c1->r;
    c.g = c1->g;
    c.b = c1->b;
    c.a = (u8)((c1->a * alpha) / 255);
    fn_80191AA4(chan, 2, c);
}

extern "C" void fn_800E2B00(Ctx* self, Rect* rects, s32 count) {
    if (self->unk594 != 0) {
        fn_800B6A04(self->unkB8, &self->unk598, self->unk560, self->unk564);
        f32 t0 = self->unk5A0;
        if (isNaNBits(&t0) == 0) {
            f32 t1 = self->unk5A4;
            if (isNaNBits(&t1) == 0) {
                f32 t2 = self->unk598;
                if (isNaNBits(&t2) == 0) {
                    f32 t3 = self->unk59C;
                    if (isNaNBits(&t3) == 0) {
                        self->unk594 = 0;
                    }
                }
            }
        }
    }

    s32 n = self->unk594;
    if (n == 0) {
        n = (count <= 0);
    }

    s32 hit;
    if (n != 0) {
        hit = 0;
    } else {
        hit = checkRects(self, rects, count);
    }

    if (hit != 0) {
        self->unk558 += lbl_805A2418;
        if (self->unk558 > lbl_805A23C0) {
            self->unk558 = lbl_805A23C0;
        }
    } else {
        self->unk558 -= lbl_805A2418;
        if (self->unk558 < lbl_805A23B0) {
            self->unk558 = lbl_805A23B0;
        }
    }

    if (self->unk2A0 == 1) {
        self->unk55C += lbl_805A2418;
        if (self->unk55C > lbl_805A23C0) {
            self->unk55C = lbl_805A23C0;
        }
    } else {
        self->unk55C = lbl_805A23B0;
    }

    if (self->unk558 > lbl_805A23B0 || lbl_805A23C0 > self->unk55C) {
        f32 t = lbl_805A23C0 - self->unk558;
        s32 a1 = (s32)(lbl_805A2424 * (t * self->unk55C));

        setPair(&self->chan57C, &self->c580, &self->c584, a1);

        s32 a2 = (s32)(lbl_805A241C + lbl_805A2420 * t);
        s32 a3 = (s32)((f32)a2 * self->unk55C);

        setPair(&self->c570, &self->c574, &self->c578, a3);
        setPair(&self->c588, &self->c58C, &self->c590, a2);
    }
}
