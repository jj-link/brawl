#include <gf/gf_model.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <stdio.h>
#pragma force_active on

class Class_80454860 {
public:
    virtual void fn_80080AE4();
    virtual void fn_80080A64();
    virtual void fn_80080A68();
    virtual void fn_80080A7C();
    virtual void fn_80280C20();
    virtual void fn_80280CA4();
    virtual void fn_80280CAC(int, int);
};
struct ModelObject {
    char pad[0x10];
    Class_80454860* scene;
    gfModelAnimation* anim;
};
struct Inner {
    char pad[0xe8];
    void* mdl;
};
struct Outer {
    char pad[0xe8];
    Inner* inner;
};
struct Context {
    unsigned char flags;
    char pad[0xf];
    ModelObject* objects[10];
    char pad2[0x11c];
    Outer* outer;
    char pad3[0x28];
    int nodes[4][2];
    int values[16];
};
extern const unsigned char lbl_805A2398[4][2];
extern char lbl_8059E228[8];
extern const float lbl_805A2374;

extern "C" void fn_800DDB54(Context* self) {
    if ((self->flags >> 7) & 1) {
        nw4r::g3d::ResMdl mdl(self->outer->inner->mdl);
        char name[16];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++) {
                sprintf(name, lbl_8059E228, lbl_805A2398[i][j]);
                nw4r::g3d::ResNode node = mdl.GetResNode(name);
                self->nodes[i][j] = node.IsValid() ? node.ptr()->m_nodeIndex : 0;
            }
        }
        self->objects[0]->anim->setUpdateRate(lbl_805A2374);
        self->objects[0]->scene->fn_80280CAC(8, 1);
        for (int i = 1; i < 9; i++) {
            self->objects[i]->anim->setUpdateRate(lbl_805A2374);
            self->objects[i]->scene->fn_80280CAC(8, 1);
        }
        self->objects[9]->anim->setUpdateRate(lbl_805A2374);
        for (int i = 0; i < 16; i++) {
            self->values[i] = -1;
        }
    }
}
