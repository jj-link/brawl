#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void* fn_113_A3D8();
extern "C" unsigned int fn_27_5BE80(void*);
extern "C" void fn_113_BCB0(void*);
extern "C" void fn_113_24D94(void*);
extern "C" void fn_27_12DCA8(void*);
extern "C" void fn_113_C024(void*);

class Class_7FE8 {
public:
    virtual void fn_113_80F4();
    virtual void fn_113_1552C();
    virtual void fn_113_1C084();
    virtual void fn_113_1C07C();
    virtual void fn_113_1C074();
    virtual void fn_113_1C06C();
    virtual void fn_113_1C064();
    virtual void fn_113_1C05C();
    virtual void fn_113_1C054();
    virtual void fn_113_1C04C();
    virtual void fn_113_1C044();
    virtual void fn_113_1C03C();
    virtual void fn_113_1C034();
    virtual void fn_113_1C02C();
    virtual void fn_113_1BFDC();
    virtual void fn_113_1C024();
    virtual void fn_113_1C014();
    virtual unsigned int fn_113_1C004(unsigned int);
    virtual void fn_113_1BFF4();
    virtual void fn_113_1BFE4(unsigned int);
};

extern "C" void fn_113_A2A4(char* self) {
    unsigned int active = 0;
    if (fn_27_5BE80(fn_113_A3D8()) == 1U) {
        if ((*(soModuleAccesser**)(self + 0x60))->getStopModule().isStop() == 0) {
            if ((*(soModuleAccesser**)(self + 0x60))->getSlowModule().isSkip() == 0) {
                active = 1;
            }
        }
    }
    if (active == 1U) {
        fn_113_BCB0(self);
        if ((*(soModuleAccesser**)(self + 0x60))->getStatusModule().getStatusKind() == 0x115) {
            if (((Class_7FE8*)&(*(soModuleAccesser**)(self + 0x60))->getWorkManageModule())->fn_113_1C004(0x22000010) == 1U) {
                fn_113_24D94(self + 0x1FD08);
                ((Class_7FE8*)&(*(soModuleAccesser**)(self + 0x60))->getWorkManageModule())->fn_113_1BFE4(0x22000010);
            }
        }
    }
    fn_27_12DCA8(self);
    if (active == 1U) {
        fn_113_C024(self);
    }
}
