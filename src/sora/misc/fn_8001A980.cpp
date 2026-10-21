#include <types.h>
#pragma force_active on

struct Light {
    unsigned int data[16];
};

struct Color {
    unsigned char r, g, b, a;
};

struct Vec3f {
    float x, y, z;
};

extern "C" void fn_801F2400(Light*, Color);
extern "C" void fn_801F2284(Light*, float, float, float);
extern "C" void fn_8003DE70(Vec3f*);
extern "C" void fn_801F22B0(Light*, float, float, float);
extern "C" void fn_801F202C(Light*, int, float);
extern "C" void fn_801F21B4(Light*, int, float, float);
extern "C" void fn_801F2418(Light*, unsigned int);

extern const float lbl_805A1468;
extern const float lbl_805A146C;
extern const float lbl_805A1470;
extern const float lbl_805A1474;
extern const float lbl_805A1478;

extern "C" void gfDrawResetLight__Fv() {
    Light light;
    Vec3f direction;
    Color color;

    color.r = color.g = color.b = color.a = 0x80;
    fn_801F2400(&light, color);
    fn_801F2284(&light, lbl_805A1468, lbl_805A146C, lbl_805A1468);

    direction.x = lbl_805A1470;
    direction.y = lbl_805A1470;
    direction.z = lbl_805A1470;
    fn_8003DE70(&direction);
    fn_801F22B0(&light, direction.x, direction.y, direction.z);

    fn_801F202C(&light, 0, lbl_805A1474);
    fn_801F21B4(&light, 0, lbl_805A146C, lbl_805A1478);
    fn_801F2418(&light, 1);
    fn_801F2418(&light, 2);
    fn_801F2418(&light, 4);
    fn_801F2418(&light, 8);
    fn_801F2418(&light, 0x10);
    fn_801F2418(&light, 0x20);
    fn_801F2418(&light, 0x40);
    fn_801F2418(&light, 0x80);
}
