#pragma force_active on

class Foo {
public:
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
    virtual void f10();
    virtual void f11();
};

extern "C" {
    extern const float lbl_27_rodata_7A0;
    extern void* lbl_27_data_6050[];

    Foo* fn_27_59FD4(Foo* self) {
        const float* pf = &lbl_27_rodata_7A0;
        int zero = 0;
        *(unsigned char*)((char*)self + 0x04) = (unsigned char)zero;
        *(void**)self = lbl_27_data_6050;
        *(unsigned char*)((char*)self + 0x88) = (unsigned char)zero;
        *(unsigned char*)((char*)self + 0x89) = (unsigned char)zero;
        self->f2();
        *(int*)((char*)self + 0x4C) = zero;
        *(float*)((char*)self + 0x40) = *pf;
        self->f8();
        *(float*)((char*)self + 0x1C) = *pf;
        *(float*)((char*)self + 0x18) = *pf;
        self->f11();
        *(float*)((char*)self + 0x34) = *pf;
        *(float*)((char*)self + 0x30) = *pf;
        self->f1();
        return self;
    }
}