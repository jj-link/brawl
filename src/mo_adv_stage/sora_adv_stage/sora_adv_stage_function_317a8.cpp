#include <gr/gr_gimmick.h>
#pragma force_active on

extern "C" const unsigned int lbl_40_rodata_5D0[];
extern "C" const char lbl_40_data_E3A8[];

extern "C" void fn_40_317A8(grGimmick* self, void* archive) {
    unsigned int pathInfo[9];
    const unsigned int* defaults = lbl_40_rodata_5D0;

    pathInfo[0] = *defaults++;
    pathInfo[1] = *defaults++;
    pathInfo[2] = *defaults++;
    pathInfo[3] = *defaults++;
    pathInfo[4] = *defaults++;
    pathInfo[5] = *defaults++;
    pathInfo[6] = *defaults++;
    pathInfo[7] = *defaults++;
    pathInfo[8] = *defaults++;

    pathInfo[0] = (unsigned int)archive;
    pathInfo[1] = *(unsigned int*)((char*)self + 0x154);

    self->createAttachMotionPath(
        (grGimmickMotionPathInfo*)pathInfo,
        (stTriggerData*)((char*)*(void**)((char*)self + 0x154) + 0x1E4),
        lbl_40_data_E3A8
    );
}
