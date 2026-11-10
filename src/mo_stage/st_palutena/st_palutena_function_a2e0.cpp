#pragma force_active on
#pragma opt_propagation off

struct Component {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void set(int, int);

    unsigned int* flags;
    int state;
};

extern "C" {
void* fn_67_A040(void* self);
void __ct__14snd3DGeneratorFv(void* self);

extern char lbl_67_data_27D4[];
extern const float lbl_67_rodata_E8[6];
}

extern "C" void* fn_67_A2E0(char* self) {
    const float* fp = lbl_67_rodata_E8;
    fn_67_A040(self);
    *(void**)(self + 0x3c) = lbl_67_data_27D4;
    __ct__14snd3DGeneratorFv(self + 0x1cc);
    Component* sub = (Component*)(self + 0xd0);

    int o = 1;
    unsigned char z = 0;
    *(unsigned char*)(self + 0x15c) = z;
    *(unsigned char*)(self + 0x15d) = z;
    *(float*)(self + 0x160) = fp[0];
    *(float*)(self + 0x164) = fp[0];
    *(float*)(self + 0x168) = fp[0];
    *(unsigned char*)(self + 0x16c) = z;
    *(unsigned char*)(self + 0x16d) = z;
    *(unsigned char*)(self + 0x16e) = z;
    *(unsigned char*)(self + 0x16f) = z;
    *(unsigned char*)(self + 0x170) = o;
    *(float*)(self + 0x174) = fp[1];
    *(float*)(self + 0x178) = fp[2];
    *(float*)(self + 0x17c) = fp[3];
    *(float*)(self + 0x180) = fp[0];
    *(float*)(self + 0x184) = fp[4];
    *(float*)(self + 0x188) = fp[0];
    *(float*)(self + 0x18c) = fp[4];
    *(float*)(self + 0x190) = fp[5];
    *(float*)(self + 0x194) = fp[0];
    *(float*)(self + 0x198) = fp[0];
    *(float*)(self + 0x1a4) = fp[0];
    *(float*)(self + 0x1a8) = fp[0];
    *(float*)(self + 0x1ac) = fp[0];
    *(float*)(self + 0x1b0) = fp[0];
    *(float*)(self + 0x1b4) = fp[0];
    *(float*)(self + 0x1b8) = fp[0];
    *(float*)(self + 0x1bc) = fp[0];
    *(float*)(self + 0x1c0) = fp[0];
    *(float*)(self + 0x1c4) = fp[0];
    *(int*)(self + 0x19c) = 0;
    *(float*)(self + 0x1a0) = fp[0];
    *(unsigned char*)(self + 0x1c8) = z;

    if (sub == 0) {
        return self;
    }

    sub->state = o;
    sub->set(0, 15);
    sub->flags[1] |= 0x10;
    return self;
}
