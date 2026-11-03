#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

extern "C" {
void fn_27_89DAC(int, soModuleAccesser*);
void fn_124_C38C(void*, void*);
extern const float lbl_124_rodata_18;
extern const float lbl_124_rodata_1C;
}

struct GroundBase { char pad[0x8]; };

class GroundMod : public GroundBase {
public:
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3c();
    virtual void f40();
    virtual void f44();
    virtual void f48();
    virtual void f4c();
    virtual void f50();
    virtual void f54();
    virtual void f58();
    virtual void f5c();
    virtual void f60();
    virtual void f64();
    virtual void f68();
    virtual void f6c();
    virtual void f70();
    virtual void f74();
    virtual void f78();
    virtual void f7c();
    virtual void f80();
    virtual void f84();
    virtual void f88();
    virtual void f8c();
    virtual void f90();
    virtual void f94();
    virtual void f98();
    virtual void f9c();
    virtual void fa0();
    virtual void fa4();
    virtual void fa8();
    virtual void fac();
    virtual void fb0();
    virtual void fb4();
    virtual void fb8();
    virtual void fbc();
    virtual void fc0();
    virtual void fc4();
    virtual void fc8();
    virtual void fcc();
    virtual void fd0();
    virtual void fd4();
    virtual void fd8();
    virtual void fdc();
    virtual void fe0();
    virtual void fe4();
    virtual void fe8();
    virtual void fec();
    virtual void ff0();
    virtual void ff4();
    virtual void ff8();
    virtual void ffc();
    virtual void f100();
    virtual void f104();
    virtual void f108();
    virtual void f10c();
    virtual void f110();
    virtual void f114();
    virtual void f118();
    virtual void f11c();
    virtual void f120();
    virtual void f124();
    virtual void f128();
    virtual void f12c();
    virtual void f130();
    virtual void f134();
    virtual void f138();
    virtual void f13c();
    virtual void f140();
    virtual void f144();
    virtual void f148();
    virtual void f14c();
    virtual void f150();
    virtual void f154();
    virtual void f158();
    virtual void f15c();
    virtual void f160();
    virtual void f164();
    virtual void f168();
    virtual void f16c();
    virtual void f170();
    virtual void f174();
    virtual void f178();
    virtual void f17c();
    virtual void f180();
    virtual void f184();
    virtual void f188();
    virtual void f18c();
    virtual void f190();
    virtual void f194();
    virtual void f198();
    virtual void f19c();
    virtual void f1a0();
    virtual void f1a4();
    virtual void f1a8();
    virtual void f1ac(int, int, int);
};

extern "C" void fn_124_BCF4(void* arg0, soModuleAccesser* accesser) {
    fn_27_89DAC(3, accesser);
    fn_27_89DAC(1, accesser);
    fn_27_89DAC(2, accesser);
    fn_27_89DAC(4, accesser);
    fn_27_89DAC(0, accesser);

    accesser->getWorkManageModule().offFlag(0x22000011);
    accesser->getWorkManageModule().setFloat(lbl_124_rodata_18, 0x21000004);

    int kind = accesser->getStatusModule().getStatusKind();
    switch (kind) {
    case 0x116:
        accesser->getWorkManageModule().setFloat(lbl_124_rodata_1C, 0x21000006);
        accesser->getWorkManageModule().onFlag(0x22000012);
        break;
    case 0x11e:
        fn_124_C38C(arg0, accesser);
        break;
    }

    GroundMod* g = (GroundMod*)(&accesser->getGroundModule());
    g->f1ac(3, 1, 0);
}
