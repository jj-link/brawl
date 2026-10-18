#pragma force_active on
extern "C" void fn_72_1130(void* p);
extern "C" void* __ct__14snd3DGeneratorFv(void* p);
extern "C" char lbl_72_data_1078[];
extern "C" const float lbl_72_rodata_40;

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, int b);
    unsigned int* p4;
    int w8;
};

extern "C" char* fn_72_1B74(char* self) {
    fn_72_1130(self);
    *(char**)(self + 0x3c) = lbl_72_data_1078;
    __ct__14snd3DGeneratorFv(self + 0x19c);
    *(float*)(self + 0x158) = lbl_72_rodata_40;
    *(int*)(self + 0x15c) = 0;
    *(int*)(self + 0x160) = 0;
    *(int*)(self + 0x164) = 0;
    *(unsigned char*)(self + 0x168) = 4;
    *(unsigned char*)(self + 0x169) = 4;
    *(unsigned char*)(self + 0x16a) = 4;
    *(unsigned char*)(self + 0x16b) = 4;
    *(unsigned char*)(self + 0x16c) = 0;
    *(int*)(self + 0x170) = 0;
    *(unsigned char*)(self + 0x178) = 5;
    *(float*)(self + 0x17c) = lbl_72_rodata_40;
    *(float*)(self + 0x180) = lbl_72_rodata_40;
    *(unsigned char*)(self + 0x184) = 0;
    *(unsigned char*)(self + 0x185) = 0;
    *(int*)(self + 0x188) = 0;
    *(int*)(self + 0x18c) = 0;
    *(int*)(self + 0x190) = 0;
    *(int*)(self + 0x194) = 0;
    *(int*)(self + 0x198) = 0;
    *(int*)(self + 0x1a4) = -1;
    *(int*)(self + 0x174) = 0;

    Sub* sub = (Sub*)(self + 0xd0);
    if (sub == 0) {
        return self;
    }
    sub->w8 = 1;
    sub->v4(0, 15);
    unsigned int* p = sub->p4;
    p[1] = p[1] | 1;
    return self;
}
