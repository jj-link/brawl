#pragma force_active on

#define VT_METHODS \
    virtual void d2(); \
    virtual void d3(); \
    virtual void d4(); \
    virtual void callA(int, void*); \
    virtual void d6(); \
    virtual void d7(); \
    virtual void d8(); \
    virtual void callB(float); \
    virtual void d10(); \
    virtual void d11(); \
    virtual void d12(); \
    virtual void d13(); \
    virtual float getF(int); \
    virtual void setF(float, int); \
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); \
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); \
    virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27(); \
    virtual void d28(); virtual void d29(); virtual void d30(); virtual void d31(); \
    virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35(); \
    virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39(); \
    virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43(); \
    virtual void d44(); virtual void d45(); virtual void d46(); \
    virtual void callC(); \
    virtual void d48(); virtual void d49(); virtual void d50(); virtual void d51(); \
    virtual void d52(); \
    virtual float getD(int);

class Vt {
public:
    VT_METHODS
};

struct Pad8 {
    int a;
    int b;
};

class VtB : public Pad8 {
public:
    VT_METHODS
};

struct Data {
    char pad0[0x8];
    Vt* at8;
    char pad1[0x2C];
    VtB* at38;
    char pad2[0x20];
    Vt* at5c;
    char pad3[0x4];
    Vt* at64;
    char pad4[0x8];
    Vt* at70;
};

struct Accesser {
    char pad[0xD8];
    Data* d8;
};

extern "C" {
extern const float lbl_27_rodata_24D8;
extern const float lbl_27_rodata_24E4;
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, unsigned long id, unsigned long idx);
}

extern "C" void fn_27_188134(void* unused, Accesser* acc) {
    Data* d8 = acc->d8;
    Vt* w = d8->at64;
    Vt* r28 = d8->at8;
    getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd67, 0);
    acc->d8->at38->callC();
    float f31 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd6c, 0);
    float f30 = acc->d8->at5c->getD(0);
    int r27 = 0;
    if (w->getF(0x21000008) - f30 > f31) {
        r27 = 1;
    }
    w->setF(f30, 0x21000008);
    if (f30 <= lbl_27_rodata_24E4) {
        acc->d8->at70->callA(0xe, acc);
        return;
    }
    float v = w->getF(0x21000005);
    if (v > lbl_27_rodata_24E4) {
        v -= lbl_27_rodata_24D8;
        if (v <= lbl_27_rodata_24E4 && r27 == 0) {
            r28->callB(lbl_27_rodata_24D8);
            v = lbl_27_rodata_24E4;
        }
    }
    if (v <= lbl_27_rodata_24E4 && r27 != 0) {
        r28->callB(getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd6e, 0));
        v = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd6d, 0);
    }
    w->setF(v, 0x21000005);
}
