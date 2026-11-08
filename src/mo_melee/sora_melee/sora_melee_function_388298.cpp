#include <nw4r/math/math_arithmetic.h>
#include <types.h>
#pragma force_active on
struct PairFloat { float x; float y; float z; };
class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual PairFloat slot4();
    virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
    virtual void slot13(u32, float);
    virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17();
    virtual void slot18(u32); virtual void slot19(); virtual void slot20(u32, u32);
};
struct Device_388298 { char pad0[0xC]; Object_vptr_0* query; char pad10[0x54]; Object_vptr_0* module; };
struct Owner_388298 { char pad0[0xD8]; Device_388298* device; };
extern "C" const float lbl_27_rodata_7C78[];
static inline float clampRange(float v, float lo, float hi) {
    float t = nw4r::math::FSelect(v - lo, v, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}
extern "C" void fn_27_388298(void* arg0, Owner_388298* arg1, float farg0, float farg1, float farg2) {
    const float* c = lbl_27_rodata_7C78;
    if (farg0 != farg1) {
        const PairFloat& result = arg1->device->query->slot4();
        if ((float)(double)nw4r::math::FAbs(farg1 - farg0) <= c[16] * farg2) {
            arg1->device->module->slot13(0x1100001D, c[5]);
            arg1->device->module->slot13(0x1100001F, c[7]);
            arg1->device->module->slot13(0x1100001E, c[5]);
            arg1->device->module->slot18(0x12000041);
        } else {
            float low = farg0 + farg2;
            float high = farg1 - farg2;
            float span = high - low;
            float t = c[17];
            if (c[5] != span) t = (result.x - low) / span;
            float clamped = clampRange(t, c[5], c[7]);
            arg1->device->module->slot13(0x1100001D, clamped);
            if (clamped < c[17])
                arg1->device->module->slot13(0x1100001F, c[6]);
            else
                arg1->device->module->slot13(0x1100001F, c[7]);
            float delta = clamped < c[17] ? result.x - low : high - result.x;
            float value = clampRange(delta, c[5], delta);
            arg1->device->module->slot13(0x1100001E, value);
            unsigned char flag = *(unsigned char*)((char*)arg0 + 0xA);
            arg1->device->module->slot20((flag >> 4) & 1, 0x12000041);
        }
    }
}