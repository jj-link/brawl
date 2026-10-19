#include <types.h>
#pragma force_active on

extern "C" const float lbl_124_rodata_20;

class ftVirtA {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual float vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
};

class ftPad3c {
public:
    char pad[0x3c];
};

class ftVirtM : public ftPad3c {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
};

extern "C" void fn_124_C38C(void* unused, u8* obj) {
    ftVirtA* inner = *(ftVirtA**)(*(u8**)(obj + 0xd8) + 0xc);
    float value = inner->vf9();
    if (lbl_124_rodata_20 == value) {
        ftVirtA* inner2 = *(ftVirtA**)(*(u8**)(obj + 0xd8) + 0xc);
        inner2->vf20();
        ftVirtM* member = *(ftVirtM**)(obj + 8);
        member->vf43();
    }
}
