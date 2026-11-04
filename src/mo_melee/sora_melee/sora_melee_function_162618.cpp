#include <types.h>
#pragma force_active on

struct soModuleAccesser;
struct Vec2f {
    float x, y;
    Vec2f operator*(float s) const {
        Vec2f res = {x * s, y * s};
        return res;
    }
};
struct Vec3f { float x, y, z; };

extern "C" {
extern const float lbl_27_rodata_1FC0;
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, u32, u32);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

class Holder {
public:
    virtual void vf0();
    virtual void vf1();
    virtual Vec2f vf2();
    u32 pad4;
    Vec2f vec;
};

extern "C" void fn_27_162618(void* unused, char* self, Vec2f* pos, soModuleAccesser* acc) {
    Holder* h = (Holder*)(self + 0x140);
    float s = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xC7F, 0);
    h->vec = h->vf2() * s;
    Vec3f zero = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    fn_27_89D08(3, acc, 0, pos, &zero);
}
