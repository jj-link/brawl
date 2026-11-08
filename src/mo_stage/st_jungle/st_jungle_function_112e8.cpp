#include <gr/gr_gimmick.h>
#pragma force_active on
extern "C" int fn_51_112E8(grGimmick* self) {
    int result = self->grGimmick::setNode();
    self->getNodeIndex((u32*)((char*)self + 0x194), 0, "L9wheel1N");
    self->getNodeIndex((u32*)((char*)self + 0x198), 0, "L9wheel2N");
    self->getNodeIndex((u32*)((char*)self + 0x19c), 0, "L9wheel3N");
    self->getNodeIndex((u32*)((char*)self + 0x1a0), 0, "L9wheel4N");
    self->getNodeIndex((u32*)((char*)self + 0x1a4), 0, "L9BigWheel");
    return result;
}