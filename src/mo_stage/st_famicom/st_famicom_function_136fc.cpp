#include <gr/gr_gimmick.h>

#pragma force_active on
#pragma opt_propagation off

extern "C" int fn_68_136FC(grGimmick* self) {
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x178), 0, "yukaD_Position");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x17c), 0, "yukaF_Position");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x180), 0, "yukaG_Position");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x184), 0, "yukaC_Position");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x188), 0, "yukaE_Position");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x18c), 0, "yukaA_Position");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x190), 0, "yukaB_Position");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x194), 0, "powBlockPosition");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x198), 0, "EnemyOutPointA");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x19c), 0, "EnemyOutPointB");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1a0), 0, "EnemyInPointA");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1a4), 0, "EnemyInPointB");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1a8), 0, "GreenBallPositionA");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1ac), 0, "GreenBallPositionB");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1b0), 0, "GreenBallPositionC");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x1b4), 0, "GreenBallPositionD");
    return result;
}
