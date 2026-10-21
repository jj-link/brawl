#pragma force_active on
#pragma opt_propagation off

extern "C" {
void* fn_52_35D0(void* self);
extern char lbl_52_data_39E0[];
extern const float lbl_52_rodata_2F8[3];
}

struct Obj {
    char pad1[0x3C];
    void* f3c;
    char pad2[0x110];
    unsigned char f150;
    char pad3[3];
    float f154;
    char pad4[8];
    float f160;
    float f164;
    float f168;
    int f16c;
    unsigned char f170;
    char pad5[3];
    float f174;
};

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void method(int, int);

    unsigned int* flags;
    unsigned int x;
};

extern "C" void* fn_52_1142C(void* self) {
    const float* fp = lbl_52_rodata_2F8;
    Obj* obj = (Obj*)self;
    fn_52_35D0(self);
    obj->f3c = lbl_52_data_39E0;
    obj->f150 = 0;
    obj->f154 = fp[0];
    obj->f160 = fp[1];
    obj->f164 = fp[2];
    obj->f168 = fp[0];
    obj->f16c = 0;
    obj->f170 = 0;
    obj->f174 = fp[0];

    Sub* sub = (Sub*)((char*)self + 0xD0);
    if (sub == 0) {
        return self;
    }

    sub->x = 1;
    sub->method(0, 15);
    sub->flags[1] |= 1;
    return self;
}
