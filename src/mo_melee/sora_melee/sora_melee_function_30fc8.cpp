#include <math.h>
#pragma force_active on

typedef struct CamInst {
    char pad[0x158];
    float f158;
    float f15c;
    float f160;
    float f164;
} CamInst;

typedef struct Self {
    float a;
    float b;
} Self;

extern "C" CamInst* getInstance__16CameraControllerFv();
extern "C" const float lbl_27_rodata_44C;

extern "C" float fn_27_30FC8(Self* self) {
    CamInst* c = getInstance__16CameraControllerFv();
    float x = self->a;
    if (x < c->f158 || x > c->f15c) {
        float d = c->f160 - c->f164;
        float n = self->b - c->f164;
        float ad = (float)fabs(d);
        return n / ad;
    }
    float y = self->b;
    if (y > c->f160 || y < c->f164) {
        float d = c->f15c - c->f158;
        float n = c->f15c - self->a;
        float ad = (float)fabs(d);
        return n / ad;
    }
    return lbl_27_rodata_44C;
}
