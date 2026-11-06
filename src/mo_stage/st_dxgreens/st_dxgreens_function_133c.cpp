#pragma force_active on
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_joint.h>

extern "C" grCollision* fn_27_222878(void* self, unsigned int index);

struct Self {
    unsigned char pad[0x7F8];
    grCollisionJoint* joint0;
    grCollisionJoint* joint1;
    grCollisionJoint* joint2;
};

extern "C" void fn_79_133C(Self* self) {
    short flags0;
    unsigned short flags1;
    short flags2;
    unsigned char* elem;
    unsigned char* sub;
    grCollisionJoint* joint0 = self->joint0;
    unsigned char i;
    unsigned char j;
    if (joint0 != 0 && self->joint1 != 0 && self->joint2 != 0) {
        flags0 = 0;
        flags1 = 0;
        flags2 = 0;
        for (i = 0; i < 6; i++) {
            elem = (unsigned char*)self + i * 0x8C;
            j = 0;
            while (j != 5) {
                sub = elem + j * 0x1C;
                if (sub[0x20D] != 2) {
                    j++;
                } else {
                    switch (i) {
                    case 0:
                        if (sub[0x20C] == 0) {
                            flags0 |= 0x4000;
                        }
                        break;
                    case 2:
                        if (sub[0x20C] <= 1) {
                            flags1 |= 0x2000;
                        }
                        break;
                    case 3:
                        if (sub[0x20C] <= 1) {
                            flags1 |= 0x4000;
                        }
                        break;
                    case 5:
                        if (sub[0x20C] == 0) {
                            flags2 |= 0x2000;
                        }
                        break;
                    }
                    j++;
                }
            }
        }
        joint0->m_0x52 = flags0;
        self->joint1->m_0x52 = flags1;
        self->joint2->m_0x52 = flags2;
    } else {
        grCollision* col = fn_27_222878(self, 0);
        if (col != 0) {
            self->joint0 = col->getJoint(0);
            self->joint1 = col->getJoint(1);
            self->joint2 = col->getJoint(2);
        }
    }
}
