#include <so/so_module_accesser.h>
#pragma force_active on

struct WM {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual int offFlag(unsigned);
    virtual void f18();
    virtual void turnOffFlag(unsigned);
};

extern "C" {
void* fn_98_9890(soModuleAccesser* accesser);
void fn_98_183E4(void*, soCollisionAttackModule* attack);
void fn_98_17F24(void*, int);

void fn_98_113A8(soModuleAccesser* accesser) {
    WM* work = reinterpret_cast<WM*>(accesser->m_enumerationStart->m_workManageModule);
    void* owner = fn_98_9890(accesser);
    if (owner) {
        if (work->offFlag(0x22000012)) {
            fn_98_183E4(owner, accesser->m_enumerationStart->m_collisionAttackModule);
            fn_98_17F24(owner, 0);
            work->turnOffFlag(0x22000012);
        }
    }
}
}
