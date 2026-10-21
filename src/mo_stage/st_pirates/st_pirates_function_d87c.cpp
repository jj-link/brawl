#pragma force_active on

struct Component {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void set(int, int);

    unsigned int* flags;
    int state;
};

extern "C" void* fn_52_35D0(void*, const char*);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" char lbl_52_data_2DA8[];
extern "C" const float lbl_52_rodata_238;

extern "C" void* fn_52_D87C(char* self, const char* name) {
    fn_52_35D0(self, name);
    *(void**)(self + 0x3c) = lbl_52_data_2DA8;
    __ct__14snd3DGeneratorFv(self + 0x1ac);

    *(int*)(self + 0x164) = 0;
    *(float*)(self + 0x160) = lbl_52_rodata_238;
    *(int*)(self + 0x168) = 0;
    *(int*)(self + 0x16c) = 0;
    *(int*)(self + 0x170) = 0;
    *(int*)(self + 0x174) = 0;
    *(int*)(self + 0x178) = 0;
    *(float*)(self + 0x17c) = lbl_52_rodata_238;
    *(float*)(self + 0x180) = lbl_52_rodata_238;
    *(float*)(self + 0x184) = lbl_52_rodata_238;
    *(float*)(self + 0x188) = lbl_52_rodata_238;
    *(float*)(self + 0x18c) = lbl_52_rodata_238;
    *(float*)(self + 0x190) = lbl_52_rodata_238;
    *(float*)(self + 0x194) = lbl_52_rodata_238;
    *(float*)(self + 0x198) = lbl_52_rodata_238;
    *(float*)(self + 0x19c) = lbl_52_rodata_238;
    *(unsigned char*)(self + 0x1a0) = 0;

    Component* sub = (Component*)(self + 0xd0);
    if (!sub)
        return self;

    sub->state = 1;
    sub->set(0, 15);
    sub->flags[1] |= 1;

    *(unsigned char*)(self + 0x1a1) = 0;
    *(unsigned char*)(self + 0x1a2) = 0;
    *(int*)(self + 0x1a4) = 0;
    *(int*)(self + 0x1a8) = 0;
    return self;
}
