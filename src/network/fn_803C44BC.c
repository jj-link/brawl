#include <types.h>
#pragma force_active on
extern s32 lbl_805A1210;
extern s32 lbl_805A1214;
extern s32 lbl_805A1218;
extern s32 lbl_805A121C;
extern s32 lbl_805A1220;
extern s32 lbl_805A1228;
extern s32 lbl_805A122C;
extern s32 lbl_80563218[];
s32 fn_80204688(s32, s32, s32);
s32 fn_80204768(s32, s32, s32);
void fn_803A976C(s32, s32, s32);
void fn_803C7B78(void);
void fn_803CB000();
void fn_803C44BC(s32 arg0, s32 arg1) {
    u32 end, i, ptr;
    s32 count, buf;
    u32 base;
    ptr = (u32)arg1 >> 14;
    if (arg0 != 0 && arg1 != 0 && lbl_805A1218 == 0) {
        lbl_805A1218 = fn_80204688(arg0, arg1, 0);
    }
    if (ptr > 0x1a) {
        count = 0x1a;
    } else {
        count = (s32)ptr;
    }
    lbl_805A1210 = count;
    if (lbl_805A1220 == 0) {
        if (lbl_805A1218 == 0) {
            buf = 0;
        } else {
            buf = fn_80204768(lbl_805A1218, count * 0x140, 0x20);
        }
        lbl_805A1220 = buf;
    }
    if (lbl_805A1210 != 0 && lbl_805A1220 != 0) {
        base = (u32)lbl_805A1220;
    } else {
        base = 0;
    }
    end = base + (u32)(lbl_805A1210 * 0x140);
    while (base != end) {
        fn_803A976C((s32)base, 0, 0x140);
        if (base + 0x1c != 0) {
            *(s32 *)(base + 0x1c) = 0;
            *(s32 *)(base + 0x20) = 0;
            *(s32 *)(base + 0x24) = 0;
            *(s32 *)(base + 0x28) = 0;
        }
        base += 0x140;
    }
    count = lbl_805A1210;
    if (lbl_805A121C == 0) {
        ptr = 0;
        i = (u32)lbl_80563218;
        while (ptr < count) {
            if (lbl_805A1218 == 0) {
                buf = 0;
            } else {
                buf = fn_80204768(lbl_805A1218, 0xa0, 0x20);
            }
            *(s32 *)i = buf;
            i += 4;
            ptr++;
        }
        lbl_805A121C = 1;
    }
    fn_803C7B78();
    lbl_805A1214 = 0;
    lbl_805A122C = 2;
    lbl_805A1228 = 8;
    fn_803CB000();
}