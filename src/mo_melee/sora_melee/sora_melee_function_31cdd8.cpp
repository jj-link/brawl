#pragma force_active on
#include <nw4r/math/math_arithmetic.h>

class WorkModule {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual float getFloat(int id);
    virtual void setFloat(int id, float value);
};
class OtherModule {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12();
    virtual long long getPos(short* pos);
};
struct Controller {
    char pad0[0x64]; WorkModule* work; char pad1[0x14]; OtherModule* other;
};
struct Params {
    char pad0[0x9C]; float lo; float hi; float max; float scale;
};
struct Obj {
    char pad0[8]; void* castSource; char pad1[0xCC]; Controller* controller;
};
extern "C" {
extern const float lbl_27_rodata_74F0[];
extern const char lbl_27_data_48E80[];
extern const char lbl_27_data_248[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
extern "C" void fn_27_31CDD8(void*, Obj* obj) {
    const float* table = lbl_27_rodata_74F0;
    Params* params = *(Params**)((char*)__dynamic_cast(obj->castSource, 0x3C, lbl_27_data_48E80, lbl_27_data_248, 1) + 0x4870);
    Controller* controller = obj->controller;
    WorkModule* work = controller->work;
    OtherModule* other = controller->other;
    float angle = work->getFloat(0x21000001);
    float scale = work->getFloat(0x21000004);
    short position = -1;
    long long result = other->getPos(&position);
    float posFloat = nw4r::math::FAbs(*(float*)&result);
    if (posFloat >= params->lo && posFloat < params->hi) {
        float normalized = (posFloat - params->lo) / (params->hi - params->lo);
        float delta = table[15] - normalized;
        delta *= params->scale;
        if (table[0] == scale) scale = table[15];
        angle += delta * scale;
        if (angle > params->max) {
            scale = table[7];
            angle = params->max - (angle - params->max);
        } else if (angle < -params->max) {
            scale = table[15];
            angle = -params->max - (angle + params->max);
        }
    }
    work->setFloat(0x21000001, angle);
    work->setFloat(0x21000004, scale);
}