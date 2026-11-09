#include <nw4r/math/math_arithmetic.h>

#pragma force_active on
#pragma fp_contract off

extern "C" {
void fn_27_1D9FF8(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
float rsqrtf__Ff(float);
extern void* lbl_27_bss_F0;
extern const unsigned char lbl_27_rodata_7960[];
}

namespace {
struct Vec2 {
    float x;
    float y;
};

class Module44 {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual int slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
};

class Module64 {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual float slot38(unsigned long, void*) = 0;
    virtual void slot3C(unsigned long, void*, float) = 0;
};

class Module7C {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual unsigned long long slot3C(short*) = 0;
};

struct SoraConst {
    float pad[3];
    float zero;
    float pad2[2];
    float min;
    float pad3[2];
    float epsilon;
    float threshold;
};
}

extern "C" void fn_27_355824(void* self) {
    unsigned char* base = static_cast<unsigned char*>(self);
    const SoraConst* c = reinterpret_cast<const SoraConst*>(lbl_27_rodata_7960);
    fn_27_1D9FF8(self);

    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }

    if (fn_27_5BE80(lbl_27_bss_F0) != 1) {
        return;
    }

    if ((*reinterpret_cast<Module44**>(
             *reinterpret_cast<unsigned char**>(
                 *reinterpret_cast<unsigned char**>(base + 0x60) + 0xD8) +
             0x44))->slot2C() != 0) {
        return;
    }

    short id = 1;
    unsigned long long bits = (*reinterpret_cast<Module7C**>(
        *reinterpret_cast<unsigned char**>(
            *reinterpret_cast<unsigned char**>(base + 0x60) + 0xD8) +
        0x7C))->slot3C(&id);
    Vec2 v = *reinterpret_cast<Vec2*>(&bits);

    float c_fa0;
    float sum = v.x * v.x + v.y * v.y;
    const float mag =
        (float)(double)nw4r::math::FAbs(sum) <= c->epsilon
            ? c->zero
            : sum * rsqrtf__Ff(sum);

    c_fa0 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        *reinterpret_cast<void**>(base + 0x60), 0xFA0, 0);
    float val = (*reinterpret_cast<Module64**>(
        *reinterpret_cast<unsigned char**>(
            *reinterpret_cast<unsigned char**>(base + 0x60) + 0xD8) +
        0x64))->slot38(
        0x11000001,
        *reinterpret_cast<unsigned char**>(
            *reinterpret_cast<unsigned char**>(base + 0x60) + 0xD8));
    float c_fa1 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        *reinterpret_cast<void**>(base + 0x60), 0xFA1, 0);

    float result_val = val + mag / c_fa1;
    if (result_val > c_fa0) {
        result_val = c_fa0;
    }
    if (result_val < c->threshold) {
        result_val = c->min;
    }

    (*reinterpret_cast<Module64**>(
        *reinterpret_cast<unsigned char**>(
            *reinterpret_cast<unsigned char**>(base + 0x60) + 0xD8) +
        0x64))->slot3C(
        0x11000001,
        *reinterpret_cast<void**>(base + 0x60),
        result_val);
}
