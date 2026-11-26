#include <types.h>

#pragma force_active on

extern "C" {
void* fn_8009D2DC();
double fn_80400AB8(double);

extern const float lbl_805A2170;
extern const float lbl_805A2198;
extern const float lbl_805A21A8;
extern const float lbl_805A21AC;
}

struct Vec2 {
    float x;
    float y;

    Vec2& operator=(const Vec2& other) {
        *(u32*)&x = *(const u32*)&other.x;
        *(u32*)&y = *(const u32*)&other.y;
        return *this;
    }
};

extern "C" void fn_800AB1C8(
    float* out,
    float farg0,
    float farg1,
    float farg2,
    float farg3
) {
    char* p = (char*)fn_8009D2DC();

    if ((*(int*)(p + 0x10) >> 24) == 0) {
        out[0] = lbl_805A2170;
        out[1] = lbl_805A2170;
        out[2] = lbl_805A2170;
        return;
    }

    float b = *(float*)(p + 0x4);
    float a = *(float*)(p + 0x0);
    float c = *(float*)(p + 0x8);

    Vec2 z;
    Vec2 w;
    Vec2 v;
    v.y = b * c;
    v.x = a * c;
    w = v;
    z = w;

    float f5 = farg2 * (float)fn_80400AB8(lbl_805A2198 * farg0);

    float dx = f5 / lbl_805A21A8;
    out[1] = farg3 * (z.y * (f5 / lbl_805A21AC));
    out[0] = farg3 * (z.x * (dx * farg1));
    out[2] = lbl_805A2170;
}
