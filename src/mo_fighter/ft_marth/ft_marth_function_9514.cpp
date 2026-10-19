#include <types.h>
#pragma force_active on

struct Vec2F {
    float x;
    float y;
};

extern "C" {
extern const float lbl_106_rodata_8;
void fn_106_954C(Vec2F* dst, const Vec2F* src);

void fn_106_9514(Vec2F* value) {
    Vec2F temp;
    temp.x = lbl_106_rodata_8;
    temp.y = lbl_106_rodata_8;
    fn_106_954C(value + 1, &temp);
}
}
