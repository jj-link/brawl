#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
struct soEventObserver {
    static void __vt(int, int);
};

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_5C674(void*, s32);
void __dl__FPv(void*);
}

struct EvSys {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32 f6(s16);
};

struct EvMgr {
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3(s16, s16);
};

extern "C" void* fn_27_5BFA0(void* p, s32 flag) {
    if (p != nullptr) {
        if ((char*)p + 0x18 != 0 && (char*)p + 0x18 != 0) {
            char* pc = (char*)p;
            s16 id = *(s16*)(pc + 0x1C);
            *(void**)(pc + 0x18) = (void*)&soEventObserver<soAnimCmdEventObserver>::__vt;
            EvSys* sys = (EvSys*)getInstance__13soEventSystemFv();
            if (sys->f6(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)(pc + 0x1C));
                mgr->g3(*(s16*)(pc + 0x1E), *(s16*)(pc + 0x20));
            }
            *(s16*)(pc + 0x20) = -1;
            *(s16*)(pc + 0x1C) = -1;
        }
        fn_27_5C674(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
