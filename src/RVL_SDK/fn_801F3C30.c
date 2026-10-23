#include <revolution/GX/GXHardware.h>
#pragma force_active on

typedef struct _GXData {
    char pad[2];
    u16 unk2;
    char pad3[0x17C];
    u32 fields[0x40];
} GXData;

extern GXData *const __GXData;

void fn_801F3C30(s32 idx, s32 a, s32 b, s32 c, s32 d)
{
    GXData *gx = __GXData;
    u32 *field = &gx->fields[idx];
    u32 v = *field;
    v = __rlwimi(v, a, 12, 16, 19);
    v = __rlwimi(v, b, 8, 20, 23);
    WGPIPE.c = 0x61;
    v = __rlwimi(v, c, 4, 24, 27);
    v = __rlwimi(v, d, 0, 28, 31);
    WGPIPE.ui = v;
    *field = v;
    gx->unk2 = 0;
}
