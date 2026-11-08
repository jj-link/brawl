#include <gr/ground.h>

#pragma force_active on
#pragma push
#pragma opt_propagation off

extern "C" void fn_62_3260(Ground* self) {
    self->Ground::processAnim();
    if (*(Matrix**)((char*)self + 0x158)) {
        self->getNodeMatrix(*(Matrix**)((char*)self + 0x158), 0, "P_Kumoyuka1_a");
        self->getNodeMatrix(*(Matrix**)((char*)self + 0x158) + 1, 0, "P_Kumoyuka1_b");
        self->getNodeMatrix(*(Matrix**)((char*)self + 0x158) + 2, 0, "P_Kumoyuka2_a");
        self->getNodeMatrix(*(Matrix**)((char*)self + 0x158) + 3, 0, "P_Kumoyuka2_b");
        self->getNodeMatrix(*(Matrix**)((char*)self + 0x158) + 4, 0, "P_kaimen_a");
        self->getNodeMatrix(*(Matrix**)((char*)self + 0x158) + 5, 0, "P_kaimen_b");
    }
    if (*(Vec3f**)((char*)self + 0x15C)) {
        self->getNodePosition(*(Vec3f**)((char*)self + 0x15C), 0, "P_Fish_a");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x15C) + 1, 0, "P_Fish_b");
    }
}

#pragma pop