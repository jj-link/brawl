#pragma force_active on
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
extern "C" void fn_70_6014(void*);
extern "C" void __ct__14snd3DGeneratorFv(snd3DGenerator*);
extern "C" char lbl_70_data_3360[];
extern "C" const float lbl_70_rodata_E8;
class Class_3790 {
public:
    virtual void fn_70_B644();
    virtual void fn_70_AB0C();
    virtual void fn_70_AB1C();
    virtual void fn_70_9164();
    virtual void fn_70_8EEC(int, int);
    char* p4;
    int f8;
};
extern "C" char* fn_70_6E1C(char* self) {
    fn_70_6014(self);
    *(char**)(self + 0x3c) = lbl_70_data_3360;
    __ct__14snd3DGeneratorFv((snd3DGenerator*)(self + 0x200));
    float zero = lbl_70_rodata_E8;
    Class_3790* s = (Class_3790*)(self + 0xd0);
    *(unsigned char*)(self + 0x1cc) = 4;
    *(unsigned int*)(self + 0x1e0) = 0;
    *(float*)(self + 0x1d0) = zero;
    *(float*)(self + 0x1d4) = zero;
    *(float*)(self + 0x1d8) = zero;
    *(float*)(self + 0x1dc) = zero;
    *(unsigned int*)(self + 0x1e4) = 0;
    *(unsigned char*)(self + 0x1e8) = 0;
    *(unsigned char*)(self + 0x1e9) = 0;
    *(unsigned char*)(self + 0x1ea) = 0;
    *(unsigned int*)(self + 0x1ec) = 0;
    *(unsigned int*)(self + 0x1f0) = 0;
    *(unsigned int*)(self + 0x1f4) = 0;
    *(unsigned int*)(self + 0x1f8) = 0;
    *(unsigned int*)(self + 0x1fc) = 0;
    if (s == 0) return self;
    s->f8 = 1;
    s->fn_70_8EEC(0, 15);
    char* p = s->p4;
    *(unsigned int*)(p + 4) |= 1;
    return self;
}