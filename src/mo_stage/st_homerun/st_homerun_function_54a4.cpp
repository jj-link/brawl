#include <gr/gr_gimmick.h>

#pragma force_active on

extern "C" int fn_88_54A4(grGimmick* self) {
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1CC), 0, "SubStadium_A_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1D0), 0, "SubStadium_B_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1D4), 0, "SubStadium_A_02");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1D8), 0, "SubStadium_C_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1DC), 0, "SubStadium_A_03");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1E0), 0, "SubStadium_B_02");
    return result;
}
