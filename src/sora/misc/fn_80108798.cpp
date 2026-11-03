#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

class ObjVt13 {
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
    virtual void v11();
    virtual void v12();
    virtual void v13(int arg);
};

class AnmVt8 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(float f);
};

struct Self {
    char pad0[0x4];
    MuObject* m4;
    MuObject* m8;
    char pad1[0xc];
    int m18;
    int m1c;
};

extern "C" {
extern void* lbl_805A032C;
extern float lbl_805A27F8;

void fn_80108798(Self* self, s32 arg1) {
    MuObject* obj;
    int val;
    if (arg1 == 0) {
        val = self->m18;
    } else {
        val = self->m1c;
    }
    ((ObjVt13*)lbl_805A032C)->v13(val);
    if (arg1 == 0) {
        obj = self->m4;
    } else {
        obj = self->m8;
    }
    obj->setFrameNode(lbl_805A27F8);
    ((AnmVt8*)obj->m_modelAnim->m_anmObjChrRes)->v8(lbl_805A27F8);
    obj->setFrameMatCol(lbl_805A27F8);
    ((AnmVt8*)obj->m_modelAnim->m_anmObjMatClrRes)->v8(lbl_805A27F8);
}
}
