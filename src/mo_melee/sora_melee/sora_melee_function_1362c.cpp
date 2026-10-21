#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_1180[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void* p);

struct Instance {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32 f6(s16);
};

struct Manager {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(s16, s16);
};

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
    s16 m8;
};

extern "C" void* fn_27_1362C(void* p, s32 flag) {
    if (p) {
        Obj* obj = (Obj*)p;
        s16 id = obj->m4;
        obj->vtbl = lbl_27_data_1180;
        u32 result = ((Instance*)getInstance__13soEventSystemFv())->f6(id);
        if (result == 1) {
            ((Manager*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), obj->m4))->f3(obj->m6, obj->m8);
        }
        obj->m8 = -1;
        obj->m4 = -1;
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
