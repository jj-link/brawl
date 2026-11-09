#include <gr/gr_gimmick.h>

#pragma force_active on
#pragma opt_propagation off

extern "C" int fn_61_8BF4(grGimmick* self) {
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x178), 0, "FZmachine01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x17C), 0, "FZmachine02");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x180), 0, "FZmachine03");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x184), 0, "FZmachine04");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x188), 0, "FZmachine05");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x18C), 0, "FZmachine06");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x190), 0, "FZmachine07");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x194), 0, "FZmachine08");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x198), 0, "FZmachine09");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x19C), 0, "FZmachine10");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A0), 0, "FZmachine11");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A4), 0, "FZmachine12");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A8), 0, "FZmachine13");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1AC), 0, "FZmachine14");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1B0), 0, "FZmachine15");
    return result;
}