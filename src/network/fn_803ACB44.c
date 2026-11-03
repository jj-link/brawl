#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed int s32;

extern u8 lbl_8053A6E0[];

s32 fn_803ACB44(u32 arg0, u16 arg1, void **arg2, u16 *arg3, u16 *arg4)
{
    s32 n;
    u16 i;
    u16 idx;
    u8 *found;
    u16 found_idx;
    void *node;
    void *p;

    *arg2 = 0;
    found = 0;
    found_idx = 0;
    idx = 0;
    for (n = 0; n < 13; n++) {
        if (*(u32 *)(lbl_8053A6E0 + ((u16)idx << 3) + 0xD8) == 0) {
            break;
        }
        idx++;
        if (*(u32 *)(lbl_8053A6E0 + ((u16)idx << 3) + 0xD8) == 0) {
            break;
        }
        idx++;
    }

    if (idx >= 0x1A) {
        return 0xA;
    }
    *arg4 = idx;

    i = 0;
    for (n = 0; n < 13; n++) {
        p = lbl_8053A6E0 + ((u16)i * 0x2C);
        node = (u8 *)p + 0x6EC;
        if (!(*(u32 *)((u8 *)p + 0x6EC) & 1)) {
            if (found == 0) {
                found = node;
                found_idx = i;
            }
        } else if (arg1 == *(u16 *)((u8 *)p + 0x6F8) && *(u32 *)((u8 *)p + 0x6F0) == arg0) {
            *arg2 = node;
            *arg3 = i;
            return 0;
        }
        i++;
        p = (u8 *)lbl_8053A6E0 + ((u16)i * 0x2C);
        node = (u8 *)p + 0x6EC;
        if (!(*(u32 *)((u8 *)p + 0x6EC) & 1)) {
            if (found == 0) {
                found = node;
                found_idx = i;
            }
        } else if (arg1 == *(u16 *)((u8 *)p + 0x6F8) && *(u32 *)((u8 *)p + 0x6F0) == arg0) {
            *arg2 = node;
            *arg3 = i;
            return 0;
        }
        i++;
    }

    if (found == 0) {
        return 0xA;
    }
    *(u32 *)found |= 1;
    *(u16 *)lbl_8053A6E0 += 1;
    *(u32 *)(found + 4) = arg0;
    *(u16 *)(found + 0xC) = arg1;
    *arg2 = found;
    *arg3 = found_idx;
    return 0;
}
