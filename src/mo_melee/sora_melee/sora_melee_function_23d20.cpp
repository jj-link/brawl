#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_38C;
extern const float lbl_27_rodata_394;
}

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
    virtual float get();
};

struct Modules {
    char pad[0x5C];
    Controller* controller;
};

struct Access {
    char pad[0xD8];
    Modules* modules;
};

struct Self {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float get();
    virtual void set(float);
    char pad[4];
    Access* access;
};

extern "C" bool fn_27_23D20(Self* self, float threshold) {
    float stick = self->access->modules->controller->get();
    float previous = self->get();

    if (stick > threshold) {
        self->set(lbl_27_rodata_38C);
    } else if (stick < -threshold) {
        self->set(lbl_27_rodata_394);
    }

    return previous != self->get();
}
