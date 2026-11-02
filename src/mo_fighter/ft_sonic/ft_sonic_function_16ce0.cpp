#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" void fn_27_1D9FF8(void*);
extern const float lbl_123_rodata_88;

namespace {
struct Target {
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual int s6(unsigned long);
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void call15(float, unsigned long);
    virtual void s16();
    virtual void s17();
    virtual int s18();
    virtual int s19(unsigned long);
    virtual void s20(unsigned long);
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40(unsigned long, float);
};

struct Enumeration {
    unsigned char pad0[0x64];
    Target* workManage;
    unsigned char pad1[0x8];
    Target* status;
    unsigned char pad2[0x14];
    Target* effect;
};

struct Accesser {
    unsigned char pad[0xD8];
    Enumeration* enumeration;
};

struct Fighter {
    unsigned char pad[0x60];
    Accesser* accesser;
};
}

extern "C" void fn_123_16CE0(Fighter* self) {
    fn_27_1D9FF8(self);
    self->accesser->enumeration->workManage->call15(lbl_123_rodata_88, 0x11000001);
    if (self->accesser->enumeration->workManage->s19(0x12000003) == 0) {
        if (self->accesser->enumeration->status->s18() == 1) {
            int diff;
            Target* work;
            Accesser* acc = self->accesser;
            work = acc->enumeration->workManage;
            diff = soValueAccesser::getConstantInt((soModuleAccesser*)acc, 0x5dc1, 0) -
                   soValueAccesser::getConstantInt((soModuleAccesser*)acc, 0x5dc0, 0);
            if (work->s6(0x20000000) <= diff) {
                self->accesser->enumeration->workManage->s20(0x12000003);
                self->accesser->enumeration->effect->s40(0, lbl_123_rodata_88);
            }
        }
    }
}
