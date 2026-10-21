#include <types.h>
#pragma force_active on

class Base {
public:
    int a;
    int b;
};

class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual s32 vf3();
};

class Self : public Base {
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
    virtual void vf17(s32);
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
    virtual void vf39(s32);
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58(s32, f32);

    char pad[0x28];
    Inner* inner;
    char pad2[0xC];
    u8 flags;
};

extern const f32 lbl_27_rodata_320;

extern "C" void fn_27_10A4C(Self* self) {
    self->vf17(1);
    self->vf39(3);
    self->flags = (self->flags & 0xFFFFFF3F) | 0x20;
    s32 n = self->inner->vf3();
    for (s32 i = 0; i < n; i++) {
        self->vf58(i, lbl_27_rodata_320);
    }
}
