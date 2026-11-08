#pragma force_active on

#include <em/em_external_value_accesser.h>

struct V2 {
    float x, y;

    void set(float a, float b) {
        x = a;
        y = b;
    }
};

struct Result {
    unsigned int x, y;
};

extern "C" {
extern float lbl_41_rodata_D50[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_41_10830(const V2*);
Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
Vec3f* fn_41_534C(Vec3f*, const Vec3f&);
V2* fn_41_2354(V2*, float, float);
Result fn_41_24110(V2*, V2*);
float fn_41_15FB0(float, float);
}

static inline float adjustAngle(float angle, float mode, float scale,
                                const float* constants) {
    if (constants[1] != mode) {
        if (constants[4] == mode)
            angle *= constants[4];
        else
            return constants[2];
    }

    if (angle < constants[2])
        angle = constants[6] - angle;

    return scale * angle / constants[6];
}

extern "C" float fn_41_23F3C(
    void* self, const V2* first, const V2* second,
    const V2* direction, float mode, float scale) {
    const float* constants = lbl_41_rodata_D50;

    if (constants[2] == fn_41_10830(direction))
        return constants[4];

    if (scale <= constants[2])
        return constants[4];

    Vec3f center;
    fn_41_5AC4(&center, constants[2], constants[2], constants[2]);
    fn_41_534C(
        &center,
        emExternalValueAccesser::getCenterPos(
            (Enemy*)__dynamic_cast(
                *(void**)((char*)self + 8), 0x3c,
                __RTTI__5Enemy, __RTTI__11StageObject, 1)));

    V2 center2;
    center2.set(center.m_x, center.m_y);

    V2 sum;
    fn_41_2354(&sum, first->x + second->x, first->y + second->y);

    Result difference;
    Result result = fn_41_24110(&sum, &center2);
    difference = result;

    if (constants[2] == fn_41_10830((const V2*)&difference))
        return constants[4];

    float directionAngle =
        constants[5] * fn_41_15FB0(direction->y, direction->x);
    return adjustAngle(
        directionAngle -
            constants[5] * fn_41_15FB0(
                *(float*)&difference.y, *(float*)&difference.x),
        mode, scale, constants);
}
