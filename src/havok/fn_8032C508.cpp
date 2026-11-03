#pragma force_active on
#pragma fp_contract on

#include <../../hk410/include/hkmath/hkMath.h>

struct Vec {
    float v[4];
} __attribute__((aligned(16)));

struct Mat {
    float v[12];
} __attribute__((aligned(16)));

struct Trans {
    float v[16];
} __attribute__((aligned(16)));

struct Props {
    float a, b;
    float pad[2];
    Vec center;
    Mat inertia;
} __attribute__((aligned(16)));

struct Elem {
    float a, b;
    float pad[2];
    Vec center;
    Mat inertia;
    Trans transform;
} __attribute__((aligned(16)));

struct Acc {
    char data[0x1c0];
} __attribute__((aligned(16)));

extern const float lbl_805A4848;
extern const float lbl_805A4850;
extern const float lbl_805A4854;
extern const float lbl_805A4858;
extern const float lbl_805A485C;
extern const float lbl_805A4860;
extern const float lbl_805A4864;
extern const float lbl_805A4868;
extern const float lbl_805A486C;
extern const float lbl_805A4870;

extern "C" {
void fn_802DB598(void*);
void fn_80294764(void*, const void*, const void*);
float fn_80295098(void*);
void fn_802AA2C4(void*);
void fn_80294C80(void*);
void fn_802DB6D0(void*, float, float, float, float);
float fn_80294C58(void*, void*);
void fn_802947A8(void*, void*, void*);
void fn_802F2F28(void*, void*, float);
void fn_8032CA98(void*, void*);
void fn_8032CA9C(void*);
void fn_80304BC4(void*, const void*, const void*);
void fn_80294D1C(void*, float);
void fn_8032CB1C(void*, void*);
void fn_8032CC20(void*, int);
void fn_8032CB40(void*);
void fn_8032CDA8(void*, void*);
void fn_8032BD74(void*);
float* fn_80291270(void*, int, int);
void fn_802839D4(void*, float);
void fn_80294398(void*);
void fn_8032CE54(void*, void*);
void* fn_8031351C(void*);
void fn_802879F8(void*, void*, void*);
void* fn_8032CC18(void*);
void fn_80297444(void*, void*);
void fn_8032C42C(void*);
void fn_8032C35C(void*, float, float);
void fn_8032C4A4(void*, void*);
void fn_8032D2D4(void*, void*, float);
void fn_8032CFCC(void*, void*);
void fn_8032CD14(void*, int);
}

static inline float multiply(float a, float b) {
    return a * b;
}

extern "C" int fn_8032C508(const Vec* a, const Vec* b, void* out,
                           float radius, float mass) {
    if (mass <= lbl_805A4848) return 1;
    if (radius <= lbl_805A4848) return 1;

    Vec dir;
    fn_802DB598(&dir);
    fn_80294764(&dir, b, a);
    float length = fn_80295098(&dir);

    Trans transform;
    fn_802AA2C4(&transform);
    if (length > lbl_805A4848) {
        fn_80294C80(&dir);
        Vec axis;
        fn_802DB598(&axis);
        fn_802DB6D0(&axis, lbl_805A4848, lbl_805A4848,
                    lbl_805A4850, lbl_805A4848);
        if (hkMath::fabs(fn_80294C58(&dir, &axis)) < lbl_805A4860) {
            Vec cross;
            fn_802DB598(&cross);
            fn_802947A8(&cross, &axis, &dir);
            fn_80294C80(&cross);
            float angle = hkMath::acos(fn_80294C58(&dir, &axis));
            Vec rotation;
            fn_802F2F28(&rotation, &cross, angle);
            fn_8032CA98(&transform, &rotation);
        } else {
            fn_8032CA9C(&transform);
        }
    } else {
        fn_8032CA9C(&transform);
    }

    Vec midpoint;
    fn_802DB598(&midpoint);
    fn_80304BC4(&midpoint, a, b);
    fn_80294D1C(&midpoint, lbl_805A4858);
    fn_8032CB1C(&transform, &midpoint);

    float sphereVolume = lbl_805A4854 * radius;
    sphereVolume *= radius;
    sphereVolume = radius * sphereVolume;
    float cylinderVolume = length * (radius * (lbl_805A4864 * radius));
    float total = sphereVolume + cylinderVolume;
    float sphereMass = mass * sphereVolume / total;
    float cylinderMass = mass * cylinderVolume / total;

    Acc acc;
    fn_8032CC20(&acc, 0);

    Elem cylinder;
    fn_8032CB40(&cylinder);
    fn_8032CDA8(&cylinder.transform, &transform);
    fn_802DB6D0(&cylinder.center, lbl_805A4848, lbl_805A4848,
                lbl_805A4848, lbl_805A4848);
    fn_8032BD74(&cylinder.inertia);
    *fn_80291270(&cylinder.inertia, 0, 0) =
        lbl_805A4868 * multiply(radius, radius) +
        (multiply(multiply(length * lbl_805A4858, length), lbl_805A4858) /
         lbl_805A485C);
    *fn_80291270(&cylinder.inertia, 1, 1) =
        *fn_80291270(&cylinder.inertia, 0, 0);
    *fn_80291270(&cylinder.inertia, 2, 2) =
        lbl_805A4858 * (radius * radius);
    fn_802839D4(&cylinder.inertia, cylinderMass);
    fn_80294398(&cylinder.center);
    cylinder.a = cylinderVolume;
    cylinder.b = cylinderMass;
    fn_8032CE54(&acc, &cylinder);

    Elem cap1;
    fn_8032CB40(&cap1);
    fn_8032CDA8(&cap1.transform, &transform);
    Vec offset1;
    fn_802DB598(&offset1);
    fn_802DB6D0(&offset1, lbl_805A4848, lbl_805A4848,
                length * lbl_805A4858, lbl_805A4848);
    fn_802879F8(&offset1, fn_8031351C(&transform), &offset1);
    fn_80297444(&offset1, fn_8032CC18(&cap1.transform));
    fn_8032CB1C(&cap1.transform, &offset1);
    fn_802DB6D0(&cap1.center, lbl_805A4848, lbl_805A4848,
                lbl_805A486C * radius, lbl_805A4848);

    Props props1;
    fn_8032C42C(&props1);
    fn_8032C35C(&props1, radius, sphereMass);
    fn_8032C4A4(&cap1.inertia, &props1.inertia);
    fn_802839D4(&cap1.inertia, lbl_805A4858);
    fn_8032D2D4(&cap1.center, &cap1.inertia, lbl_805A4858 * sphereMass);
    cap1.a = lbl_805A4858 * sphereVolume;
    cap1.b = lbl_805A4858 * sphereMass;
    fn_8032CE54(&acc, &cap1);

    Elem cap2;
    fn_8032CB40(&cap2);
    fn_8032CDA8(&cap2.transform, &transform);
    Vec offset2;
    fn_802DB598(&offset2);
    fn_802DB6D0(&offset2, lbl_805A4848, lbl_805A4848,
                -(length * lbl_805A4858), lbl_805A4848);
    fn_802879F8(&offset2, fn_8031351C(&transform), &offset2);
    fn_80297444(&offset2, fn_8032CC18(&cap2.transform));
    fn_8032CB1C(&cap2.transform, &offset2);
    fn_802DB6D0(&cap2.center, lbl_805A4848, lbl_805A4848,
                lbl_805A4870 * radius, lbl_805A4848);

    Props props2;
    fn_8032C42C(&props2);
    fn_8032C35C(&props2, radius, sphereMass);
    fn_8032C4A4(&cap2.inertia, &props2.inertia);
    fn_802839D4(&cap2.inertia, lbl_805A4858);
    fn_8032D2D4(&cap2.center, &cap2.inertia, lbl_805A4858 * sphereMass);
    cap2.a = lbl_805A4858 * sphereVolume;
    cap2.b = lbl_805A4858 * sphereMass;
    fn_8032CE54(&acc, &cap2);

    fn_8032CFCC(&acc, out);
    fn_8032CD14(&acc, -1);
    return 0;
}
