#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

extern "C" void fn_27_160BF0(int, int, const Vec2f* in, soModuleAccesser* accesser) {
    Vec3f r1(lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0);
    Vec2f a(lbl_27_rodata_1FC0, in->m_y);
    fn_27_89D08(1, accesser, 0, &a, &r1);
    Vec3f r2(lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0);
    Vec2f b(in->m_x, lbl_27_rodata_1FC0);
    fn_27_89D08(2, accesser, 0, &b, &r2);
}