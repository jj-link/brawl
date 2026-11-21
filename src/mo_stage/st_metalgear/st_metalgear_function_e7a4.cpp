#include <gr/ground.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_joint.h>
#include <mt/mt_vector.h>
#pragma force_active on
extern "C" {
extern const float lbl_71_rodata_238;
extern const float lbl_71_rodata_23C[];
}
struct Flags { unsigned int a : 8; unsigned int b : 8; unsigned int c : 16; };
struct State { float x, y, z; };
struct Bounds { float a, b, c, d, e; };
struct MetalGround : Ground {
    char padding[0x158 - 0x9c];
    State* state;
    Bounds* bounds;
    char padding2[4];
    float value;
    char padding3[0xc];
    unsigned char mode;
};
extern "C" void fn_71_E7A4(MetalGround* self) {
    if (self->m_collision != 0) {
        grCollisionJoint* joint = self->m_collision->getJoint(0);
        if (joint != 0) {
            grCollisionLine* line = joint->getLine(0);
            if (line != 0) {
                ((Flags*)((char*)joint + 0x48))->b = 3;
                unsigned short index = line->m_point0Index;
                unsigned char mode = self->mode;
                Vec2f* p;
                grCollData::VtxData* base = joint->m_vtxDatas;
                p = (Vec2f*)(base + index);
                base += (unsigned short)(index + 1);
                Vec2f* q = (Vec2f*)base;
                switch (mode) {
                case 7: {
                    State* s = self->state;
                    self->value = s->x - ((lbl_71_rodata_23C[0] - s->z) * (s->x - self->bounds->a));
                    p->m_x = self->value;
                    p->m_y = self->bounds->b;
                    q->m_x = self->value;
                    q->m_y = self->bounds->e;
                    break;
                }
                case 8: {
                    State* s = self->state;
                    self->value = s->x + ((lbl_71_rodata_23C[0] - s->z) * (self->bounds->d - s->x));
                    p->m_x = self->value;
                    p->m_y = self->bounds->e;
                    q->m_x = self->value;
                    q->m_y = self->bounds->b;
                    break;
                }
                }
                unsigned int enabled;
                if (lbl_71_rodata_238 == self->state->z)
                    enabled = 0;
                else
                    enabled = lbl_71_rodata_23C[0] != self->state->y;
                if (enabled != self->m_isEnableCollisionStatus) {
                    if (enabled == 1)
                        self->setEnableCollisionStatus(true);
                    else
                        self->setEnableCollisionStatus(false);
                }
            }
        }
    }
}
