#include <gr/gr_gimmick.h>
#pragma force_active on

extern "C" const unsigned int lbl_27_rodata_44A0[];
extern "C" const char lbl_27_data_580D0[];

extern "C" void fn_27_272940(grGimmick* self, void* archive) {
    unsigned int pathInfo[9];
    const unsigned int* defaults = lbl_27_rodata_44A0;

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
    pathInfo[1] = *(unsigned int*)((char*)self + 0x150);
    pathInfo[3] = *(unsigned int*)((char*)self + 0x150) + 0x48;
    pathInfo[4] = *(unsigned int*)((char*)self + 0x150) + 0x120;
    pathInfo[5] = *(unsigned int*)((char*)self + 0x150) + 0x198;
    pathInfo[6] = *(unsigned int*)((char*)self + 0x150) + 0x6C;
    pathInfo[7] = *(unsigned int*)((char*)self + 0x150) + 0x15C;
    pathInfo[8] = *(unsigned int*)((char*)self + 0x150) + 0x1BC;

    self->createAttachMotionPath(
        (grGimmickMotionPathInfo*)pathInfo,
        (stTriggerData*)(*(unsigned int*)((char*)self + 0x150) + 0x1E4),
        lbl_27_data_580D0);
}
