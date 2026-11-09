#pragma force_active on
extern "C" void fn_71_2708(void* self);
extern "C" void __ct__14snd3DGeneratorFv(void* self);
extern "C" char lbl_71_data_2030[];
extern "C" const float lbl_71_rodata_178;

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void slot4(int, int);

    unsigned int* flags;
    int x;
};

extern "C" void* fn_71_6B40(void* self) {
    char* obj = (char*)self;
    fn_71_2708(self);
    *(void**)(obj + 0x3c) = lbl_71_data_2030;
    __ct__14snd3DGeneratorFv(obj + 0x1d0);

    const float f = lbl_71_rodata_178;
    *(float*)(obj + 0x158) = f;
    *(float*)(obj + 0x15c) = f;
    *(float*)(obj + 0x160) = f;
    *(float*)(obj + 0x164) = f;
    *(float*)(obj + 0x168) = f;
    *(float*)(obj + 0x16c) = f;
    *(int*)(obj + 0x170) = 0;
    *(int*)(obj + 0x174) = 0;
    *(float*)(obj + 0x178) = f;
    *(float*)(obj + 0x17c) = f;
    *(float*)(obj + 0x180) = f;
    *(float*)(obj + 0x184) = f;
    *(float*)(obj + 0x188) = f;
    *(float*)(obj + 0x18c) = f;
    *(int*)(obj + 0x190) = 0;
    *(char*)(obj + 0x194) = 9;
    *(float*)(obj + 0x198) = f;
    *(float*)(obj + 0x19c) = f;
    *(float*)(obj + 0x1a0) = f;
    *(float*)(obj + 0x1a4) = f;
    *(int*)(obj + 0x1a8) = 0;
    *(float*)(obj + 0x1ac) = f;
    *(char*)(obj + 0x1b8) = 0;
    *(int*)(obj + 0x1bc) = 0;
    *(int*)(obj + 0x1c0) = 0;
    *(int*)(obj + 0x1c4) = 0;
    *(int*)(obj + 0x1c8) = 0;
    *(int*)(obj + 0x1cc) = 0;
    *(char*)(obj + 0x1b0) = 1;
    *(float*)(obj + 0x1b4) = f;

    Sub* sub = (Sub*)(obj + 0xd0);
    if (sub == 0) {
        return self;
    }
    sub->x = 1;
    sub->slot4(0, 0xf);
    *(unsigned int*)(sub->flags + 1) |= 0x10;
    *(int*)(obj + 0x1d8) = 0;
    *(int*)(obj + 0x1dc) = -1;
    return self;
}