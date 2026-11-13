#include <types.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_joint.h>
#include <mt/mt_vector.h>

#pragma force_active on

struct Ground_base { char pad[0x3c]; };

class Ground : public Ground_base {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void getNodePosition(Vec3f* pos, u32 sceneModelIndex, u32 nodeIndex);

    char pad40[0xc];        // 0x40
    grCollision* coll;      // 0x4c
    char pad50[0x114];      // 0x50
    u8 state;               // 0x164
    char pad165[3];         // 0x165
    s32 nodeIdx[2];         // 0x168
};

struct JointWord {
    u32 a : 8;
    u32 b : 8;
    u32 c : 16;
};

extern "C" {
extern const float lbl_68_rodata_88[];

void fn_68_468C(void* arg) {
    Ground* self = (Ground*)arg;
    const float* c = lbl_68_rodata_88;

    if (self->coll == 0) {
        return;
    }
    grCollisionJoint* joint = self->coll->getJoint(0);
    if (joint == 0) {
        return;
    }
    float* mat = (float*)joint->m_vtxDatas;
    if (mat == 0) {
        return;
    }

    ((JointWord*)((char*)joint + 0x48))->b = 3;

    u8* l1 = (u8*)joint->getLine(1);
    if (l1 != 0) {
        l1[0x10] |= 0x80;
    }
    u8* l3 = (u8*)joint->getLine(3);
    if (l3 != 0) {
        l3[0x10] |= 0x80;
    }

    float f31 = c[8];
    u16 i;
    for (i = 0; i < 2; i++) {
        Vec3f tmp;
        self->getNodePosition(&tmp, 0, self->nodeIdx[i]);
        float* p = mat + i * 2;
        p[0] = tmp.m_x;
        p[1] = tmp.m_y;

        u16 idx;
        if (i == 0) {
            idx = 3;
        }
        if (i == 1) {
            idx = 1;
        }

        float f1;
        switch (self->state) {
        case 0:
            f1 = c[4];
            break;
        case 1:
            f1 = c[5];
            break;
        case 2:
            f1 = c[6];
            break;
        default:
            f1 = c[7];
            break;
        }

        float* q = p + idx * 2;
        q[0] = tmp.m_x;
        q[1] = tmp.m_y - f31 * f1;
    }
}
}
