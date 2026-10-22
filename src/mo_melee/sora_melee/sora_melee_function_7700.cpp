#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <typename T>
class soEventObserver {
public:
    static void __vt(int, int);
    void* vptr;
    s16 m4;
    s16 m6;
    s16 m8;
};

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

struct Sys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual u32 v6(s16);
};

struct Mgr {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3(s16, s16);
};

extern "C" void* fn_27_7700(void* p, s32 flag) {
    if (p) {
        soEventObserver<soAnimCmdEventObserver>* obj = (soEventObserver<soAnimCmdEventObserver>*)p;
        s16 id = obj->m4;
        obj->vptr = (void*)&soEventObserver<soAnimCmdEventObserver>::__vt;
        if (((Sys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
            ((Mgr*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), obj->m4))->m3(obj->m6, obj->m8);
        }
        obj->m8 = -1;
        obj->m4 = -1;
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
