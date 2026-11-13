#pragma force_active on
#include <nw4r/math/math_arithmetic.h>

struct Controller {
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual float stickX();
    virtual void v19();
    virtual void v20();
    virtual float angle();
};

struct Posture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float lr();
};

struct Modules {
    char pad[12];
    Posture* posture;
    char pad10[0x4c];
    Controller* controller;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern const float lbl_121_rodata_0[];
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
}

extern "C" float fn_121_A600(Accesser* accesser) {
    float x;
    const float* constants = lbl_121_rodata_0;
    Controller* controller = accesser->modules->controller;
    float result = constants[3];
    x = (float)(double)nw4r::math::FAbs(controller->stickX());

    if (x > getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xfaa, 0)) {
        float limit =
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xfab, 0);
        result = controller->angle();
        if (result > limit)
            result = limit;
        else if (result < -limit)
            result = -limit;
    }

    if (constants[6] == accesser->modules->posture->lr()) {
        if (result < constants[3])
            result = constants[7] - result;
        else
            result = constants[8] - result;
    }

    if (result < constants[3])
        result += constants[9];

    return result;
}
