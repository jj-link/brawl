#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_5B30[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void* p);

struct SoEventSystem {
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3();
    virtual void fn4();
    virtual void fn5();
    virtual u32 fn6(s16);
};

struct EventManager {
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3(s16, s16);
};

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
    s16 m8;
};

extern "C" void* fn_27_56534(void* p, s32 flag) {
    if (p) {
        if (p) {
            s16 id = ((Obj*)p)->m4;
            *(void**)p = (void*)lbl_27_data_5B30;
            if (((SoEventSystem*)getInstance__13soEventSystemFv())->fn6(id) == 1) {
                ((EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), ((Obj*)p)->m4))
                    ->fn3(((Obj*)p)->m6, ((Obj*)p)->m8);
            }
            ((Obj*)p)->m8 = -1;
            ((Obj*)p)->m4 = -1;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
