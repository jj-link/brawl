#include <types.h>
#pragma force_active on

struct Vec3 {
    float x, y, z;
};

struct RotBuf {
    Vec3 v;
    RotBuf() {}
};

class PostureModule {
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual Vec3 getRot(int);
    virtual void setRot(const Vec3*, int);
};

class WorkModule {
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual int getInt(int);
};

struct ModuleEnumeration {
    unsigned char padding00[0x0C];
    PostureModule* posture;
    unsigned char padding10[0x54];
    WorkModule* work;
};

struct ModuleAccesser {
    unsigned char padding00[0xD8];
    ModuleEnumeration* modules;
};

struct MetaSoundB {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void setPos(Vec3* p, u32 flag);
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void update() = 0;
};

struct MetaSoundX {
    char pad[0x0c];
    MetaSoundB* b;
};

struct MetaSoundA {
    char pad[0xd8];
    MetaSoundX* x;
};

extern "C" {

Vec3* fn_111_CB38(Vec3* v, float x, float y, float z);

void fn_111_C9B8(void*, ModuleAccesser* accesser) {
    int count = accesser->modules->work->getInt(0x20000002);
    if (count <= 0) {
        PostureModule* posture = accesser->modules->posture;
        Vec3 rotFirst;
        posture->setRot(
            fn_111_CB38(&rotFirst, 0.0f, 0.0f, 0.0f),
            0);
    } else {
        float x = accesser->modules->posture->getRot(0).x;
        float numerator = 2.0f * x;
        float step = numerator / count;
        PostureModule* posture = accesser->modules->posture;
        posture->setRot(
            fn_111_CB38(&const_cast<Vec3&>(RotBuf().v), x - step,
                        posture->getRot(0).y,
                        posture->getRot(0).z),
            0);
    }
}

Vec3* fn_111_CB38(Vec3* v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

void fn_111_CB48(void* unused, MetaSoundA* a) {
    MetaSoundB* b1 = a->x->b;
    Vec3 pos;
    Vec3* p = fn_111_CB38(&pos, 0.0f, 0.0f, 0.0f);
    b1->setPos(p, 0);
    MetaSoundB* b2 = a->x->b;
    b2->update();
}
}
