#pragma force_active on
extern "C" void fn_52_35D0(void*);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" char lbl_52_data_25E8[];
extern const float lbl_52_rodata_1B8;

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void method(int, int);

    unsigned int* flags;
    int x;
};

extern "C" void* fn_52_BA08(void* self) {
    char* obj = (char*)self;
    fn_52_35D0(self);
    *(void**)(obj + 0x3c) = lbl_52_data_25E8;
    __ct__14snd3DGeneratorFv(obj + 0x178);
    *(char*)(obj + 0x160) = 0;
    *(char*)(obj + 0x161) = 0;
    *(int*)(obj + 0x164) = 0;
    *(int*)(obj + 0x168) = 0;
    *(char*)(obj + 0x16c) = 0;
    *(char*)(obj + 0x16d) = 1;
    *(float*)(obj + 0x170) = lbl_52_rodata_1B8;
    *(char*)(obj + 0x174) = 0;
    Sub* sub = (Sub*)(obj + 0xd0);
    if (sub == 0) {
        return self;
    }
    sub->x = 1;
    sub->method(0, 15);
    sub->flags[1] |= 8;
    *(int*)(obj + 0x180) = -1;
    *(char*)(obj + 0x184) = 0;
    return self;
}
