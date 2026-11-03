#pragma force_active on
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <new>

extern "C" void fn_66_2BFC(void*);
extern "C" void __ct__14snd3DGeneratorFv(snd3DGenerator*);
extern "C" char lbl_66_data_3108[];
extern "C" const float lbl_66_rodata_1E0[];

class Class_1F70 {
public:
    virtual void fn_66_CA8C();
    virtual void fn_66_BF54();
    virtual void fn_66_BF64();
    virtual void fn_66_A44C();
    virtual void fn_66_A094(int, int);
    char* p4;
    int f8;
};

class Class_2068 {
public:
    virtual void fn_66_D8D4();
    virtual void fn_66_CCF4();
    virtual void fn_66_CD04();
    virtual void fn_66_A4E4();
    virtual void fn_66_A060(int, int);
};

class Class_3340 {
public:
    virtual void fn_66_CA8C();
    virtual void fn_66_BF54();
    virtual void fn_66_BF64();
    virtual void fn_66_11350();
    virtual void fn_66_A094(int, int);
};

extern "C" char* fn_66_FC04(char* self) {
    fn_66_2BFC(self);
    *(char**)(self + 0x3c) = lbl_66_data_3108;
    __ct__14snd3DGeneratorFv((snd3DGenerator*)(self + 0x180));
    float zero = lbl_66_rodata_1E0[0];
    Class_1F70* s = (Class_1F70*)(self + 0xd0);
    *(unsigned char*)(self + 0x158) = 6;
    *(float*)(self + 0x15c) = zero;
    *(unsigned int*)(self + 0x164) = 0;
    *(unsigned char*)(self + 0x168) = 0;
    *(unsigned int*)(self + 0x16c) = 0;
    *(unsigned int*)(self + 0x170) = 0;
    *(unsigned int*)(self + 0x174) = 0;
    *(unsigned int*)(self + 0x178) = 0;
    *(unsigned int*)(self + 0x17c) = 0;
    if (s == 0) return self;
    s->f8 = 1;
    s->fn_66_A094(0, 15);
    {
        char* p = s->p4;
        *(unsigned int*)(p + 4) |= 1;
    }
    {
        char* p = s->p4;
        *(unsigned int*)(p + 4) |= 2;
    }
    return self;
}
