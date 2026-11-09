#include <gr/gr_gimmick.h>

#pragma force_active on
#pragma opt_propagation off

extern "C" int fn_51_CC5C(grGimmick* self) {
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1A8), 0, "L3ButtonClick");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1AC), 0, "L3togetoge");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1B0), 0, "L3moveN");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1B4), 0, "L3stoneN");
    return result;
}