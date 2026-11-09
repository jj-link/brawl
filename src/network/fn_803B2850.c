#include <types.h>
#pragma force_active on
extern s32 fn_803B847C(void *, void *, s32, void *);
extern s32 fn_803B24E0(void *, s32, s32, void *);

s32 fn_803B2850(void *arg0, s32 arg1, s32 *arg2)
{
    s32 storage[16];
    s32 sp8;
    void *obj;
    u32 base;
    u32 outer;
    u32 limit;
    u32 count;
    u32 offset;
    s32 result;

    obj = *(void **)((char *)arg0 + 0x22c);
    *arg2 = 1;
    fn_803B847C(storage + 2, &sp8, *(s32 *)((char *)arg0 + 0x22c), (char *)arg0 + 0x234);

    base = 0xf0000;
    outer = 1;
    limit = base + 0x423f;
    while (outer <= limit) {
        result = fn_803B24E0(storage + 2, outer, arg1, *(void **)((char *)obj + 0x1868));
        if (result != 0)
            return result;
        count = 0;
        offset = 0;
        while (count < *(u32 *)((char *)obj + 0x1860)) {
            if ((u32)(*(u32 *)((char *)*(void **)((char *)obj + 0x1868) + offset) + 0x10000) != 0xffffU) {
                offset = count * 4;
                while ((*(u32 *)(offset + (u32)*(void **)((char *)obj + 0x1868)) & 1) != 0) {
                    *(u32 *)(offset + (u32)*(void **)((char *)obj + 0x1868)) >>= 1;
                    *arg2 += 1;
                }
                outer = base + 0x4240;
                break;
            } else {
                offset += 4;
                count += 1;
                *arg2 += 0x20;
            }
        }
        outer += *(u32 *)((char *)obj + 0x1860) << 5;
    }
    return 0;
}