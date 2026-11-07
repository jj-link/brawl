#include <gr/gr_gimmick.h>
#pragma force_active on
#pragma opt_propagation off
extern "C" char lbl_88_data_1D80[];
extern "C" int fn_88_71DC(grGimmick* self) {
    const char* base = lbl_88_data_1D80;
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x168), 0, base + 0x04);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x16c), 0, base + 0x10);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x170), 0, base + 0x1c);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x174), 0, base + 0x28);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x178), 0, base + 0x34);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x17c), 0, base + 0x40);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x180), 0, base + 0x4c);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x184), 0, base + 0x58);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x188), 0, base + 0x64);
    self->Ground::getNodeIndex((u32*)((char*)self + 0x18c), 0, base + 0x70);
    return result;
}