#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void* __memcpy(void*, const void*, unsigned long);
extern unsigned char g_ftCommonDataAccesser[];
extern const float lbl_107_rodata_38;
extern const float lbl_107_rodata_3C;
extern const char lbl_107_data_8E20[], lbl_107_data_8E64[], lbl_107_data_3B18[];

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_107_B444(Vec3f*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void fn_107_EF04(Vec2f*, const Vec2f*);
}

extern "C" void fn_107_1111C(void*, int, const Vec2f* input,
                           soModuleAccesser* accesser) {
    Vec2f speed;
    __memcpy(&speed, input, sizeof(speed));

    const char* data = *reinterpret_cast<const char**>(
        static_cast<char*>(getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 0x12)) + 0xb8);

    const float scale = *reinterpret_cast<const float*>(data + 0x4c);
    speed.m_x = scale * accesser->getControllerModule().getStickX();
    const float rate = *reinterpret_cast<const float*>(data + 0x48);
    speed.m_y = *reinterpret_cast<const float*>(data + 0x38) * rate;

    Vec2f gravitySpeed(lbl_107_rodata_38, speed.m_y);
    Vec3f gravityRotation;
    fn_27_89D08(1, accesser, 0, &gravitySpeed, fn_107_B444(&gravityRotation,
        lbl_107_rodata_38, lbl_107_rodata_38, lbl_107_rodata_38));

    Vec2f motion(speed.m_x, lbl_107_rodata_38);
    Vec3f rotation;
    fn_27_89D08(2, accesser, 0, &motion, fn_107_B444(&rotation,
        lbl_107_rodata_38, lbl_107_rodata_38, lbl_107_rodata_38));

    char* gravity = static_cast<char*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0,
        lbl_107_data_8E64, lbl_107_data_3B18, 1));
    *reinterpret_cast<float*>(gravity + 0x10) =
        -*reinterpret_cast<const float*>(data + 0x64);
    *reinterpret_cast<float*>(gravity + 0x14) =
        *reinterpret_cast<const float*>(data + 0x68);
    *reinterpret_cast<float*>(gravity + 0x18) =
        *reinterpret_cast<const float*>(data + 0x6c);
    *reinterpret_cast<float*>(gravity + 0x1c) =
        *reinterpret_cast<const float*>(data + 0x70);

    char* control = static_cast<char*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(2), 0,
        lbl_107_data_8E20, lbl_107_data_3B18, 1));

    Vec2f a(*reinterpret_cast<const float*>(data + 0x7c), lbl_107_rodata_3C);
    fn_107_EF04(reinterpret_cast<Vec2f*>(control + 0x18), &a);

    Vec2f b(*reinterpret_cast<const float*>(data + 0x80), lbl_107_rodata_38);
    fn_107_EF04(reinterpret_cast<Vec2f*>(control + 0x20), &b);

    Vec2f c(*reinterpret_cast<const float*>(data + 0x88), lbl_107_rodata_38);
    fn_107_EF04(reinterpret_cast<Vec2f*>(control + 0x28), &c);

    *reinterpret_cast<float*>(control + 0x3c) =
        *reinterpret_cast<const float*>(data + 0x74);
    *reinterpret_cast<float*>(control + 0x40) =
        *reinterpret_cast<const float*>(data + 0x78);
}
