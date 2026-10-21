#include <types.h>
#pragma force_active on

class MatColAnim {
public:
    virtual void f0();
};

class ScnMdl {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void BindAnmObj(MatColAnim*, s32);
};

class ModelAnimation {
public:
    char pad[0x18];
    MatColAnim* matColAnim;
};

extern "C" {
void bindMatColAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(ModelAnimation* self, ScnMdl* mdl) {
    if (self->matColAnim != 0)
        mdl->BindAnmObj(self->matColAnim, 2);
}
}
