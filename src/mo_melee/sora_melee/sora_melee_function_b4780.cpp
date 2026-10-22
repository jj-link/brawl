#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    static void __vt(int, int);
};

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, s32);
void __dl__FPv(void*);
}

struct EvSys {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual u32 check(s16 id);
};

struct EvMgr {
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void erase(s16 a, s16 b);
};

struct Obj {
    void* vtbl0;
    void* vtbl4;
    s16 m8;
    s16 mA;
    s16 mC;
};

extern "C" Obj* fn_27_B4780(Obj* p, s32 flag) {
    if (p) {
        if (((char*)p + 4 != nullptr) && ((char*)p + 4 != nullptr)) {
            s16 id = p->m8;
            p->vtbl4 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            if (((EvSys*)getInstance__13soEventSystemFv())->check(id) == 1) {
                ((EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(),
                        p->m8))->erase(p->mA, p->mC);
            }
            p->mC = -1;
            p->m8 = -1;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
