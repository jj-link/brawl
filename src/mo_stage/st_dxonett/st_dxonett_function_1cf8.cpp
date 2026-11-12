#include <gr/gr_gimmick.h>

#pragma force_active on

extern "C" int fn_78_1CF8(grGimmick* self) {
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x15C), 0, "CarLeftPositionA");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x160), 0, "CarRightPositionA");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x164), 0, "CarLeftPositionB");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x168), 0, "CarRightPositionB");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x16C), 0, "kemuriGen");
    return result;
}
