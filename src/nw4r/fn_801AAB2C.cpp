#pragma force_active on
#include <nw4r/math/math_types.h>

extern "C" void fn_801EC158(void*);
extern "C" char lbl_804662B0[];
extern "C" const float lbl_805A33E0;

struct Obj {
    void* vtbl;
    unsigned int field4;
    void* owner;
    char matrices[0x90];
    nw4r::math::VEC3 v9c, va8, vb4, vc0;
    unsigned int flags;
    unsigned char d0, d1, d2, d3;
    void* d4;
    unsigned char d8, d9;
    unsigned short da;
};

extern "C" Obj* fn_801AAB2C(Obj* p, void* owner) {
    p->field4 = 0;
    p->owner = owner;
    p->vtbl = lbl_804662B0;
    p->flags = 0;
    p->d0 = 0x80;
    p->d1 = 0x80;
    p->d2 = 0;
    p->d3 = 0;
    p->d4 = 0;
    p->d8 = 0;
    p->d9 = 0;
    p->da = 0;
    p->flags |= 0x80000000;
    fn_801EC158(p->matrices);
    fn_801EC158(p->matrices + 0x30);
    fn_801EC158(p->matrices + 0x60);
    p->v9c = nw4r::math::VEC3(lbl_805A33E0, lbl_805A33E0, lbl_805A33E0);
    p->va8 = nw4r::math::VEC3(lbl_805A33E0, lbl_805A33E0, lbl_805A33E0);
    p->vb4 = nw4r::math::VEC3(lbl_805A33E0, lbl_805A33E0, lbl_805A33E0);
    p->vc0 = nw4r::math::VEC3(lbl_805A33E0, lbl_805A33E0, lbl_805A33E0);
    return p;
}
