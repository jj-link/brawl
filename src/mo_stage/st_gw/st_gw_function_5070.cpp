#include <gr/ground.h>

#pragma force_active on
#pragma push
#pragma opt_propagation off

extern "C" void fn_63_5070(Ground* self) {
    self->Ground::processAnim();
    if (*(Vec3f**)((char*)self + 0x194)) {
        self->getNodePosition(*(Vec3f**)((char*)self + 0x194), 0, "_KEEPER_L_POSITION_01");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x194) + 1, 0, "_KEEPER_L_POSITION_02");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x194) + 2, 0, "_KEEPER_L_POSITION_03");
    }
    if (*(Vec3f**)((char*)self + 0x198)) {
        self->getNodePosition(*(Vec3f**)((char*)self + 0x198), 0, "_KEEPER_R_POSITION_01");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x198) + 1, 0, "_KEEPER_R_POSITION_02");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x198) + 2, 0, "_KEEPER_R_POSITION_03");
    }
}

#pragma pop
