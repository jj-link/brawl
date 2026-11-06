#include <types.h>
#pragma force_active on
extern void fn_8022C0E8(void);
extern void fn_8022C264(void);
extern void fn_8023A460(void (*callback)(void));
extern int fn_8023B45C(u16 command, u8 size, u8 *data, void (*callback)(void));
extern u32 lbl_805A0CEC;
extern s32 lbl_805A0CF0;
extern u32 lbl_805A0CF4;
extern u8 lbl_8047EE6C[];

static inline void copy_bytes(u8 *data, u32 source, s32 length)
{
    s32 i;
    for (i = 0; i < length; i++) {
        data[i + 4] = *(u8 *)(source + i + 8);
    }
}

void fn_8022C0EC(s32 arg0)
{
    u8 data[255];
    s32 length;
    if (arg0 == 0) {
        fn_8023A460(fn_8022C0E8);
        return;
    }
    length = (u8)(lbl_805A0CF4 < 251 ? lbl_805A0CF4 : 251);
    data[0] = lbl_805A0CEC;
    data[1] = lbl_805A0CEC >> 8;
    data[2] = lbl_805A0CEC >> 16;
    data[3] = lbl_805A0CEC >> 24;
    copy_bytes(data, (u32)lbl_8047EE6C, length);
    lbl_805A0CF0 = length;
    fn_8023B45C(0xFC4C, length + 4, data, fn_8022C264);
}
