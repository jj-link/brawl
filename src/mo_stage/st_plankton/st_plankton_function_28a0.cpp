#include <gr/ground.h>

#pragma force_active on
#pragma push
#pragma opt_propagation off

extern "C" void fn_74_28A0(Ground* self) {
    self->Ground::processAnim();
    if (*(Vec3f**)((char*)self + 0x158)) {
        self->getNodePosition(*(Vec3f**)((char*)self + 0x158), 0, "FrameLocA");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x158) + 1, 0, "FrameLocB");
    }
    if (*(Vec3f**)((char*)self + 0x15C)) {
        self->getNodePosition(*(Vec3f**)((char*)self + 0x15C), 0, "suimen01");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x15C) + 1, 0, "suimen02");
    }
}

#pragma pop