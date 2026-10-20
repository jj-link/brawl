#include <types.h>
#pragma force_active on

struct Vec3 {
    float x, y, z;
};

extern "C" Vec3* fn_111_CB38(Vec3* v, float x, float y, float z);
extern "C" const float lbl_111_rodata_20;

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

extern "C" void fn_111_CB48(void* unused, MetaSoundA* a) {
    MetaSoundB* b1 = a->x->b;
    Vec3 pos;
    Vec3* p = fn_111_CB38(&pos, lbl_111_rodata_20, lbl_111_rodata_20, lbl_111_rodata_20);
    b1->setPos(p, 0);
    MetaSoundB* b2 = a->x->b;
    b2->update();
}
