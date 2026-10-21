#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(s32 a, s32 b, float f1, float f2, float f3);
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
    virtual void vf44();
    virtual s32 vf45();
    u8 pad[0x40];
    s32 m_44;
};

extern "C" void fn_27_43044(Obj* self, s32 a, s32 b, float f1, float f2, float f3) {
    s32 counter = 0;
    self->m_44 = a;
    while (counter < self->vf45()) {
        self->vf2(b, counter, f1, f2, f3);
        counter++;
    }
}
