#pragma force_active on

#define VF8(P) virtual void P##0(); virtual void P##1(); virtual void P##2(); virtual void P##3(); virtual void P##4(); virtual void P##5(); virtual void P##6(); virtual void P##7();

struct Work {
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
    virtual void setFloat(float, unsigned long);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void onFlag(unsigned long);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Data {
    char pad[0x8c];
    float* values;
};

struct FighterPad {
    char pad[0x3c];
};

struct Fighter : FighterPad {
    VF8(a) VF8(b) VF8(c) VF8(d) VF8(e) VF8(f) VF8(g) VF8(h) VF8(i) VF8(j)
    VF8(k) VF8(l) VF8(m) VF8(n) VF8(o) VF8(p) VF8(q) VF8(r) VF8(s) VF8(t)
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void callA(unsigned long);
    virtual void y0();
    virtual void y1();
    virtual void y2();
    virtual void y3();
    virtual void y4();
    virtual void y5();
    virtual void callB(unsigned long, unsigned long);
    char pad1[0x60 - 0x40];
    Accesser* accesser;
    char pad2[0xb24c - 0x64];
    Data* data;
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);
extern const float lbl_110_rodata_1D4;

void fn_110_1F4A0(Fighter* self, unsigned long arg2, unsigned long arg3) {
    self->callA(arg3);

    float* values = self->data->values;
    float v = lbl_110_rodata_1D4 * values[0];
    float r = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        self->accesser, 0xdb2, 0);
    v -= r * values[1];

    self->accesser->modules->work->setFloat(v, 0x11000013);
    self->accesser->modules->work->onFlag(0x1200003D);

    self->callB(arg2, 0x130);
}
}
