#pragma always_inline on
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

struct V2 { float x; float y; void set(float a, float b) { x = a; y = b; } };
struct V3 { float x; float y; float z; };
struct Result { unsigned int x; unsigned int y; };

extern "C" {
extern char __RTTI__16emAreaModuleImpl[];
extern char __RTTI__12soAreaModule[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern float lbl_41_rodata_D50[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_41_10830(float*);
V3* fn_41_5AC4(V3*, float, float, float);
void getCenterPos__23emExternalValueAccesserFP5Enemy(V3*, void*);
V3* fn_41_534C(V3*, V3*);
V2* fn_41_2354(V2*, float, float);
Result fn_41_24110(V2*, V2*);
float fn_41_15FB0(float, float);

int fn_41_24E78(char* self, V2* a, V2* b, float* direction) {
    float* constants = lbl_41_rodata_D50;
    __dynamic_cast(*(void**)(*(char**)(self + 0xd8) + 0x90), 0,
                   __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, 1);

    if (constants[2] == fn_41_10830(direction))
        return 3;

    V3 center, tmp;
    fn_41_5AC4(&center, constants[2], constants[2], constants[2]);
    getCenterPos__23emExternalValueAccesserFP5Enemy(
        &tmp, __dynamic_cast(*(void**)(self + 8), 0x3c,
                             __RTTI__5Enemy, __RTTI__11StageObject, 1));
    fn_41_534C(&center, &tmp);

    V2 pos;
    pos.set(center.x, center.y);
    V2 sum;
    fn_41_2354(&sum, a->x + b->x, a->y + b->y);
    Result s;
    Result r = fn_41_24110(&sum, &pos);
    s = r;

    float first = constants[5] * fn_41_15FB0(direction[1], direction[0]);
    float second = constants[5] * fn_41_15FB0(*(float*)&s.y, *(float*)&s.x);
    float diff = second - first;

    int ret;
    if (diff > constants[2]) {
        if ((float)(double)nw4r::math::FAbs(diff) <= constants[8])
            ret = 0;
        else
            ret = 1;
    } else if (diff < constants[2]) {
        if ((float)(double)nw4r::math::FAbs(diff) <= constants[8])
            ret = 1;
        else
            ret = 0;
    } else {
        ret = 2;
    }
    return ret;
}
}
