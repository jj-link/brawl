#include <gr/gr_gimmick.h>
#pragma force_active on
#pragma opt_propagation off
extern "C" char lbl_51_data_EB8[];
extern "C" int fn_51_39C8(grGimmick* self) {
    const char* base = lbl_51_data_EB8;
    int result = self->grGimmick::setNode();
    self->getNodeIndex((u32*)((char*)self + 0x164), 0, base + 0x14);
    self->getNodeIndex((u32*)((char*)self + 0x168), 0, base + 0x1c);
    self->getNodeIndex((u32*)((char*)self + 0x16c), 0, base + 0x24);
    self->getNodeIndex((u32*)((char*)self + 0x174), 0, base + 0x2c);
    self->getNodeIndex((u32*)((char*)self + 0x178), 0, base + 0x34);
    self->getNodeIndex((u32*)((char*)self + 0x17c), 0, base + 0x3c);
    self->getNodeIndex((u32*)((char*)self + 0x180), 0, base + 0x44);
    self->getNodeIndex((u32*)((char*)self + 0x184), 0, base + 0x4c);
    self->getNodeIndex((u32*)((char*)self + 0x188), 0, base + 0x54);
    self->getNodeIndex((u32*)((char*)self + 0x18c), 0, base + 0x5c);
    self->getNodeIndex((u32*)((char*)self + 0x190), 0, base + 0x64);
    self->getNodeIndex((u32*)((char*)self + 0x194), 0, base + 0x6c);
    return result;
}