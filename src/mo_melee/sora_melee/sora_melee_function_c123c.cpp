#include <revolution/GX/GXTypes.h>
#pragma force_active on
struct Vec4 { float x, y, z, w; };
struct Object { GXColor color; Vec4 current; Vec4 delta; Vec4 scale; unsigned char pad; unsigned char active; };
extern "C" void fn_27_C1328(Vec4*, const Vec4*, const Vec4*);
extern "C" void fn_27_C123C(Object* self) {
    if (self->active == 1) {
        Vec4 result;
        fn_27_C1328(&result, &self->delta, &self->current);
        self->current = result;
        unsigned int packed;
        GXColor color = { (unsigned char)(self->current.x * self->scale.x), (unsigned char)(self->current.y * self->scale.y), (unsigned char)(self->current.z * self->scale.z), (unsigned char)(self->current.w * self->scale.w) };
        packed = *(unsigned int*)&color;
        self->color = *(GXColor*)&packed;
    }
}