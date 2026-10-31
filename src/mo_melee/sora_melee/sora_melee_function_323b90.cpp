#include <math.h>
#include <so/so_value_accesser.h>

#pragma force_active on
#pragma fp_contract off

namespace {

class CheckModule {
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
    virtual int check() = 0;
};

class VectorModule {
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
    virtual unsigned long long getVector(short*) = 0;
};

class WorkModule {
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
    virtual float getFloat(unsigned long) = 0;
    virtual void setFloat(unsigned long, float) = 0;
};

struct Modules {
    unsigned char pad0[0x44];
    CheckModule* check;
    unsigned char pad1[0x1C];
    WorkModule* work;
    unsigned char pad2[0x14];
    VectorModule* vector;
};

struct Accesser {
    unsigned char pad[0xD8];
    Modules* modules;
};

struct Vec2 {
    float x;
    float y;
};

}

extern "C" {
void fn_27_1D9FF8(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
double __fabs(double);
float rsqrtf__Ff(float);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
extern void* lbl_27_bss_F0;
extern const float lbl_27_rodata_7550[];
}

extern "C" void fn_27_323B90(void* self) {
    const float* constants = lbl_27_rodata_7550;
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

    if ((*reinterpret_cast<Accesser**>(
             static_cast<unsigned char*>(self) + 0x60))
            ->modules->check->check() != 0) {
        return;
    }

    short flag = 1;
    unsigned long long bits =
        (*reinterpret_cast<Accesser**>(
             static_cast<unsigned char*>(self) + 0x60))
            ->modules->vector->getVector(&flag);
    Vec2 vector = *reinterpret_cast<Vec2*>(&bits);

    float maximum;
    float current;
    float divisor;
    float result;

    float sum = vector.x * vector.x + vector.y * vector.y;
    const float magnitude =
        (float)__fabs((double)sum) <= constants[9]
            ? constants[3]
            : sum * rsqrtf__Ff(sum);

    maximum =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            *reinterpret_cast<Accesser**>(
                static_cast<unsigned char*>(self) + 0x60),
            0xFA0, 0);
    current =
        (*reinterpret_cast<Accesser**>(
             static_cast<unsigned char*>(self) + 0x60))
            ->modules->work->getFloat(0x11000001);
    divisor =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            *reinterpret_cast<Accesser**>(
                static_cast<unsigned char*>(self) + 0x60),
            0xFA1, 0);

    result = current + magnitude / divisor;
    if (result > maximum) {
        result = maximum;
    }
    if (result < constants[10]) {
        result = constants[6];
    }

    (*reinterpret_cast<Accesser**>(
         static_cast<unsigned char*>(self) + 0x60))
        ->modules->work->setFloat(0x11000001, result);
}
