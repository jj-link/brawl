#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_1FC0;
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

extern "C" void fn_27_163248(
    void*, void*, void*, soModuleAccesser* accesser) {
    Vec2f vec2;
    Vec3f vec3;

    vec3.m_x = lbl_27_rodata_1FC0;
    vec3.m_y = lbl_27_rodata_1FC0;
    vec3.m_z = lbl_27_rodata_1FC0;

    float value = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xBE7, 0);

    vec2.m_y = value;
    vec2.m_x = lbl_27_rodata_1FC0;

    fn_27_89D08(1, accesser, 0, &vec2, &vec3);
}
