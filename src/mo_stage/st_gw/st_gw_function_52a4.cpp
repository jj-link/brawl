#include <gr/ground.h>

#pragma force_active on
#pragma push
#pragma opt_propagation off

struct NodeNames {
    char man1[0x14];
    char man2[0x14];
    char man3[0x14];
    char man4[0x14];
    char woman1[0x14];
    char woman2[0x14];
    char woman3[0x14];
    char woman4[0x14];
    char woman5[0x1C];
    char woman6[0x1C];
    char woman7[0x1C];
    char woman8[0x1C];
};

extern NodeNames lbl_63_data_1808;

extern "C" void fn_63_52A4(Ground* self) {
    self->Ground::processAnim();
    if (*(Vec3f**)((char*)self + 0x194)) {
        self->getNodePosition(*(Vec3f**)((char*)self + 0x194), 0, "_MAN_01_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x194) + 1, 0, "_MAN_02_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x194) + 2, 0, "_MAN_03_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x194) + 3, 0, "_MAN_04_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x194) + 4, 0, "_MAN_01_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x194) + 5, 0, "_MAN_02_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x194) + 6, 0, "_MAN_03_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x194) + 7, 0, "_MAN_04_POSITION");
    }
    if (*(Vec3f**)((char*)self + 0x198)) {
        self->getNodePosition(*(Vec3f**)((char*)self + 0x198), 0, "_WOMAN_01_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x198) + 1, 0, "_WOMAN_02_POSITION1");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x198) + 2, 0, "_WOMAN_03_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x198) + 3, 0, "_WOMAN_04_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x198) + 4, 0, "_WOMAN_ANGER_01_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x198) + 5, 0, "_WOMAN_ANGER_02_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x198) + 6, 0, "_WOMAN_ANGER_03_POSITION");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x198) + 7, 0, "_WOMAN_ANGER_04_POSITION");
    }
}
#pragma pop
