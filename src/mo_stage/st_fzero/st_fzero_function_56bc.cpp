#include <gr/gr_gimmick.h>

#pragma force_active on
#pragma opt_cycle_count off
#pragma opt_propagation off

extern "C" char jumptable_61_data_12C0[];

extern "C" int fn_61_56BC(grGimmick* self) {
    char* base = jumptable_61_data_12C0;
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x174), 0, base + 0xA0);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x178), 0, base + 0xB0);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x17C), 0, base + 0xC0);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x180), 0, base + 0xCC);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x184), 0, base + 0xD8);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x188), 0, base + 0xE4);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x18C), 0, base + 0xF0);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x190), 0, base + 0xFC);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x194), 0, base + 0x108);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x198), 0, base + 0x114);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x19C), 0, base + 0x120);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A0), 0, base + 0x12C);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A4), 0, base + 0x138);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A8), 0, base + 0x144);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1AC), 0, base + 0x150);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1B0), 0, base + 0x15C);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1B4), 0, base + 0x168);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1B8), 0, base + 0x174);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1BC), 0, base + 0x180);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1C0), 0, base + 0x18C);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1C4), 0, base + 0x198);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1C8), 0, base + 0x1A8);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1CC), 0, base + 0x1B4);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1D0), 0, base + 0x1C4);
    return result;
}