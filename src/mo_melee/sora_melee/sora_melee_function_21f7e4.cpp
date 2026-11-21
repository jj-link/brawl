#include <types.h>
#pragma force_active on

extern f32 lbl_27_rodata_32A8;
extern f32 lbl_27_rodata_32AC;

struct Obj {
    u8* data;
    char pad[4];
    s8 value;
    char pad2[3];
    u32 mask;
};

extern "C" u16 fn_27_21F7E4(Obj* self, s32 index, s32 count) {
    if (index >= 0 && (u32)index < 24) {
        u8* base = self->data;
        if (*(s32*)(base + 0x170 + index * 4) != 0) {
            u8* p = base + *(s32*)(base + 0x170 + index * 4);
            f32 a = lbl_27_rodata_32A8 * (f32)self->value;
            f32 b = lbl_27_rodata_32AC - a;
            u8 id;
            while ((id = *p) != 0) {
                if (!(self->mask & (1 << (id - 1)))) {
                    if ((s32)((f32)p[1] * a + (f32)p[2] * b) > 0) {
                        if (--count < 0)
                            break;
                    }
                }
                p += 3;
            }
            if (count < 0) {
                u8 v = id - 1;
                if (v < 22) {
                    s32 n = v;
                    s32 result;
                    if (n >= 0) {
                        if (n < 13)
                            result = n + 0x6031;
                        else if (n < 22)
                            result = n + 0x6034;
                        else
                            goto zero;
                    } else {
                    zero:
                        result = 0;
                    }
                    return result;
                }
            }
        }
    }
    return 0;
}
