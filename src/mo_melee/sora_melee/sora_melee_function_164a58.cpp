#include <so/so_value_accesser.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}
extern "C" void fn_27_164A58(int, int, const Vec2f* in, soModuleAccesser* accesser) {
    float value = soValueAccesser::getConstantFloat(accesser, 0xDA2, 0);
    Vec3f first3(lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0);
    Vec2f first(lbl_27_rodata_1FC0, -value);
    fn_27_89D08(1, accesser, 0, &first, &first3);
    Vec3f second3(lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0);
    Vec2f second(in->m_x, lbl_27_rodata_1FC0);
    fn_27_89D08(3, accesser, 6, &second, &second3);
}