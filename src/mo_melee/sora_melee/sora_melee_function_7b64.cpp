#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;
template <class T>
struct soEventObserver {
    static void __vt(int, int);
};

extern "C" {
extern char __vt__17soModelModuleImpl[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
void* __dt__19soModelModuleSimpleFv(void*, short);
void* fn_8015C1B0(void*, void*);
void fn_8015C144(void*, void*);
void fn_27_100F8(void*, int);
void fn_27_1000C(void*, int);
void fn_27_FEE4(void*, int);
}

struct IEvSys {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32 f6(s32 id);
};
struct IEvMgr {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(s16 a, s16 b);
};

struct V {
    void* a;
    int b;
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9();
};

struct Obj {
    void* vt0;
    char pad4[4];
    char* vt8;
    char padC[8];
    void* vt14;
    s16 m18;
    s16 m1a;
    s16 m1c;
    char pad1e[2];
    void* vt20;
    char pad24[8];
    char m2c[8];
    char m34[8];
    char m3c[8];
    u16 m44;
    char pad46[0x52];
    char m98[4];
};

extern "C" Obj* __dt__17soModelModuleImplFv(Obj* p, s32 flag) {
    if (p) {
        p->vt8 = __vt__17soModelModuleImpl;
        p->vt0 = __vt__17soModelModuleImpl + 8;
        p->vt14 = __vt__17soModelModuleImpl + 0x154;
        p->vt20 = __vt__17soModelModuleImpl + 0x168;
        ((V*)p)->f9();
        while (p->m44 != 0) {
            fn_8015C144(p->m3c, fn_8015C1B0(p->m3c, 0));
        }
        fn_27_100F8(p->m98, -1);
        fn_27_1000C(p->m34, -1);
        fn_27_FEE4(p->m2c, -1);
        if (&p->vt14 && &p->vt14) {
            s16 id = p->m18;
            p->vt14 = (void*)&soEventObserver<soAnimCmdEventObserver>::__vt;
            if (((IEvSys*)getInstance__13soEventSystemFv())->f6(id) == 1) {
                IEvMgr* mgr = (IEvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m18);
                mgr->f3(p->m1a, p->m1c);
            }
            p->m1c = -1;
            p->m18 = -1;
        }
        __dt__19soModelModuleSimpleFv(p, 0);
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}
