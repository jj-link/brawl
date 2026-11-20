#pragma force_active on
#define V(n) virtual void f##n();
#define T10(a) V(a##0) V(a##1) V(a##2) V(a##3) V(a##4) V(a##5) V(a##6) V(a##7) V(a##8) V(a##9)

struct Ev {
    int state;
    unsigned char unk4;
    unsigned char unk5;
    unsigned char unk6;
    int unk8;
    char pad0[8];
    float unk14;
};

struct Arg3 {
    char pad0[0x28];
    void* unk28;
    unsigned int unk2C;
};

struct Obj14 { V(2) V(3) V(4) virtual int f5(); };
struct Mid;
struct Obj70 { V(2) V(3) V(4) virtual void f5(int, Mid*); };

struct MidD8 {
    char pad0[0x14];
    Obj14* unk14;
    char pad1[0x70 - 0x18];
    Obj70* unk70;
};

struct Mid {
    char pad0[0xD8];
    MidD8* unkD8;
};

struct VA8 {
    V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    T10(1) T10(2) T10(3) T10(4)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56)
    virtual int f57(int);
};

struct VB64 {
    V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13)
    virtual float f14(int);
    V(15) V(16) V(17) V(18)
    virtual int f19(int);
    virtual void f20(int);
};

struct VB6C {
    V(2) V(3) V(4) V(5) V(6) V(7)
    virtual void f8(int, void*, int, float);
};

struct VC {
    V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10)
    virtual float f11();
};

struct Inner {
    char pad0[8];
    VA8* unk8;
    VC* unkC;
    char pad1[0x38 - 0x10];
    void* unk38;
    char pad2[0x64 - 0x3C];
    VB64* unk64;
    char pad3[0x6C - 0x68];
    VB6C* unk6C;
    char pad4[0x7C - 0x70];
    void* unk7C;
};

struct Self {
    char pad0[0x28];
    unsigned int unk28;
    char pad1[0x60 - 0x2C];
    Mid* unk60;
    char pad2[0xB0 - 0x64];
    void* unkB0;
    char pad3[0xDC - 0xB4];
    char acc[0x1B4 - 0xDC];
    Inner* unk1B4;
};

extern "C" {
float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned int, unsigned int);
void fn_27_23313C(void*, void*, unsigned int, unsigned int);
void fn_41_103FC(void*, void*, void*, float, float*, int, int, float, bool);
void fn_41_11CBC(void*, float*, int);
void fn_41_B8D4(void*, void*, void*, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern void* g_stTriggerMng;
extern float lbl_41_rodata_10BC;
extern char lbl_41_data_1EE8[];
extern char lbl_41_data_2210[];
extern char lbl_41_data_644[];
extern char lbl_41_data_6A8[];
}

extern "C" void fn_41_50CB4(Self* self, Ev* ev, void* a2, Arg3* a3) {
    switch (ev->state) {
    case 6: {
        ev->unk4 = 1;
        ev->unk6 = 1;
        ev->unk5 = 0;
        ev->unk8 = -1;

        float v;
        if (self->unk1B4->unk8->f57(0) == 0) {
            v = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl((char*)self + 0xDC, 0xFA0, 0);
        } else {
            v = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl((char*)self + 0xDC, 0xFA1, 0);
        }
        ev->unk14 = v;

        if (g_stTriggerMng != 0) {
            fn_27_23313C(self->unkB0, a3->unk28, self->unk28,
                         ((int)((a3->unk2C << 17) & 0xFF800000)) >> 24);
        }

        float sp8 = lbl_41_rodata_10BC;
        if (self->unk1B4->unk64->f19(0x12000006) != 0) {
            sp8 = self->unk1B4->unk64->f14(0x11000001);
        }

        VC* t29;
        void* t28;
        void* t27;
        short hint = 1;
        t28 = __dynamic_cast(self->unk1B4->unk38, 8, lbl_41_data_1EE8, lbl_41_data_2210, hint);
        fn_41_11CBC(t28, &sp8, 0);

        self->unk1B4->unk6C->f8(5, self->acc, 0, lbl_41_rodata_10BC);

        t27 = __dynamic_cast(self->unk1B4->unk7C, 0, lbl_41_data_644, lbl_41_data_6A8, hint);
        t29 = self->unk1B4->unkC;
        float vec[2];
        vec[0] = lbl_41_rodata_10BC;
        vec[1] = lbl_41_rodata_10BC;
        float f2 = t29->f11();
        fn_41_103FC(t28, t27, t29, lbl_41_rodata_10BC, vec, 0, 0, f2, 0);

        if (self->unk1B4->unk64->f19(0x12000006) == 0) {
            if (self->unk60->unkD8->unk14->f5() == 0) {
                self->unk60->unkD8->unk70->f5(0xE, self->unk60);
                return;
            } else {
                self->unk60->unkD8->unk70->f5(0xE, self->unk60);
                return;
            }
        } else {
            self->unk1B4->unk64->f20(0x12000007);
            if (self->unk60->unkD8->unk14->f5() == 0) {
                self->unk60->unkD8->unk70->f5(0x15, self->unk60);
                return;
            } else {
                self->unk60->unkD8->unk70->f5(0x14, self->unk60);
                return;
            }
        }
    }
    default:
        fn_41_B8D4(self, ev, a2, a3);
    }
}
