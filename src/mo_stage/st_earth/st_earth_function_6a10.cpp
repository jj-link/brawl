#pragma force_active on
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>

extern "C" void fn_66_2BFC(void*);
extern "C" void __ct__14snd3DGeneratorFv(snd3DGenerator*);
extern "C" char lbl_66_data_1B40[];
extern "C" const float lbl_66_rodata_178;
extern "C" const float lbl_66_rodata_17C;

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

extern "C" char* fn_66_6A10(char* self) {
    fn_66_2BFC(self);
    *(char**)(self + 0x3c) = lbl_66_data_1B40;
    __ct__14snd3DGeneratorFv((snd3DGenerator*)(self + 0x1bc));
    Class_1F70* s = (Class_1F70*)(self + 0xd0);
    *(unsigned char*)(self + 0x158) = 3;
    *(unsigned char*)(self + 0x159) = 0;
    *(float*)(self + 0x15c) = lbl_66_rodata_178;
    *(unsigned char*)(self + 0x160) = 0;
    *(unsigned char*)(self + 0x161) = 0;
    *(float*)(self + 0x164) = lbl_66_rodata_178;
    *(float*)(self + 0x168) = lbl_66_rodata_178;
    *(float*)(self + 0x16c) = lbl_66_rodata_178;
    *(float*)(self + 0x170) = lbl_66_rodata_178;
    *(float*)(self + 0x174) = lbl_66_rodata_178;
    *(float*)(self + 0x178) = lbl_66_rodata_178;
    *(float*)(self + 0x17c) = lbl_66_rodata_178;
    *(float*)(self + 0x180) = lbl_66_rodata_178;
    *(float*)(self + 0x184) = lbl_66_rodata_178;
    *(float*)(self + 0x188) = lbl_66_rodata_178;
    *(float*)(self + 0x18c) = lbl_66_rodata_178;
    *(float*)(self + 0x190) = lbl_66_rodata_17C;
    *(float*)(self + 0x194) = lbl_66_rodata_178;
    *(float*)(self + 0x198) = lbl_66_rodata_178;
    *(unsigned char*)(self + 0x19c) = 8;
    *(float*)(self + 0x1a0) = lbl_66_rodata_178;
    *(unsigned char*)(self + 0x1a4) = 0;
    *(unsigned int*)(self + 0x1a8) = 0;
    *(unsigned int*)(self + 0x1ac) = 0;
    *(unsigned int*)(self + 0x1b0) = 0;
    *(unsigned int*)(self + 0x1b4) = 0;
    *(unsigned int*)(self + 0x1b8) = 0;
    *(int*)(self + 0x1c4) = -1;
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