#include <types.h>
#pragma force_active on

extern int fn_803D7B40(int, u16 *);

typedef struct {
    char pad0[4];
    int field4;
    char pad8[4];
    u32 fieldC;
} Obj;

u32 fn_803D87AC(Obj *obj, u32 arg1, u32 arg2) {
    u16 value;
    u32 n;
    u32 size;

    fn_803D7B40(obj->field4, &value);
    if (arg2 == value) return arg1 + obj->fieldC;
    size = (value >> 9) & 0x7f;
    n = obj->fieldC;
    if (size == 2) n *= 2;
    else if (size == 4) n *= 4;
    else if (size == 8) n *= 8;
    {
        u32 kind = (arg2 >> 9) & 0x7f;
        if (kind == 2) n >>= 1;
        else if (kind == 4) n >>= 2;
        else if (kind == 8) n >>= 3;
    }
    return arg1 + n;
}
