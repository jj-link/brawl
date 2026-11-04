#include <types.h>
#pragma force_active on
typedef struct { char pad0[4]; int field4; char pad8[12]; u32 field14; char pad18[4]; u32 field1c; } Obj;
extern int fn_803AC40C(int, u16 *);
u32 fn_803ACA68(Obj *obj, u32 arg1, u32 arg2) {
    u16 value;
    u32 size;
    u32 n;
    fn_803AC40C(obj->field4, &value);
    if (arg2 == value) return arg1 + obj->field14 + obj->field1c;
    size = (value >> 9) & 0x7f;
    n = obj->field14 + obj->field1c;
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