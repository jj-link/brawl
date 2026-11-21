#include <so/so_module_accesser.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_1FC0;

float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

extern "C" void fn_27_164504(
    void*, void*, const Vec2f* input, soModuleAccesser* accesser) {
    Vec2f vec2(input->m_x, lbl_27_rodata_1FC0);
    Vec3f vec3;

    float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xBD5, 0);

    if ((float)(double)nw4r::ut::Abs(vec2.m_x) > c) {
        if (vec2.m_x < lbl_27_rodata_1FC0)
            c = -c;
        vec2.m_x = c;
    }

    vec3.m_x = lbl_27_rodata_1FC0;
    vec3.m_y = lbl_27_rodata_1FC0;
    vec3.m_z = lbl_27_rodata_1FC0;

    fn_27_89D08(2, accesser, 0xF, &vec2, &vec3);
}
