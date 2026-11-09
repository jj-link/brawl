#include <gr/gr_gimmick.h>
#pragma force_active on
#pragma opt_propagation off
extern "C" int fn_88_6B7C(grGimmick* self) {
    int result = self->grGimmick::setNode();
    void* obj = *self->m_sceneModels;
    if (!obj) return 0;
    if (!*(u32*)((char*)obj + 0xe8)) return 0;
    self->Ground::getNodeIndex((u32*)((char*)self + 0x178), 0, "Nunber_Position_A_01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x17c), 0, "Nunber_Position_A_02");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x180), 0, "Nunber_Position_A_03");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x184), 0, "Nunber_Position_A_04");
    return result;
}