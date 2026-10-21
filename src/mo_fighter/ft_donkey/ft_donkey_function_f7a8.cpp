#pragma force_active on

class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual int a(int);
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void b(float, float, int);
};

struct Inner {
    char pad[0xa8];
    VObj* vobj;
};

struct Self {
    char pad[0xd8];
    Inner* inner;
};

struct FloatStruct {
    char pad[0xc];
    float f;
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
int fn_27_63438(void*, float);
extern float lbl_92_rodata_70;
extern float lbl_92_rodata_74;
}

extern "C" int fn_92_F7A8(void*, Self* self, FloatStruct* fs) {
    float val = fs->f * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x7D2, 0);
    if (fn_27_63438(self, val) < 3) {
        return 1;
    }
    if (self->inner->vobj->a(0) != 0) {
        self->inner->vobj->b(lbl_92_rodata_70, lbl_92_rodata_74, 0);
    }
    return 0;
}
