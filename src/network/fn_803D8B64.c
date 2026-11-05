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
extern u32 fn_803D87AC(Obj *, u32, u32);
extern s32 fn_803D7DC8(void *, s32, u32, u32, u32, s32);
s32 fn_803D8B64(Obj *self, s32 a, u32 offset, u32 length, u32 mode, s32 last)
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
    result = fn_803D7DC8(self->context, a, fn_803D87AC(self, offset, mode), length, mode, last);
    if (result != 0)
        return result;
    return 0;
}