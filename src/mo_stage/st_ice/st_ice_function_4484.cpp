#include <gr/gr_gimmick.h>

#pragma force_active on
#pragma opt_propagation off

extern "C" char lbl_62_data_DB0[];

extern "C" int fn_62_4484(grGimmick* self) {
    const char* base = lbl_62_data_DB0;
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x184), 0, base + 0x18);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x188), 0, base + 0x28);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x18c), 0, base + 0x38);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x190), 0, base + 0x44);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x194), 0, base + 0x50);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x198), 0, base + 0x5c);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x19c), 0, base + 0x68);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1a0), 0, base + 0x78);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1a4), 0, base + 0x88);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1a8), 0, base + 0x98);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1ac), 0, base + 0xa8);
    return result;
}