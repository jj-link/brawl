#include <types.h>
#pragma force_active on

typedef struct Obj {
    u32 flags;
    void *context;
    u32 unk8;
    u32 unkc;
    u32 size;
} Obj;

extern s32 fn_803D7B04(void *, void *);
extern s32 fn_803D7ECC(void *, s32, u32, u32, u32, s32);
extern u32 fn_803D87AC(Obj *, u32, u32);

s32 fn_803D8C48(Obj *self, s32 a1, u32 offset, u32 length, u32 a4, s32 a5)
{
    s32 result;
    u32 end;

    if ((self->flags & 8) != 8 || (self->flags & 2) == 2)
        return 15;
    result = fn_803D7B04(self->context, self);
    if (result != 0)
        return result;
    if (self->size <= offset)
        return 18;
    end = offset + length;
    if (self->size < end)
        length -= end - self->size;
    result = fn_803D7ECC(self->context, a1, fn_803D87AC(self, offset, a4), length, a4, a5);
    if (result != 0)
        return result;
    return 0;
}
