#include <so/so_module_accesser.h>
#pragma force_active on

struct LinkNodeModule {
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
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void act(int);
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual bool check(int);
};

#define LINK_MODULE(p) \
    (*reinterpret_cast<LinkNodeModule**>( \
        reinterpret_cast<char*>( \
            const_cast<soModuleEnumeration*>((p)->m_enumerationStart)) + 0x88))

extern "C" void fn_115_12CD8(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x2200001A)) {
        int value = accesser->getWorkManageModule().getInt(0x20000001);
        if (LINK_MODULE(accesser)->check(value)) {
            LINK_MODULE(accesser)->act(value);
        }
        accesser->getWorkManageModule().offFlag(0x2200001A);
    }

    if (accesser->getWorkManageModule().isFlag(0x2200001B)) {
        int value = accesser->getWorkManageModule().getInt(0x20000002);
        if (LINK_MODULE(accesser)->check(value)) {
            LINK_MODULE(accesser)->act(value);
        }
        accesser->getWorkManageModule().offFlag(0x2200001B);
    }
}
