#pragma always_inline on
#include <nw4r/math/math_arithmetic.h>
#include <revolution/mtx.h>
#pragma force_active on
extern "C" const float lbl_41_rodata_8;
extern "C" const float lbl_41_rodata_28;
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec slot4();
};
struct Access { char padding[0xC]; Object_vptr_0* object; };
struct Self { char padding[0xD0]; float x; float y; char padding2[0xDC]; Access* access; };
extern "C" int fn_41_5580(Self* self) {
    int result = 1;
    if (lbl_41_rodata_8 != self->x) {
        const Vec& pos = self->access->object->slot4();
        float distance = (float)(double)nw4r::math::FAbs(self->x - pos.x);
        if (lbl_41_rodata_28 < distance) {
            result = 0;
        }
    }
    if (lbl_41_rodata_8 != self->y) {
        const Vec& pos = self->access->object->slot4();
        float distance = (float)(double)nw4r::math::FAbs(self->y - pos.y);
        if (lbl_41_rodata_28 < distance) {
            result = 0;
        }
    }
    return result;
}