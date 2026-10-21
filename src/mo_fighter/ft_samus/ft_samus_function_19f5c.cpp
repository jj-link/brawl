#include <so/so_module_accesser.h>
#pragma force_active on

class SamusWorkView {
public:
    virtual ~SamusWorkView();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(int);
};

class SamusPostureView {
public:
    virtual ~SamusPostureView();
    virtual void p01();
    virtual void p02();
    virtual void p03();
    virtual void p04();
    virtual void p05();
    virtual void p06();
    virtual void p07();
    virtual void p08();
    virtual void p09();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
};

extern "C" void fn_94_19F5C(int, soModuleAccesser* moduleAccesser, int statusKind) {
    if (statusKind == 0x115 || (unsigned)(statusKind - 0x11a) <= 5u)
        return;

    soWorkManageModule* work = &moduleAccesser->getWorkManageModule();
    soPostureModule* post = &moduleAccesser->getPostureModule();
    if (((SamusWorkView*)work)->v17(0x22000017) != 0) {
        ((SamusPostureView*)post)->p11();
        ((SamusPostureView*)post)->p19();
    }
}
