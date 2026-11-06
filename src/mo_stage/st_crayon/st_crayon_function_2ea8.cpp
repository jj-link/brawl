#pragma force_active on

struct Component {
    virtual ~Component();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void set(int, int);

    unsigned int* flags;
    int state;
};

extern "C" void __ct__16grCrayonYakumonoFPCc(void*, const char*);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" char lbl_56_data_1800[];
extern "C" const float lbl_56_rodata_80;

extern "C" void* fn_56_2EA8(char* self, const char* name) {
    __ct__16grCrayonYakumonoFPCc(self, name);
    *(int*)(self + 0x198) = 0;
    *(void**)(self + 0x3c) = lbl_56_data_1800;
    *(int*)(self + 0x19c) = 0;
    *(int*)(self + 0x1a0) = 0;
    *(int*)(self + 0x1a4) = 0;
    *(int*)(self + 0x1a8) = 0;
    __ct__14snd3DGeneratorFv(self + 0x1b8);

    *(int*)(self + 0x160) = 0;
    *(float*)(self + 0x164) = lbl_56_rodata_80;
    *(float*)(self + 0x168) = lbl_56_rodata_80;
    *(int*)(self + 0x16c) = 0;
    *(float*)(self + 0x170) = lbl_56_rodata_80;
    *(float*)(self + 0x174) = lbl_56_rodata_80;
    *(float*)(self + 0x178) = lbl_56_rodata_80;
    *(float*)(self + 0x17c) = lbl_56_rodata_80;
    *(float*)(self + 0x180) = lbl_56_rodata_80;
    *(int*)(self + 0x184) = 0;
    *(int*)(self + 0x188) = 0;
    *(float*)(self + 0x18c) = lbl_56_rodata_80;
    *(float*)(self + 0x190) = lbl_56_rodata_80;
    *(float*)(self + 0x194) = lbl_56_rodata_80;
    *(int*)(self + 0x1ac) = 0;
    *(unsigned char*)(self + 0x1b0) = 0;
    *(unsigned char*)(self + 0x1b1) = 0;
    *(int*)(self + 0x1b4) = 0;
    *(int*)(self + 0x1c0) = -1;

    Component* sub = (Component*)(self + 0xd0);
    if (!sub) {
        return self;
    }

    sub->state = 1;
    sub->set(0, 15);
    sub->flags[1] |= 1;
    sub->flags[1] |= 2;
    sub->flags[1] |= 4;
    return self;
}
