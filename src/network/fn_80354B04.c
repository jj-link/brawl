#include <types.h>
#pragma force_active on
extern void *fn_80335390(s32 type, s32 size);
extern void fn_80335450(s32 type, void *p, s32 flag);
extern void fn_8035DAA4(void *buf, void *dst, u32 len, s32 flag, u8 byte);
extern u32 lbl_805A0FE4;
extern char lbl_8048DC08[];
static inline u8 next_byte(void)
{
    lbl_805A0FE4 = (*(u32 *)(lbl_8048DC08 + 0x48) +
                   *(u32 *)(lbl_8048DC08 + 0x44) * lbl_805A0FE4) %
                  *(u32 *)(lbl_8048DC08 + 0x4C);
    return (u8)(lbl_805A0FE4 >> 16);
}
s32 fn_80354B04(void *arg0, const u8 *arg1, s32 arg2, const u8 *arg3, s32 arg4)
{
    s32 size;
    s32 total;
    s32 i;
    u8 *buf;
    u32 sum;
    u32 value;
    u32 length;
    total = arg4 + arg2;
    size = total + 4;
    sum = 0;
    buf = fn_80335390(8, size);
    if (buf == 0) return 2;
    for (i = 0; i < arg2; i++) buf[i + 4] = arg1[i];
    for (i = 0; i < arg4; i++) buf[(u32)i + arg2 + 4] = arg3[i];
    for (i = 0; i < total; i++) sum += buf[i + 4];
    lbl_805A0FE4 = sum | (sum << 16);
    for (i = 0; i < total; i++) {
        buf[i + 4] ^= next_byte();
    }
    length = total + 4U;
    sum ^= *(u32 *)(lbl_8048DC08 + 0x50);
    buf[0] = (u8)(sum >> 24);
    buf[1] = (u8)(sum >> 16);
    buf[2] = (u8)(sum >> 8);
    buf[3] = (u8)sum;
    fn_8035DAA4(buf, arg0, length, 2, (u8)(sum >> 16));
    fn_80335450(8, buf, 0);
    *((u8 *)(((u32)size / 3 + (length % 3 != 0)) * 4) + (u32)arg0) = 0;
    return 0;
}
