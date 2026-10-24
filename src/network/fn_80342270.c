#pragma force_active on
#pragma global_optimizer off

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern void *memset(void *, int, unsigned long);
extern u8 lbl_80533FE8[];
extern u8 *lbl_805A0FA8;

s32 fn_80342270(u8 **arg0)
{
    u8 *src;
    u8 *dst;
    u8 id;
    u8 *base;
    s32 i;

    if (lbl_805A0FA8 == 0) {
        return 0;
    }

    memset(lbl_80533FE8, 0, 0x20);
    base = lbl_805A0FA8;
    dst = lbl_80533FE8;
    i = 0;
    src = base;

    while (i <= (s32)base[0xE]) {
        id = src[0x2E8];
        if ((*(u32 *)(base + 0x308) & (1 << id)) == 0) {
            break;
        }
        *dst = id;
        src++;
        dst++;
        i++;
    }

    *arg0 = lbl_80533FE8;
    return lbl_805A0FA8[0xE] + 1;
}
