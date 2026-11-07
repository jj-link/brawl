#include <revolution/GX.h>
#pragma force_active on

extern "C" {
void fn_801F3F5C(int, int, int, int, int);
void fn_801F3F20(int, int, int);

void fn_8007B4A4(void) {
    GXSetZMode(1, GX_ALWAYS, 0);
    GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_SET);
    GXSetNumTexGens(1);
    GXSetNumChans(0);
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    fn_801F3F20(0, 0, 0);
    fn_801F3F20(1, 0, 0);
    fn_801F3F20(2, 0, 0);
    fn_801F3F20(3, 0, 0);
    fn_801F3F5C(0, 0, 1, 2, 3);
    fn_801F3F5C(1, 0, 0, 0, 3);
    fn_801F3F5C(2, 1, 1, 1, 3);
    fn_801F3F5C(3, 2, 2, 2, 3);
}
}
