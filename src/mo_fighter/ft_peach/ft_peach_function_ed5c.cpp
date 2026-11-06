#pragma force_active on
#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_vector.h>
#include <so/so_value_accesser.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/kinetic/so_kinetic_energy.h>

extern "C" {
extern const float lbl_103_rodata_14;
Vec2f* fn_103_C174(Vec2f*, const Vec2f*);
void fn_103_ED24(soKineticEnergy* energy, soModuleAccesser* accesser);
}

extern "C" void fn_103_ED5C(soKineticEnergy* energy, void* unused, soModuleAccesser* accesser) {
    float f31 = (float)(double)nw4r::math::FAbs(accesser->m_enumerationStart->m_controllerModule->getStickX());
    if (f31 >= soValueAccesser::getConstantFloat(accesser, 0xC49, 0)) {
        float a = soValueAccesser::getConstantFloat(accesser, 0xFB9, 0);
        float c = soValueAccesser::getConstantFloat(accesser, 0xBD3, 0);
        *(float*)((char*)energy + 0x3c) = c * a;
        float b = soValueAccesser::getConstantFloat(accesser, 0xFB9, 0);
        Vec2f v;
        float d = soValueAccesser::getConstantFloat(accesser, 0xBD5, 0);
        v.m_x = d * b;
        v.m_y = lbl_103_rodata_14;
        fn_103_C174((Vec2f*)((char*)energy + 0x18), &v);
    } else {
        Vec2f z1;
        z1.m_x = lbl_103_rodata_14;
        z1.m_y = lbl_103_rodata_14;
        fn_103_C174((Vec2f*)((char*)energy + 0x10), &z1);
        Vec2f z2;
        z2.m_x = lbl_103_rodata_14;
        z2.m_y = lbl_103_rodata_14;
        fn_103_C174((Vec2f*)((char*)energy + 0x18), &z2);
    }
    fn_103_ED24(energy, accesser);
}
