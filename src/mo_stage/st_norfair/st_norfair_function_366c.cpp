#include <types.h>
#include <gr/gr_gimmick.h>
#pragma force_active on
extern "C" int fn_54_366C(grGimmick* self) {
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x164), 0, "L_Safety_asiba_a");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x168), 0, "L_Safety_asiba_b");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x16C), 0, "L_Safety_asiba_c");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x170), 0, "L_Safety_asiba_d");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x174), 0, "L_Safety_asiba_e");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x178), 0, "L_asiba_trainer_1");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x17C), 0, "L_asiba_trainer_2");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x180), 0, "L_asiba_trainer_3");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x184), 0, "L_asiba_trainer_4");
    return result;
}