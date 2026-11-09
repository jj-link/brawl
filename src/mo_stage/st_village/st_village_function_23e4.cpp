#include <types.h>
#include <mt/mt_vector.h>
#include <gr/ground.h>

#pragma force_active on
#pragma push
#pragma opt_propagation off

extern "C" void fn_70_23E4(Ground* self) {
    self->Ground::processAnim();
    if (*(Vec3f**)((char*)self + 0x164)) {
        self->getNodePosition(*(Vec3f**)((char*)self + 0x164), 0, "transLeftChrA");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x164) + 1, 0, "transLeftChrB");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x164) + 2, 0, "transCenterChrA");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x164) + 3, 0, "transCenterChrB");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x164) + 4, 0, "transGreas");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x164) + 5, 0, "transGreasCar");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x164) + 6, 0, "transHatoNoSu");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x164) + 7, 0, "transMaster");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x164) + 8, 0, "transTotakeke");
    }
}

#pragma pop