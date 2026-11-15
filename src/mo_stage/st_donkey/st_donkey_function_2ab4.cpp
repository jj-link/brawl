#include <types.h>
#include <gr/gr_gimmick.h>

#pragma force_active on

extern "C" int fn_50_2AB4(grGimmick* self) {
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x16C), 0, "Position_DonkeyKong");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x170), 0, "Position_Jack");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x174), 0, "Position_Elevator_L1");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x178), 0, "Position_Elevator_L2");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x17C), 0, "Position_Elevator_R1");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x180), 0, "Position_Elevator_R2");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x184), 0, "Position__Score_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x188), 0, "Position__Score_02");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x18C), 0, "Position__Score_03");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x190), 0, "Position__Score_04");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x194), 0, "Position__Score_05");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x198), 0, "Position__Score_06");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x19C), 0, "Position__Score_07");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A0), 0, "Position__Score_08");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A4), 0, "Position__Score_09");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A8), 0, "Position__Score_10");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1AC), 0, "Position__Score_11");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1B0), 0, "Position__Score_12");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1B4), 0, "hasigo_09");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1B8), 0, "hasigo_07");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1BC), 0, "hasigo_08");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1C0), 0, "hasigo_06");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1C4), 0, "hasigo_02");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1C8), 0, "hasigo_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1CC), 0, "hasigo_05");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1D0), 0, "hasigo_11");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1D4), 0, "hasigo_10");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1D8), 0, "hasigo_04");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1DC), 0, "Position_fireball_A_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1E0), 0, "Position_fireball_A_02");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1E4), 0, "Position_fireball_A_03");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1E8), 0, "Position_fireball_A_04");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1EC), 0, "Position_fireball_A_05");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1F0), 0, "Position_fireball_B_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1F4), 0, "Position_fireball_B_02");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1F8), 0, "Position_fireball_B_03");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1FC), 0, "Position_fireball_B_04");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x200), 0, "Position_fireball_B_05");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x204), 0, "Position_fireball_B_06");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x208), 0, "Position_fireball_B_07");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x20C), 0, "Position_Parasol");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x210), 0, "Position_Handbag");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x214), 0, "Position_Hat");
    return result;
}
