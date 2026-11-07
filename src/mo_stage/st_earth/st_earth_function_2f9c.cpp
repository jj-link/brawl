#include <gr/gr_gimmick.h>

#pragma force_active on
#pragma opt_propagation off

extern "C" int fn_66_2F9C(grGimmick* self) {
    self->grGimmick::setNode();
    self->getNodeIndex((u32*)((char*)self + 0x1D0), 0, "tsutaJoint10");
    self->getNodeIndex((u32*)((char*)self + 0x1D4), 0, "tsutaJoint08");
    self->getNodeIndex((u32*)((char*)self + 0x1D8), 0, "tsutaJoint02");
    self->getNodeIndex((u32*)((char*)self + 0x1DC), 0, "tsutaJoint04");
    self->getNodeIndex((u32*)((char*)self + 0x1E0), 0, "tsutaJoint06");
    return 0;
}
