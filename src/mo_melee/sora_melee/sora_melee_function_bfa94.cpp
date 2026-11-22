#include <types.h>
#include <GX/GXTypes.h>
#pragma force_active on

extern "C" void fn_27_C137C(void*, float*, u32, float);

inline void* select_target(void* obj, unsigned int index) {
    if (index == 1)
        return static_cast<char*>(obj) + 0xB8;
    return static_cast<char*>(obj) + 0x30;
}

struct FloatColor {
    float values[4];
    FloatColor(GXColor color) {
        values[0] = (float)color.r;
        values[1] = (float)color.g;
        values[2] = (float)color.b;
        values[3] = (float)color.a;
    }
};

extern "C" void fn_27_BFA94(void* obj, const GXColor* color,
                            unsigned int index, float unused) {
    FloatColor local(*color);
    fn_27_C137C(select_target(obj, index), local.values, index, unused);
}
