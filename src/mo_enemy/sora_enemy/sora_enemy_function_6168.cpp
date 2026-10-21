#pragma force_active on
#include <math.h>

struct Vec3 {
    float x, y, z;
};

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
    virtual float getFloat(unsigned long);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct Enemy {
    char pad[0xd8];
    unsigned char flag;
    char pad2[0x1b4 - 0xd9];
    Modules* modules;
};

extern "C" {
extern const float lbl_41_rodata_18;
extern const float lbl_41_rodata_10;

Vec3* fn_41_5AC4(Vec3*, float, float, float);
float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);

void fn_41_6168(Vec3* self, Enemy* enemy, float value, int mode) {
    fn_41_5AC4(self, lbl_41_rodata_18, lbl_41_rodata_18,
               lbl_41_rodata_18);

    float amount;
    if (enemy->flag == 0) {
        double absolute = __fabs(
            getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                (char*)enemy + 0xdc, 0xbe9, 0));
        amount = absolute;
    } else {
        amount = enemy->modules->work->getFloat(0x11000006);
    }

    if (mode == 0) {
        self->y = value;
        if (value > lbl_41_rodata_18) {
            amount *= lbl_41_rodata_10;
        }
        self->y += amount;
    } else {
        if (value < lbl_41_rodata_18) {
            amount *= lbl_41_rodata_10;
        }
        self->y += amount;
    }
}
}
