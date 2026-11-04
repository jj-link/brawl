#include <string.h>
#include <types.h>
#pragma force_active on

extern void *fn_8035B1C4(void *obj, s32 *arg);
extern void fn_8035B078(void *obj, s32 *arg);

s32 fn_80370684(void **arg0, s32 arg1) {
    s32 sp40[7];
    s32 sp24[7];
    s32 sp8[7];
    void *obj;
    void *obj2;
    void *temp2;
    void *temp;

    obj = *arg0;
    if (arg1 <= 0) {
        return 0;
    }
    sp24[0] = arg1;
    temp = fn_8035B1C4(*(void **)((char *)obj + 0x444), sp24);
    if (temp != 0) {
        return (s32)temp;
    }
    memset(sp40, 0, 0x1C);
    sp40[0] = arg1;
    sp40[1] = 0;
    sp40[3] = 0;
    sp40[4] = 0;
    sp40[6] = 0;
    sp40[5] = 0;
    fn_8035B078(*(void **)((char *)obj + 0x444), sp40);
    *(s32 *)((char *)obj + 0x448) = *(s32 *)((char *)obj + 0x448) + 1;
    obj2 = *arg0;
    sp8[0] = arg1;
    temp2 = fn_8035B1C4(*(void **)((char *)obj2 + 0x444), sp8);
    if (temp2 != 0) {
        return (s32)temp2;
    }
    return 0;
}
