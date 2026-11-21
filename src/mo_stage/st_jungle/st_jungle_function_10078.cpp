#include <gr/gr_gimmick.h>

#pragma force_active on
#pragma opt_propagation off

extern "C" bool fn_51_10078(grGimmick* self) {
    bool result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1a8), 0, "L8ButtonClick");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1ac), 0, "L8TogeToge01");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1b0), 0, "L8trapN");
    return result;
}