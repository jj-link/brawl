#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    static void __vt(int, int);
};

extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

struct EvMgr {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void f5(s16 a, s16 b);
};

struct EvSys {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual u32 f8(s32 id);
};

class soStopModuleImpl {
public:
    char pad0[4];
    void* vtbl;
    s16 m8;
    s16 mA;
    s16 mC;
    ~soStopModuleImpl();
};

soStopModuleImpl::~soStopModuleImpl() {
    void* b = &vtbl;
    if (b != 0 && b != 0) {
        s16 id = m8;
        vtbl = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
        if (((EvSys*)getInstance__13soEventSystemFv())->f8(id) == 1) {
            EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), m8);
            mgr->f5(mA, mC);
        }
        mC = -1;
        m8 = -1;
    }
}
