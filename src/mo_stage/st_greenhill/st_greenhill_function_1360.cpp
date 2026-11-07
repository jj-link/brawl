#include <gr/ground.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_joint.h>
#include <types.h>
#pragma force_active on
#pragma push
#pragma opt_propagation off
extern "C" void fn_72_1360(Ground* self) {
    self->Ground::processAnim();
    if (*(Vec3f**)((char*)self + 0x158)) {
        self->getNodePosition(*(Vec3f**)((char*)self + 0x158), 0, "markerPosition01");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x158) + 1, 0, "markerPosition02");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x158) + 2, 0, "markerPosition03");
        self->getNodePosition(*(Vec3f**)((char*)self + 0x158) + 3, 0, "markerPosition04");
    }
}
#pragma pop
extern "C" void update__9grGimmickFf(void*, float);
class Base {
public:
    unsigned char padding[0x3C];
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void first(float);
    virtual void second(float);
};
class Object : public Base {
public:
    unsigned char padding1[0x88];
    unsigned char enabled;
};
extern "C" void fn_72_1430(Object* self, float deltaFrame)
{
    update__9grGimmickFf(self, deltaFrame);
    if (self->enabled) {
        self->first(deltaFrame);
        self->second(deltaFrame);
    }
}
struct StObject {
    char pad0[0x4C];
    grCollision* collision;
    char pad1[0x100];
    u8 flag150;
    char pad2[0x17];
    u32 nodeA;
    u32 nodeB;
    u32 nodeC;
    u32 nodeD;
    u32 nodeE;
    u32 nodeF;
    u32 nodeG;
    grCollisionJoint* joints[7];
};
extern "C" grCollisionJoint* getJoint__11grCollisionFUs(grCollision*, u32);
inline void setFlags(grCollisionJoint* joint) {
    joint->m_0x54_7 = 0;
    joint->m_0x54_4 = joint->m_0x54_7;
    joint->m_0x54_6 = joint->m_0x54_4;
}
extern "C" void fn_72_14A4(StObject* self) {
    grCollision* collision;
    u32 i;
    u32 count;
    grCollisionJoint* joint;

    if (self->joints[0] == 0 && self->flag150 != 0) {
        collision = self->collision;
        if (collision != 0) {
            for (i = 0, count = *(u16*)((char*)collision + 6); i != count; i++) {
                joint = getJoint__11grCollisionFUs(collision, i);
                if (joint != 0 && (void*)joint->m_ground == (void*)self) {
                    if (self->nodeB == joint->m_nodeIndex) {
                        self->joints[0] = joint;
                    } else if (self->nodeC == joint->m_nodeIndex) {
                        self->joints[1] = joint;
                    } else if (self->nodeD == joint->m_nodeIndex) {
                        self->joints[2] = joint;
                    } else if (self->nodeE == joint->m_nodeIndex) {
                        self->joints[3] = joint;
                    } else if (self->nodeF == joint->m_nodeIndex) {
                        self->joints[4] = joint;
                    } else if (self->nodeG == joint->m_nodeIndex) {
                        self->joints[5] = joint;
                    } else if (self->nodeA == joint->m_nodeIndex) {
                        self->joints[6] = joint;
                    }
                }
            }

            for (int j = 0; j < 6; j++) {
                if (self->joints[j] != 0) {
                    self->joints[j]->m_0x56_7 = 1;
                    setFlags(self->joints[j]);
                }
            }
        }
    }
}
struct Obj {
    char pad[0x52];
    unsigned short mask;
    unsigned char b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
};
struct Self : Ground {
    char pad[0x150 - 0x9c];
    unsigned char state;
    char pad2[11];
    unsigned char* data;
    unsigned long node[9];
    Obj *a, *b, *c, *d, *e, *f, *out;
};
#define ON(p) do { Obj* x = (p); x->b3 = 1; x->b1 = x->b3; } while (0)
#define OFF(p) do { Obj* x = (p); x->b0 = 0; x->b3 = x->b0; x->b1 = x->b3; } while (0)
extern "C" void fn_72_1674(Self* s) {
    if (s->data != 0) {
        switch ((int)s->state) {
        case 0:
            s->getNodeIndex(&s->node[0], 0, "DanmenBrk02");
            s->getNodeIndex(&s->node[1], 0, "DanmenBrk03");
            s->getNodeIndex(&s->node[2], 0, "GHcol_collision");
            s->getNodeIndex(&s->node[3], 0, "flower");
            s->getNodeIndex(&s->node[4], 0, "markerPosition01");
            s->getNodeIndex(&s->node[5], 0, "markerPosition02");
            s->getNodeIndex(&s->node[6], 0, "markerPosition03");
            s->getNodeIndex(&s->node[7], 0, "markerPosition04");
            s->getNodeIndex(&s->node[8], 0, "himawari\0\0\0\0\0\0\0");
            s->state = 1;
        case 1:
            if (s->a) {
                unsigned short mask = 0;
                if (s->data[0] == 1) {
                    if (s->data[1] != 1) { ON(s->c); } else { OFF(s->c); }
                    if (s->data[2] != 1) { ON(s->d); } else { OFF(s->d); }
                } else { OFF(s->c); OFF(s->d); }
                if (s->data[1] == 1) {
                    s->setNodeVisibility(true, 0, s->node[0], true, false);
                    ON(s->a);
                    if (s->data[0] != 1) { ON(s->b); } else { OFF(s->b); }
                } else {
                    s->setNodeVisibility(false, 0, s->node[0], true, false);
                    mask |= 0x4000;
                    OFF(s->a); OFF(s->b);
                }
                if (s->data[2] == 1) {
                    s->setNodeVisibility(true, 0, s->node[1], true, false);
                    if (s->data[0] != 1) { ON(s->e); } else { OFF(s->e); }
                    ON(s->f);
                } else {
                    s->setNodeVisibility(false, 0, s->node[1], true, false);
                    mask |= 0x2000;
                    OFF(s->e); OFF(s->f);
                }
                s->out->mask = mask;
            }
            break;
        }
    }
}
