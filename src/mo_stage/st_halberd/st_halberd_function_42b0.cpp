#include <gr/ground.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_joint.h>
#pragma force_active on
extern "C" {
extern char lbl_57_data_884[];
extern char lbl_57_data_898[];
grCollisionJoint* getJoint__11grCollisionFUs(grCollision*, unsigned int);
}
struct HalberdGround : Ground {
    char padding[0x184 - sizeof(Ground)];
    grCollisionJoint* joint1;
    grCollisionJoint* joint2;
};
extern "C" void fn_57_42B0(HalberdGround* self) {
    grCollision* coll;
    u32 i;
    u16 count;
    u32 idx2, idx1;
    grCollisionJoint* j;

    if (self->joint1 != 0) return;
    coll = self->m_collision;
    if (coll == 0) return;
    if (!self->getNodeIndex(&idx1, 0, lbl_57_data_884)) return;
    if (!self->getNodeIndex(&idx2, 0, lbl_57_data_898)) return;
    count = *(u16*)&coll->m_jointLen;
    for (i = 0; i != count; ++i) {
        j = getJoint__11grCollisionFUs(coll, i);
        if (j == 0) return;
        if (j->m_ground == self && j->_0x4E == 0) {
            if (idx1 == j->m_nodeIndex) {
                j->m_0x56_7 = true;
                j->m_0x54_7 = false;
                j->m_0x54_4 = j->m_0x54_7;
                j->m_0x54_6 = j->m_0x54_4;
                self->joint1 = j;
            } else if (idx2 == j->m_nodeIndex) {
                j->m_0x56_7 = true;
                j->m_0x54_7 = false;
                j->m_0x54_4 = j->m_0x54_7;
                j->m_0x54_6 = j->m_0x54_4;
                self->joint2 = j;
            }
        }
    }
}
