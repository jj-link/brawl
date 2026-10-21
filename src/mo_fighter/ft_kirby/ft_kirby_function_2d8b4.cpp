#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" const float lbl_96_rodata_5B0[];

extern "C" void fn_96_2D8B4(void*, soModuleAccesser* accesser) {
    const float* k = lbl_96_rodata_5B0;
    Vec3f rotate = accesser->getModelModule().getNodeRotate(1);
    rotate.m_y = (k[4] == accesser->getPostureModule().getLr()) ? k[3] : k[2];
    accesser->getModelModule().setNodeRotate(1, &rotate);
}
