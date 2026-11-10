#include <so/so_module_accesser.h>
#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);

void fn_27_16445C(int, int, const Vec2f* in, soModuleAccesser* accesser) {
    Vec3f r1(lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0);
    Vec2f a(in->m_x, lbl_27_rodata_1FC0);
    fn_27_89D08(2, accesser, 0xf, &a, &r1);
    Vec3f r2(lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0);
    Vec2f b(lbl_27_rodata_1FC0, in->m_y);
    fn_27_89D08(1, accesser, 2, &b, &r2);
}
}
