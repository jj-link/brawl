#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {
extern float lbl_41_rodata_E28;
extern char lbl_41_data_4018[];
void wnemReport__FPCce(const char*, ...);
float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
float mtCosf__Ff(float);
float mtSinf__Ff(float);
float fn_27_60AF4(void*, float, int, int, int*, float, float, float, float, float, int);
void fn_41_33544(void*, float);
}

struct Pair { int a; int b; };

struct SubObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int vf3();
};

struct Vec4Obj {
    virtual void v0();
    virtual float* get(int);
    virtual void v2();
    virtual void v3();
};

struct WnemSelf {
    char pad[0x21b8];
    u8 f21b8;
    char pad2[0x21d4 - 0x21b9];
    float f21d4;
    float f21d8;
    char pad3[0x2216 - 0x21dc];
    u8 f2216;
    char pad4[0x224c - 0x2217];
    Vec4Obj obj224c;
};

extern "C" void fn_41_337E8(WnemSelf* self, char* arg1, void* dummy, void* accp) {
    char* base;
    float* rodata;

    rodata = &lbl_41_rodata_E28;
    base = lbl_41_data_4018;

    if (self->f21b8 == 0) return;

    wnemReport__FPCce(base + 0x1259);

    float f31 = *(float*)(arg1 + 0xc);
    float f30 = rodata[1] * *(float*)(arg1 + 0x7c);

    float f29 = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(accp, 0x7d6, 0);
    float f28 = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(accp, 0x7d8, 0);
    float f27 = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(accp, 0x7d9, 0);
    float f26 = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(accp, 0x7d7, 0);

    Pair pair = *(Pair*)(arg1 + 0x8c);

    SubObj* sub = *(SubObj**)((char*)*(void**)((char*)accp + 0xd8) + 0x14);
    int subval = sub->vf3();

    f26 = fn_27_60AF4(accp, f31, *(int*)(arg1 + 0x50), subval,
                      &pair.a, f30, f29, f28, f27, f26, 0);

    f31 = f30 * mtCosf__Ff(f26);
    self->obj224c.get(0)[0] = f31;

    f31 = mtSinf__Ff(f26);
    self->obj224c.get(1)[0] = f31;

    float* p2 = self->obj224c.get(2);
    *p2 = rodata[12];
    float* p3 = self->obj224c.get(3);
    *p3 = rodata[0];

    wnemReport__FPCce(base + 0x1289, f26);
    wnemReport__FPCce(base + 0x12be, f30);

    self->f2216 = 1;
    fn_41_33544(self, *(float*)(arg1 + 0x4));
    wnemReport__FPCce(base + 0x12f3, self->f21d4, self->f21d8,
                      *(float*)(arg1 + 0x4));
}
