#pragma force_active on

#include <types.h>

struct MotionModule {
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void setFrame(float);
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual float getEndFrame(u32);
};

struct ControllerModule {
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual float getStickX();
};

struct WorkModule {
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual float getFloat(u32);
    virtual void setFloat(float, u32);
};

struct Enumeration {
    char pad0[8];
    MotionModule* motion;
    char pad1[0x50];
    ControllerModule* controller;
    char pad2[4];
    WorkModule* work;
};

struct Accesser {
    char pad[0xD8];
    Enumeration* enumeration;
};

extern "C" {
extern const float lbl_112_rodata_20;
extern const float lbl_112_data_6A48;
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, u32, u32);
void fn_112_E3CC(void*, Accesser*);
}

extern "C" void fn_112_E278(void* self, Accesser* accesser) {
    MotionModule* motion = accesser->enumeration->motion;
    WorkModule* work = accesser->enumeration->work;

    float a = work->getFloat(0x21000004);
    float b = accesser->enumeration->controller->getStickX();
    if (b < lbl_112_rodata_20) {
        b = lbl_112_rodata_20;
    } else {
        float c =
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xfb8, 0) /
            lbl_112_data_6A48;
        if (b > c)
            b = c;
    }
    b = a + (b - a) * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                         accesser, 0xfb9, 0);
    motion->setFrame(b * motion->getEndFrame(0x1eb));
    work->setFloat(b, 0x21000004);
    fn_112_E3CC(self, accesser);
}
