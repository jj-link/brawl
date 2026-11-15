#include <types.h>
#include <GX/GXTypes.h>
#pragma force_active on

extern "C" void fn_27_C1168(void*, float*);

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

struct Target {
    char pad[0x78];
    float f1;
    float f2;
    u8 flag;
};

extern "C" void fn_27_BFB58(void* obj, const GXColor* color, u8 flag,
                            unsigned int index, float f1, float f2) {
    FloatColor local(*color);
    fn_27_C1168(static_cast<char*>(select_target(obj, index)) + 0x3C,
                local.values);
    Target* target = static_cast<Target*>(select_target(obj, index));
    target->f1 = f1;
    target->f2 = f2;
    target->flag = flag;
}
