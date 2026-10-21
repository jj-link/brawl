#pragma force_active on
extern "C" void fn_74_264C(void*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" char lbl_74_data_2C10[];
extern "C" const float lbl_74_rodata_160[];

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v6(int, int);
    char* p4;
    int f8;
};

extern "C" char* fn_74_B510(char* self) {
    fn_74_264C(self);
    *(char**)(self + 0x3c) = lbl_74_data_2C10;
    __ct__14snd3DGeneratorFv(self + 0x174);

    float zero = lbl_74_rodata_160[0];
    *(unsigned char*)(self + 0x158) = 0;
    *(unsigned int*)(self + 0x15c) = 0;
    *(unsigned int*)(self + 0x160) = 0;
    *(unsigned int*)(self + 0x164) = 0;
    *(float*)(self + 0x168) = zero;
    *(float*)(self + 0x16c) = zero;
    *(unsigned int*)(self + 0x170) = 0;

    Sub* s = (Sub*)(self + 0xd0);
    if (s == 0) {
        return self;
    }
    s->f8 = 1;
    s->v6(0, 15);
    {
        char* p = s->p4;
        *(unsigned int*)(p + 0x4) |= 1;
    }
    {
        char* p = s->p4;
        *(unsigned int*)(p + 0x4) |= 2;
    }
    return self;
}
