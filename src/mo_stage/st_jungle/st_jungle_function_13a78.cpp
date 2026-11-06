#pragma force_active on
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>

extern "C" void fn_51_2838(void*, const char*);
extern "C" void __ct__14snd3DGeneratorFv(snd3DGenerator*);
extern "C" char lbl_51_data_88B0[];
extern "C" const float lbl_51_rodata_238;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(int, int);
    char* p4;
    int f8;
};

extern "C" char* fn_51_13A78(char* self, const char* task) {
    fn_51_2838(self, task);
    *(char**)(self + 0x3c) = lbl_51_data_88B0;
    __ct__14snd3DGeneratorFv((snd3DGenerator*)(self + 0x194));

    float zero = lbl_51_rodata_238;
    Object_vptr_0* s = (Object_vptr_0*)(self + 0xd0);
    *(unsigned int*)(self + 0x158) = 0;
    *(unsigned int*)(self + 0x15c) = 0;
    *(unsigned int*)(self + 0x160) = 0;
    *(float*)(self + 0x164) = zero;
    *(float*)(self + 0x168) = zero;
    *(float*)(self + 0x16c) = zero;
    *(float*)(self + 0x170) = zero;
    *(float*)(self + 0x174) = zero;
    *(float*)(self + 0x178) = zero;
    *(unsigned char*)(self + 0x17c) = 0;
    *(unsigned int*)(self + 0x180) = 0;
    *(unsigned int*)(self + 0x184) = 0;
    *(unsigned int*)(self + 0x188) = 0;
    *(unsigned int*)(self + 0x18c) = 0;
    *(unsigned int*)(self + 0x190) = 0;
    if (s == 0) return self;
    s->f8 = 1;
    s->slot4(0, 15);
    {
        char* p = s->p4;
        *(unsigned int*)(p + 4) |= 1;
    }
    {
        char* p = s->p4;
        *(unsigned int*)(p + 4) |= 0x10;
    }
    return self;
}