#pragma force_active on
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>

struct Flags {
    unsigned int pad;
    unsigned int flags;
};

class Object_vptr_0 {
public:
    virtual void fn_73_C58C();
    virtual void fn_73_B9AC();
    virtual void fn_73_B9BC();
    virtual void slot3();
    virtual void fn_73_A784(int, int);
    virtual void slot5();
    Flags* data;
    unsigned int state;
};

extern "C" void fn_73_34A4(void*);
extern "C" void __ct__14snd3DGeneratorFv(snd3DGenerator*);
extern "C" char lbl_73_data_2B40[];
extern "C" const float lbl_73_rodata_78;

extern "C" char* fn_73_6DF0(char* self) {
    fn_73_34A4(self);
    *(char**)(self + 0x3c) = lbl_73_data_2B40;
    __ct__14snd3DGeneratorFv((snd3DGenerator*)(self + 0x2a8));
    float zero = lbl_73_rodata_78;
    Object_vptr_0* p = (Object_vptr_0*)(self + 0xd0);
    *(unsigned int*)(self + 0x294) = 0;
    *(float*)(self + 0x298) = zero;
    *(float*)(self + 0x29c) = zero;
    *(float*)(self + 0x2a0) = zero;
    *(float*)(self + 0x2a4) = zero;
    if (!p) return self;
    p->slot5();
    p->state = 1;
    p->fn_73_A784(0, 15);
    p->data->flags |= 1;
    p->data->flags |= 2;
    *(int*)(self + 0x2b0) = -1;
    *(int*)(self + 0x2b4) = -1;
    return self;
}