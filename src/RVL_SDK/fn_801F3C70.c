#pragma force_active on
#include <revolution/GX/GXHardware.h>

typedef unsigned short u16x;

typedef struct {
    u32 fields[0x70];
} FieldArr;

extern struct _GXData *const __GXData;

void fn_801F3C70(s32 idx, s32 a, s32 b, s32 c, s32 d)
{
    FieldArr *arr = (FieldArr *)((char *)__GXData + 0x1C0);
    u32 *field = &arr->fields[idx];
    u32 v = *field;
    v = __rlwimi(v, a, 13, 16, 18);
    v = __rlwimi(v, b, 10, 19, 21);
    WGPIPE.c = 0x61;
    v = __rlwimi(v, c, 7, 22, 24);
    v = __rlwimi(v, d, 4, 25, 27);
    WGPIPE.ui = v;
    *field = v;
    *(u16 *)((char *)__GXData + 2) = 0;
}
