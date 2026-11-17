#include <types.h>
#include <string.h>

#pragma force_active on

extern void fn_8022C0E8(void);
extern void fn_8022C494(s32);
extern void fn_8023A460(void (*)(void));
extern int fn_8023B45C(u16, u8, u8 *, void (*)(s32));

extern u32 lbl_805A0CEC;
extern u32 lbl_805A0CF0;
extern u32 lbl_805A0CF4;
extern u8 lbl_805A0CE9;
extern u8 lbl_805A0CEA;
extern u8 lbl_8047EE6C[];
extern u8 lbl_8047EF28[];

static inline void copy_bytes(u8 *data, s32 length)
{
    s32 i;

    for (i = 0; i < length; i++) {
        data[i + 4] = *(u8 *)((u32)(lbl_8047EE6C + lbl_805A0CF0) + i + 8);
    }
}

void fn_8022C264(s32 arg0)
{
    u8 other[255];
    u8 data[255];
    s32 length;
    u32 address;

    if (arg0 != 0) {
        if (lbl_805A0CF4 == lbl_805A0CF0) {
            u8 count;
            s32 size;

            lbl_805A0CE9 = 0;
            lbl_805A0CEA = lbl_8047EF28[0];
            count = (s32)lbl_8047EF28[0] < 19 ? lbl_8047EF28[0] : 19;
            size = count * 13;
            other[0] = count;
            memcpy(other + 1, lbl_8047EF28 + 1, size);
            lbl_805A0CE9 += count;
            fn_8023B45C(0xFC4F, size + 1, other, fn_8022C494);
        } else {
            length = (u8)(lbl_805A0CF4 - lbl_805A0CF0 < 251
                              ? lbl_805A0CF4 - lbl_805A0CF0
                              : 251);
            address = lbl_805A0CEC + lbl_805A0CF0;
            data[0] = address;
            data[1] = address >> 8;
            data[2] = address >> 16;
            data[3] = address >> 24;
            copy_bytes(data, length);
            lbl_805A0CF0 += length;
            fn_8023B45C(0xFC4C, length + 4, data, fn_8022C264);
        }
    } else {
        fn_8023A460(fn_8022C0E8);
    }
}