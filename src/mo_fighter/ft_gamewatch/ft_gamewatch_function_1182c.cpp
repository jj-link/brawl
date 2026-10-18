#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
extern const float lbl_107_rodata_38;
extern const char lbl_107_data_8E20[], lbl_107_data_8E64[], lbl_107_data_3B18[];

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_107_B444(Vec3f*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
Vec2f* fn_107_EF04(Vec2f*, const Vec2f*);
}

extern "C" void fn_107_1182C(void*, int, const Vec2f* input,
                           soModuleAccesser* accesser) {
    const char* data = *reinterpret_cast<const char**>(
        static_cast<char*>(getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 0x12)) + 0xb8);

    Vec2f speed(input->m_x, lbl_107_rodata_38);
    Vec3f rotation;
    fn_27_89D08(2, accesser, 15, &speed, fn_107_B444(&rotation,
        lbl_107_rodata_38, lbl_107_rodata_38, lbl_107_rodata_38));

    Vec2f gravitySpeed(lbl_107_rodata_38, input->m_y);
    Vec3f gravityRotation;
    fn_27_89D08(1, accesser, 2, &gravitySpeed, fn_107_B444(&gravityRotation,
        lbl_107_rodata_38, lbl_107_rodata_38, lbl_107_rodata_38));

    char* control = static_cast<char*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(2), 0,
        lbl_107_data_8E20, lbl_107_data_3B18, 1));

    Vec2f limit(*reinterpret_cast<const float*>(data + 0x19c),
                lbl_107_rodata_38);
    fn_107_EF04(reinterpret_cast<Vec2f*>(control + 0x20), &limit);

    *reinterpret_cast<float*>(control + 0x3c) =
        *reinterpret_cast<const float*>(data + 0x194);
    *reinterpret_cast<float*>(control + 0x40) = lbl_107_rodata_38;

    char* gravity = static_cast<char*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0,
        lbl_107_data_8E64, lbl_107_data_3B18, 1));

    *reinterpret_cast<float*>(gravity + 0x10) =
        *reinterpret_cast<const float*>(data + 0x18c);
    *reinterpret_cast<float*>(gravity + 0x14) =
        *reinterpret_cast<const float*>(data + 0x190);
    *reinterpret_cast<float*>(gravity + 0x18) =
        *reinterpret_cast<const float*>(data + 0x6c);
    *reinterpret_cast<float*>(gravity + 0x1c) =
        *reinterpret_cast<const float*>(data + 0x70);
}
