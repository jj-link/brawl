#pragma force_active on
extern "C" void fn_74_264C(void*);
extern "C" void fn_8009ED40(void*, int, int);
extern "C" void fn_8009F1FC(void*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" char lbl_74_data_B38[];
extern "C" const float lbl_74_rodata_B0;
extern "C" const float lbl_74_rodata_B4;

class Class_1E10 {
public:
    virtual void fn_74_9ADC();
    virtual void fn_74_8FA4();
    virtual void fn_74_8FB4();
    virtual void fn_74_6B18();
    virtual void fn_74_6758();
};

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void call(int, int);
    char* p4;
    unsigned int f8;
};

struct Flags {
    unsigned int mode : 3;
    unsigned int rest : 29;
};

extern "C" char* fn_74_3060(char* self) {
    fn_74_264C(self);
    *(char**)(self + 0x3c) = lbl_74_data_B38;
    fn_8009ED40(self + 0x174, 0, 1);
    __ct__14snd3DGeneratorFv(self + 0x1f8);
    *(unsigned char*)(self + 0x158) = 0;
    *(float*)(self + 0x15c) = lbl_74_rodata_B0;
    *(float*)(self + 0x160) = lbl_74_rodata_B0;
    *(float*)(self + 0x164) = lbl_74_rodata_B4;
    *(float*)(self + 0x168) = lbl_74_rodata_B4;
    *(float*)(self + 0x16c) = lbl_74_rodata_B4;
    *(unsigned int*)(self + 0x170) = 0;
    fn_8009F1FC(self + 0x174);
    ((Flags*)(self + 0x17c))->mode = 1;
    Sub* s = (Sub*)(self + 0xd0);
    if (s == 0) {
        return self;
    }
    s->f8 = 1;
    s->call(0, 15);
    *(unsigned int*)(s->p4 + 4) |= 4;
    return self;
}
