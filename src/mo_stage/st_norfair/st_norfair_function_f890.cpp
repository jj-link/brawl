#include <gr/gr_gimmick.h>
#pragma force_active on
extern "C" int fn_54_F890(grGimmick* self) {
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x188), 0, "Collision_left1");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x18c), 0, "Collision_left2");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x190), 0, "Collision_left3");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x194), 0, "Collision_left4");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x198), 0, "Collision_left5");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x19c), 0, "Collision_left6");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1a0), 0, "Collision_center1");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1a4), 0, "Collision_center2");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1a8), 0, "Collision_center3");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1ac), 0, "Collision_center4");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1b0), 0, "Collision_center5");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1b4), 0, "Collision_center6");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1b8), 0, "Collision_right1");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1bc), 0, "Collision_right2");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1c0), 0, "Collision_right3");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1c4), 0, "Collision_right4");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1c8), 0, "Collision_right5");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1cc), 0, "Collision_right6");
    return result;
}