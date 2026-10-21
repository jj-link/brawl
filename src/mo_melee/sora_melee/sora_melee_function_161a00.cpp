#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
void* __memcpy(void*, const void*, unsigned long);
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

static inline void setVector(Vec2f& v, float x, float y) {
    v.m_x = x;
    v.m_y = y;
}

extern "C" void fn_27_161A00(int, int, const Vec2f* input,
                           soModuleAccesser* accesser) {
    Vec2f speed;
    __memcpy(&speed, input, sizeof(speed));
    speed.m_x = lbl_27_rodata_1FC0;
    speed.m_y = soValueAccesser::getConstantFloat(accesser, 0xBF2, 0) *
        accesser->getWorkManageModule().getFloat(0x21000004);

    Vec3f zero2;
    Vec2f motion;
    Vec3f zero1(lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0);
    Vec2f gravity(lbl_27_rodata_1FC0, speed.m_y);
    fn_27_89D08(1, accesser, 0, &gravity, &zero1);

    zero2.m_x = lbl_27_rodata_1FC0;
    zero2.m_y = lbl_27_rodata_1FC0;
    zero2.m_z = lbl_27_rodata_1FC0;
    setVector(motion, speed.m_x, lbl_27_rodata_1FC0);
    fn_27_89D08(2, accesser, 0, &motion, &zero2);
}
