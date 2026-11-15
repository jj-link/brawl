#include <gr/gr_gimmick.h>

#pragma force_active on

extern "C" int fn_88_5CF4(grGimmick* self) {
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x184), 0, "Ground_A_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x188), 0, "Ground_A_02");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x18C), 0, "Ground_B_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x190), 0, "Ground_B_02");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x194), 0, "Ground_C_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x198), 0, "Ground_C_02");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x19C), 0, "Ground_D_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A0), 0, "Ground_D_02");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A4), 0, "Ground_E_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A8), 0, "Ground_E_02");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1AC), 0, "Ground_F_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1B0), 0, "Ground_F_02");
    return result;
}
