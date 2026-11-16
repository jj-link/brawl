#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

#pragma opt_common_subs off

extern "C" {
void fn_801139E4(void*);
void fn_80113724(void*, int);
void fn_80113824(void*);
void fn_80041F44(Rect2D*, Rect2D*, Rect2D*);
extern float lbl_805A2908;
extern float lbl_805A290C;
}

struct Words {
    struct Pair {
        u32 a, b;
    };
    Pair a, b;
};

struct Bits {
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 1;
    unsigned char d : 1;
    unsigned char e : 1;
    unsigned char f : 1;
    unsigned char g : 1;
    unsigned char h : 1;
};

extern "C" void fn_80110CEC(void* arg)
{
    Words other;
    u8* self = (u8*)arg;
    u8* entry;
    int offset;
    int initialize;
    int activeCount;
    int reverse;
    int first;
    Rect2D* bounds;
    u32 i;
    u8 enabled;
    Bits next;
    u8 flags = self[0x2C];

    if ((flags >> 6) & 1) {
        self[0x2C] = (flags | 0x80) & ~0x40;
    }

    flags = self[0x2C];
    initialize = 1;
    activeCount = 0;

    enabled = (flags >> 7) & 1;
    next = *(Bits*)(self + 0x2D);
    next.b = (flags >> 7) & 1;
    next.c = (flags >> 3) & 1;
    *(Bits*)(self + 0x2D) = next;

    if (enabled) {
        reverse = !((flags >> 2) & 1);
        bounds = (Rect2D*)(self + 0x1C);
        first = 1;
        i = 0;
        offset = 0;

        while (i < *(u16*)(self + 6)) {
            entry = *(u8**)(self + 0x18) + offset;
            fn_801139E4(entry);

            if ((entry[0x54] >> 6) & 1) {
                fn_80113724(entry, reverse);

                if ((entry[0x55] >> 6) & 1) {
                    fn_80113824(entry);
                }

                ++activeCount;

                if (first) {
                    first = 0;
                    *(Words*)bounds = *(Words*)(entry + 0x10);
                } else {
                    other = *(Words*)(entry + 0x10);
                    fn_80041F44(bounds, (Rect2D*)&other, bounds);
                }
            }

            offset += 0x60;
            ++i;
        }

        ((Bits*)(self + 0x2C))->f = 1;
        ((Bits*)(self + 0x2C))->d = activeCount != 0;

        if (activeCount) {
            initialize = 0;
        }
    }

    if (initialize) {
        Rect2D r = {
            lbl_805A2908,
            lbl_805A2908,
            lbl_805A290C,
            lbl_805A2908
        };
        register f32 x1 = r.m_left;
        register f32 x0 = r.m_up;
        register f32 p2, p3, p4, p5;

        asm { ps_sub p4, x1, x1 }
        asm { ps_sub p5, x0, x1 }
        asm { ps_sub p3, x0, x1 }
        asm { ps_sub p2, x1, x1 }
        asm { ps_sel p5, p5, x1, x0 }
        asm { ps_sel p4, p4, x1, x1 }
        asm { ps_sel p3, p3, x0, x1 }
        asm { ps_sel p2, p2, x1, x1 }

        *(f32*)(self + 0x1C) = p5;
        *(f32*)(self + 0x20) = p4;
        *(f32*)(self + 0x24) = p3;
        *(f32*)(self + 0x28) = p2;
    }
}
