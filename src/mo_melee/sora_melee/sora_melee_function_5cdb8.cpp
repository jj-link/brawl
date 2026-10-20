#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_27_B15D0(void* work);
extern "C" void fn_27_605AC(void* p);

extern "C" const float lbl_27_rodata_828;

struct Base {
    u32 a;
    u32 b;
};

struct Work : Base {
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
    u8 pad2[0x44 - 0x0C];
    u8 body[0x64 - 0x44];
    u8 body2[0x94 - 0x64];
    float f94;
    float f98;
    float f9c;
    u8 pada0[0xa8 - 0xa0];
    u8 flagA8;
};

extern "C" void fn_27_5CDB8(Work* self) {
    self->f8();
    self->flagA8 = 0;
    self->f94 = lbl_27_rodata_828;
    self->f98 = lbl_27_rodata_828;
    self->f9c = lbl_27_rodata_828;
    fn_27_B15D0((char*)self + 0x44);
    self->f9();
    fn_27_605AC((char*)self + 0x64);
}
