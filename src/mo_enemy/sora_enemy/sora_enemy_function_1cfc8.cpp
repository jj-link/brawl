#pragma always_inline on
#include <math.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};
class AngleModule {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual Vec3 get(int);
    virtual void set(const Vec3&, int);
};
extern "C" {
extern const float lbl_41_rodata_C90[];
float fn_41_1D178(float*);
Vec3 fn_41_1E768(int, int, float, int, int);
void fn_41_1BEBC(const Vec3*, const Vec3*, Vec3*);
void fn_41_1CFC8(void* a, int b, AngleModule* c, float* d, float e, float f) {
    const float* rd = lbl_41_rodata_C90;
    float current;
    float magnitude;
    float target;
    float delta;
    if (fn_41_1D178(d) <= rd[17])
        return;
    float dy = d[1];
    float dx = d[0];
    target = rd[0] * (rd[18] * (float)atan2(dx, dy));
    float* angle = (float*)((char*)a + 0xAC);
    current = *angle;
    delta = target - current;
    magnitude = (float)(double)nw4r::math::FAbs(delta);
    if (magnitude >= rd[13]) {
        if (current <= rd[3])
            *angle = current + rd[1];
        else if (current >= rd[3])
            *angle = current - rd[1];
        delta = target - *angle;
    }
    float lim = (float)(double)nw4r::math::FAbs(e);
    if (delta > lim)
        delta = lim;
    float neg = -(float)(double)nw4r::math::FAbs(e);
    if (delta < neg)
        delta = neg;
    Vec3 z = fn_41_1E768(b, 2, delta + f, *(int*)((char*)a + 0x8C), 0);
    Vec3 y;
    Vec3 x = c->get(*(int*)((char*)a + 0x8C));
    fn_41_1BEBC(&x, &z, &y);
    c->set(y, *(int*)((char*)a + 0x8C));
    *angle = *angle + delta;
}
}