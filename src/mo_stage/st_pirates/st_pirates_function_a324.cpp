#pragma force_active on

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void set(int, int);

    unsigned int* flags;
    int x;
};

extern "C" void fn_52_35D0(void*);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" char lbl_52_data_2390[];
extern "C" const float lbl_52_rodata_160;

extern "C" void* fn_52_A324(void* self) {
    char* obj = (char*)self;
    fn_52_35D0(self);
    *(void**)(obj + 0x3c) = lbl_52_data_2390;
    __ct__14snd3DGeneratorFv(obj + 0x17c);

    *(char*)(obj + 0x150) = 0;
    *(float*)(obj + 0x154) = lbl_52_rodata_160;
    *(int*)(obj + 0x160) = 0;
    *(int*)(obj + 0x164) = 0;
    *(char*)(obj + 0x168) = 1;
    *(char*)(obj + 0x169) = 2;
    *(float*)(obj + 0x16c) = lbl_52_rodata_160;
    *(int*)(obj + 0x170) = 0;

    Sub* sub = (Sub*)(obj + 0xd0);
    if (sub == 0) {
        return self;
    }
    sub->x = 1;
    sub->set(0, 15);
    sub->flags[1] |= 8;

    *(char*)(obj + 0x174) = 0;
    *(char*)(obj + 0x175) = 0;
    *(int*)(obj + 0x178) = 0;
    *(int*)(obj + 0x184) = -1;
    *(int*)(obj + 0x188) = 0;
    *(int*)(obj + 0x18c) = -1;
    return self;
}
