#include <types.h>
#pragma force_active on

extern u8 lbl_804FD448[];
extern void *fn_80230574(u32 size);
extern void fn_8022E978(u8 index, u32 size, s32 count);

static inline void set_flag(u8 index, u32 flag)
{
    u8 *p = lbl_804FD448 + 0x54;
    if (index < 9) {
        if (flag == 1) {
            *(u16 *)(p + 0x28A7C) |= 1 << index;
        } else {
            *(u16 *)(p + 0x28A7C) &= ~(1 << index);
        }
    }
}

u8 fn_8022F914(u32 size, s32 count, u32 flag, void *memory)
{
    u8 index;
    u8 *base;
    u8 *p;
    u16 key;
    s32 i;
    s32 j;
    s32 n;
    u32 bytes;

    base = lbl_804FD448 + 0x54;
    if (size > 0xFFF3) {
        return 0xFF;
    }

    for (index = 0; index < 9; index++) {
        if (((u32 *)base)[index + 0xA287] == 0) {
            break;
        }
    }
    if (index == 9) {
        return 0xFF;
    }

    bytes = (((size + 3) & ~3) + 12) * count;
    if (memory == 0) {
        memory = fn_80230574(bytes);
    }
    if (memory != 0) {
        fn_8022E978(index, size, count);

        p = lbl_804FD448 + 0x54;
        key = *(u16 *)(p + (index << 4) + 0x28994);
        n = p[0x28A87];
        for (i = 0; i < n; i++) {
            if (key <= *(u16 *)(p + (p[0x28A7E + i] << 4) + 0x28994)) {
                break;
            }
        }

        for (j = p[0x28A87]; j > i; j--) {
            p[0x28A7E + j] = p[0x28A7D + j];
        }
        p[0x28A7E + i] = index;
        set_flag(index, flag);
        base[0x28A87]++;
        return index;
    }
    return 0xFF;
}
