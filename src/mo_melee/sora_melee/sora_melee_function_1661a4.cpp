#include <so/so_module_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#include <types.h>

#pragma force_active on

#define DUM(n) virtual void d##n();

class Work {
public:
    DUM(0) DUM(1) DUM(2) DUM(3) DUM(4) DUM(5)
    DUM(6) DUM(7) DUM(8) DUM(9) DUM(10) DUM(11)
    virtual float getFloat(u32);        // 0x38
    DUM(13) DUM(14) DUM(15)
    virtual void setFloat(u32, float);  // 0x48
    virtual u32 isFlag(u32);            // 0x4c
};

class Motion {
public:
    DUM(0) DUM(1) DUM(2) DUM(3) DUM(4) DUM(5) DUM(6)
    virtual void setRot(float);         // 0x24
};

struct Modules {
    char pad[0x8];
    Motion* motion;
    char pad2[0x58];
    Work* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
float fn_27_194A74(void*);
void fn_27_165458(void*, u32, float, float, float, float, float, float);
extern const float lbl_27_rodata_2048;
extern const float lbl_27_rodata_204C;
}

extern "C" void fn_27_1661A4(void* unused, void* p) {
    Accesser* a = (Accesser*)p;

    float bbe, bbf, c37, t, result, v5, x, y;

    v5 = a->modules->work->getFloat(0x21000005);
    t = fn_27_194A74(p);
    c37 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(p, 0xC37, 0);
    bbf = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(p, 0xBBF, 0);
    bbe = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(p, 0xBBE, 0);

    fn_27_165458(p, 0x21000005, v5,
                 getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(p, 0xBC0, 0),
                 bbe, bbf, c37, t);

    x = a->modules->work->getFloat(0x21000005);
    y = a->modules->work->getFloat(0x21000007);

    if (a->modules->work->isFlag(0x1200000A) == 1) {
        float k = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(p, 0xD8A, 0);
        result = y * k;
        if (result < k) {
            result = k;
        }
    } else {
        result = y * (float)(double)nw4r::math::FAbs(x);
    }

    float limit = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(p, 0xC3C, 0);
    if (result > limit) {
        result = limit;
    }

    a->modules->motion->setRot(result);

    if (a->modules->work->getFloat(0x21000004) > lbl_27_rodata_204C) {
        a->modules->work->setFloat(0x21000004, lbl_27_rodata_2048);
    }
}
