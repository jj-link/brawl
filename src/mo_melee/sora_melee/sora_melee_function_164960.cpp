#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

extern "C" void fn_27_164960(int, int, const Vec2f* input,
                            soModuleAccesser* accesser) {
    float speed = soValueAccesser::getConstantFloat(accesser, 0x7F9, 0) +
        accesser->getWorkManageModule().getFloat(0x21000001) *
        soValueAccesser::getConstantFloat(accesser, 0x7F8, 0);
    speed *= -accesser->getWorkManageModule().getFloat(0x21000002);

    Vec3f zero(lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0);
    Vec2f motion(speed, input->m_y);
    fn_27_89D08(3, accesser, 0, &motion, &zero);
}
