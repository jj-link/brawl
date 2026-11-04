#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on
extern float lbl_27_rodata_2300;
class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual Vec3f v14(int);
    virtual void v15(Vec3f*, int);
    virtual int v16();
};
struct Holder {
    char pad0[0xc];
    VObj* mC;
    char pad1[0x54];
    VObj* m64;
    char pad2[8];
    VObj* m70;
};
struct Obj {
    char pad[0xd8];
    Holder* d8;
};
extern "C" void fn_27_177BAC(void*, Obj*);
extern "C" void fn_27_177CE4(void*, Obj*);
extern "C" void fn_27_177A44(void*, Obj*);
extern "C" void fn_27_178030(void*, Obj*);
extern "C" void fn_27_17496C(void*, Obj*, int);
extern "C" void fn_27_17732C(void* self, Obj* obj, int arg) {
    switch (obj->d8->m70->v16()) {
    case 0x92: fn_27_177BAC(self, obj); break;
    case 0x93: fn_27_177CE4(self, obj); break;
    case 0x94: fn_27_177A44(self, obj); break;
    case 0x95: fn_27_178030(self, obj); break;
    }
    Vec3f pos = obj->d8->mC->v14(0);
    pos.m_y = lbl_27_rodata_2300;
    obj->d8->mC->v15(&pos, 0);
    VObj* work = obj->d8->m64;
    int val = soValueAccesser::getConstantInt((soModuleAccesser*)obj, 0x59e1, 0);
    work->v5(val, 0x10000011);
    fn_27_17496C(self, obj, arg);
}