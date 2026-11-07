#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
extern const float lbl_95_rodata_120;
extern const char lbl_95_data_810C[], lbl_95_data_81D8[], lbl_95_data_2C38[];

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_95_ABB4(Vec3f*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void fn_95_DF08(Vec2f*, const Vec2f*);
}

extern "C" void fn_95_14748(void*, int, const Vec2f* input, soModuleAccesser* accesser) {
    Vec2f a(lbl_95_rodata_120, input->m_y);
    Vec3f r1;
    fn_27_89D08(1, accesser, 0, &a, fn_95_ABB4(&r1, lbl_95_rodata_120, lbl_95_rodata_120, lbl_95_rodata_120));

    Vec2f b(input->m_x, lbl_95_rodata_120);
    Vec3f r2;
    fn_27_89D08(2, accesser, 0, &b, fn_95_ABB4(&r2, lbl_95_rodata_120, lbl_95_rodata_120, lbl_95_rodata_120));

    const char* data = *reinterpret_cast<const char**>(
        static_cast<char*>(getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 4)) + 0x7c);

    char* gravity = static_cast<char*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0, lbl_95_data_810C, lbl_95_data_2C38, 1));
    char* control = static_cast<char*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(2), 0, lbl_95_data_81D8, lbl_95_data_2C38, 1));

    *reinterpret_cast<float*>(control + 0x3c) = *reinterpret_cast<const float*>(data + 0x98);
    Vec2f c(*reinterpret_cast<const float*>(data + 0x48), lbl_95_rodata_120);
    fn_95_DF08(reinterpret_cast<Vec2f*>(control + 0x28), &c);
    Vec2f d(*reinterpret_cast<const float*>(data + 0x44), lbl_95_rodata_120);
    fn_95_DF08(reinterpret_cast<Vec2f*>(control + 0x18), &d);

    *reinterpret_cast<float*>(gravity + 0x10) = -*reinterpret_cast<const float*>(data + 0x24);
    *reinterpret_cast<float*>(gravity + 0x1c) = *reinterpret_cast<const float*>(data + 0x28);
    *reinterpret_cast<float*>(gravity + 0x14) = *reinterpret_cast<const float*>(data + 0x28);
}
