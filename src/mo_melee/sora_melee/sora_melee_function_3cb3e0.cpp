#pragma force_active on
#pragma fp_contract off

#include <nw4r/math/math_arithmetic.h>

struct RoConst {
    unsigned char pad0[0x0C];
    float zero;
    unsigned char pad1[0x08];
    float minimum;
    unsigned char pad2[0x08];
    float epsilon;
    float threshold;
};

extern const RoConst lbl_27_rodata_80D8;

class ModuleP {
public:
    virtual void slot00() = 0;
    virtual void slot04() = 0;
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual int check() = 0;
};

class ModuleQ {
public:
    virtual void slot00() = 0;
    virtual void slot04() = 0;
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
    virtual unsigned long long speed(short*) = 0;
};

class ModuleR {
public:
    virtual void slot00() = 0;
    virtual void slot04() = 0;
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
    virtual float getf(unsigned long, void*) = 0;
    virtual void setf(unsigned long, void*, float) = 0;
};

struct Modules {
    unsigned char pad0[0x44];
    ModuleP* p;
    unsigned char pad1[0x1C];
    ModuleR* r;
    unsigned char pad2[0x14];
    ModuleQ* q;
};

struct Accesser {
    unsigned char pad[0xD8];
    Modules* modules;
};

struct Fighter {
    unsigned char pad[0x60];
    Accesser* accesser;
};

struct Vec2 {
    float x;
    float y;
};

extern "C" {
void fn_27_1D9FF8(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
float rsqrtf__Ff(float);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
extern void* lbl_27_bss_F0;

void fn_27_3CB3E0(void* self) {
    const RoConst* constants = &lbl_27_rodata_80D8;
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

    if (((Fighter*)self)->accesser->modules->p->check() != 0) {
        return;
    }

    short id = 1;
    unsigned long long bits =
        ((Fighter*)self)->accesser->modules->q->speed(&id);
    Vec2 velocity = *(Vec2*)&bits;

    float maximum;
    float current;
    float rate;
    float result;

    const float sum = velocity.x * velocity.x + velocity.y * velocity.y;
    double absolute = nw4r::math::FAbs(sum);
    const float magnitude = (float)absolute <= constants->epsilon
        ? constants->zero
        : sum * rsqrtf__Ff(sum);

    maximum =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            (void*)((Fighter*)self)->accesser, 0xFA0, 0);
    current =
        ((Fighter*)self)->accesser->modules->r->getf(
            0x11000001, (void*)((Fighter*)self)->accesser->modules);
    rate =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            (void*)((Fighter*)self)->accesser, 0xFA1, 0);
    result = current + magnitude / rate;

    if (result > maximum) {
        result = maximum;
    }
    if (result < constants->threshold) {
        result = constants->minimum;
    }

    ((Fighter*)self)->accesser->modules->r->setf(
        0x11000001, (void*)((Fighter*)self)->accesser, result);
}
}
