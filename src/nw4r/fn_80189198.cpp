// The previous revision scored 85.9% with 185 differing lines.
// This revision changes the address calculation for the four-byte swap table.
// Compiler verification was unavailable for this revision.
#include <types.h>
#include <nw4r/math/math_types.h>

#pragma force_active on

extern "C" {
extern void* lbl_805A0508;
void fn_80204E6C(void*, void*);
void* fn_80204E5C(void*, u32);
}

struct Bits {
    u32 a : 4, b : 4, c : 4, d : 2, e : 3, f : 1, g : 5;
    u32 h : 1, i : 1, j : 1, k : 1, rest : 5;
};

union Word {
    u32 raw;
    Bits bits;
};

struct Obj {
    u8 pad[0x38];
    Word w38;
    Word w3C;
    u8* p40;
};

typedef nw4r::math::VEC2 Vec2;

struct Srt {
    f32 rotate;
    Vec2 trans;
    Vec2 scale;

    Srt() : rotate(0.0f), trans(0.0f, 0.0f), scale(1.0f, 1.0f) {}

    void reset()
    {
        rotate = 0.0f;
        trans = Vec2(0.0f, 0.0f);
        scale = Vec2(1.0f, 1.0f);
    }

    void set(const Vec2& scaling, const Vec2& translation)
    {
        rotate = 0.0f;
        trans = translation;
        scale = scaling;
    }

    void resetTexSrt()
    {
        set(Vec2(1.0f, 1.0f), Vec2(0.0f, 0.0f));
    }
};

inline void resetSrts(u32 count, Srt* base)
{
    for (u32 i = 0; i < count; ++i) {
        base[i].resetTexSrt();
    }
}

inline u32 texSrtOffset(const Bits& cap)
{
    return cap.a * 28UL;
}

inline u32 texCoordOffset(const Bits& cap)
{
    return texSrtOffset(cap) + cap.b * 20UL;
}

inline u32 chanOffset(const Bits& cap)
{
    return texCoordOffset(cap) + cap.c * 4UL;
}

inline u32 colorOffset(const Bits& cap)
{
    return chanOffset(cap) + cap.h * 4UL;
}

inline u32 swapOffset(const Bits& cap)
{
    return colorOffset(cap) + cap.i * 4UL;
}

inline u32 alphaOffset(const Bits& cap)
{
    return swapOffset(cap) + cap.f * 4UL;
}

inline u32 blendOffset(const Bits& cap)
{
    return alphaOffset(cap) + cap.j * 4UL;
}

inline u32 indStageOffset(const Bits& cap)
{
    return blendOffset(cap) + cap.k * 4UL;
}

inline u32 indSrtOffset(const Bits& cap)
{
    return indStageOffset(cap) + cap.e * 4UL;
}

inline void resetIndirectSrts(Obj* self, u32 count)
{
    u32 n2;
    Srt* base2 = (Srt*)(self->p40 + indSrtOffset(self->w38.bits));

    for (n2 = 0; n2 < count; ++n2) {
        base2[n2].resetTexSrt();
    }
}

extern "C" void fn_80189198(
    Obj* self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7,
    u8 s8, u8 sC, u8 s10, u8 s14)
{
    u32 x = self->w38.raw;
    if ((x >> 28) < a1 || ((x >> 24) & 15) < a2 || ((x >> 20) & 15) < a3 ||
        ((x >> 9) & 31) < a4 || ((x >> 14) & 1) < a5 || ((x >> 15) & 7) < a6 ||
        ((x >> 18) & 3) < a7 || ((x >> 8) & 1) < s8 || ((x >> 7) & 1) < sC ||
        ((x >> 6) & 1) < s10 || ((x >> 5) & 1) < s14) {
        if (self->p40) {
            fn_80204E6C(lbl_805A0508, self->p40);
            self->p40 = 0;
            self->w38.raw &= 31;
            self->w3C.raw &= 31;
        }

        u32 m7 = (a7 + a2) * 20;
        u32 t1 = s10 + a5;
        u32 t2 = s14 + sC;
        u32 t3 = a6 + a3;
        u32 t4 = s8 + t1;
        u32 t5 = t2 + t3;
        u32 a4m = (a4 << 4) & 0xFF0;
        u32 m5 = a1 * 28;
        u32 sum = t5 + t4;
        u32 part = m7 + (sum << 2);
        u32 off = m5 + a4m;
        u8* mem = (u8*)fn_80204E5C(lbl_805A0508, part + off);
        self->p40 = mem;

        if (mem) {
            Word y;
            y.raw = self->w38.raw;
            y.bits.a = a1;
            y.bits.b = a2;
            y.bits.c = a3;
            y.bits.d = a7;
            y.bits.e = a6;
            y.bits.f = a5;
            y.bits.g = a4;
            y.bits.h = s8;
            y.bits.i = sC;
            y.bits.j = s10;
            y.bits.k = s14;

            Word z;
            z.raw = self->w3C.raw;
            z.bits.b = y.bits.b;
            self->w38.raw = y.raw;
            self->w3C.raw = z.raw;
            resetSrts(z.bits.b, (Srt*)(mem + y.bits.a * 28));

            self->w3C.bits.d = self->w38.bits.d;
            resetIndirectSrts(self, self->w3C.bits.d);

            {
                Word v;
                v.raw = self->w3C.raw;
                v.bits.h = self->w38.bits.h;
                self->w3C.raw = v.raw;
                if (v.bits.h) {
                    u8* p = self->p40 + chanOffset(self->w38.bits);
                    p[0] = 1;
                    p[1] = 1;
                    p[2] = 0;
                    p[3] = 0;
                }
            }
            {
                Word v;
                v.raw = self->w3C.raw;
                v.bits.i = self->w38.bits.i;
                self->w3C.raw = v.raw;
                if (v.bits.i) {
                    u8* p = self->p40 + colorOffset(self->w38.bits);
                    *(s32*)p = -1;
                }
            }
            {
                Word v;
                v.raw = self->w3C.raw;
                v.bits.f = self->w38.bits.f;
                self->w3C.raw = v.raw;
                if (v.bits.f) {
                    u8* p = self->p40 + swapOffset(self->w38.bits);
                    p[0] = 0xE4;
                    p[1] = 0xC0;
                    p[2] = 0xD5;
                    p[3] = 0xEA;
                }
            }
            {
                Word v;
                v.raw = self->w3C.raw;
                v.bits.j = self->w38.bits.j;
                self->w3C.raw = v.raw;
                if (v.bits.j) {
                    u8* p = self->p40 + alphaOffset(self->w38.bits);
                    p[0] = 0x77;
                    p[1] = 0;
                    p[2] = 0;
                    p[3] = 0;
                }
            }
            {
                Word v;
                v.raw = self->w3C.raw;
                v.bits.k = self->w38.bits.k;
                self->w3C.raw = v.raw;
                if (v.bits.k) {
                    u8* p = self->p40 + blendOffset(self->w38.bits);
                    p[0] = 1;
                    p[1] = 4;
                    p[2] = 5;
                    p[3] = 15;
                }
            }
        }
    }
}
