#pragma force_active on

extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" char lbl_56_data_3F0[];
extern const float lbl_56_rodata_40;

class Object {
public:
    char padding[0x3C];

    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
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
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
};

extern "C" Object* fn_56_F90(Object* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(char**)((char*)self + 0x3C) = lbl_56_data_3F0;
    *(int*)((char*)self + 0x168) = 0;
    *(int*)((char*)self + 0x150) = 0;
    *(unsigned char*)((char*)self + 0x154) = 4;
    *(float*)((char*)self + 0x158) = lbl_56_rodata_40;
    *(unsigned char*)((char*)self + 0x15C) = 8;
    *(float*)((char*)self + 0x160) = lbl_56_rodata_40;
    *(int*)((char*)self + 0x164) = 0;
    *(int*)((char*)self + 0x16C) = 0;
    self->f26();
    return self;
}
