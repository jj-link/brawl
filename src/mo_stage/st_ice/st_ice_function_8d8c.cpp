#pragma force_active on
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>

extern "C" void fn_62_2C84(void*);
extern "C" void __ct__14snd3DGeneratorFv(snd3DGenerator*);
extern "C" char lbl_62_data_27A0[];
extern "C" const float lbl_62_rodata_F8;

class Class_1890 {
public:
    virtual void fn_62_79D0();
    virtual void fn_62_6DF0();
    virtual void fn_62_6E00();
    virtual void fn_62_6134();
    virtual void fn_62_5E28(int, int);
    char* p4;
    int f8;
};

class Class_2C60 {
public:
    virtual void fn_62_CA3C();
    virtual void fn_62_BF04();
    virtual void fn_62_BF14();
    virtual void fn_62_A624();
    virtual void fn_62_A3AC(int, int);
};

class Class_4768 {
public:
    virtual void fn_62_79D0();
    virtual void fn_62_6DF0();
    virtual void fn_62_6E00();
    virtual void fn_62_F038();
    virtual void fn_62_5E28(int, int);
};

extern "C" char* fn_62_8D8C(char* self) {
    fn_62_2C84(self);
    *(char**)(self + 0x3c) = lbl_62_data_27A0;
    __ct__14snd3DGeneratorFv((snd3DGenerator*)(self + 0x190));

    float zero = lbl_62_rodata_F8;
    Class_1890* s = (Class_1890*)(self + 0xd0);
    *(unsigned int*)(self + 0x160) = 0;
    *(float*)(self + 0x158) = zero;
    *(float*)(self + 0x15c) = zero;
    *(float*)(self + 0x164) = zero;
    *(float*)(self + 0x168) = zero;
    *(float*)(self + 0x16c) = zero;
    *(float*)(self + 0x170) = zero;
    *(float*)(self + 0x174) = zero;
    *(unsigned char*)(self + 0x178) = 0;
    *(unsigned int*)(self + 0x17c) = 0;
    *(unsigned int*)(self + 0x180) = 0;
    *(unsigned int*)(self + 0x184) = 0;
    *(unsigned int*)(self + 0x188) = 0;
    *(unsigned int*)(self + 0x18c) = 0;
    if (s == 0) return self;
    s->f8 = 1;
    s->fn_62_5E28(0, 15);
    char* p = s->p4;
    *(unsigned int*)(p + 4) |= 8;
    return self;
}
