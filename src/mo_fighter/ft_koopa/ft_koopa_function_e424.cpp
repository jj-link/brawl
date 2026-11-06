#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_102_data_6014[], lbl_102_data_5D8C[], lbl_102_data_14F4[];
extern const float lbl_102_rodata_2C;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_102_E124(soModuleAccesser*);
Vec3f* fn_102_C5B8(Vec3f*, float, float, float);
void fn_102_B024(void*, const Vec2f*);
}

static inline Vec2f* temporaryVector(const Vec2f& v) {
    return const_cast<Vec2f*>(&v);
}

extern "C" void fn_102_E424(void*, soModuleAccesser* accesser) {
    float* data = *reinterpret_cast<float**>(
        reinterpret_cast<char*>(g_ftCommonDataAccesser.getData(static_cast<ftKind>(11))) + 0x88);
    accesser->getSituationModule().setKind(static_cast<SituationKind>(2), false);
    accesser->getGroundModule().setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(5), 0);
    fn_102_E124(accesser);

    soKineticEnergy* control = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(0), 0,
        lbl_102_data_6014, lbl_102_data_14F4, 1));
    Vec3f rotation;
    control->resetEnergy(6,
        temporaryVector(Vec2f(lbl_102_rodata_2C, lbl_102_rodata_2C)),
        fn_102_C5B8(&rotation, lbl_102_rodata_2C, lbl_102_rodata_2C, lbl_102_rodata_2C),
        accesser);
    reinterpret_cast<unsigned char*>(control)[5] |= 0x80;

    soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0,
        lbl_102_data_5D8C, lbl_102_data_14F4, 1));
    float stick = accesser->getControllerModule().getStickX();
    float speed = data[0] * accesser->getPostureModule().getLr() + data[1] * stick;
    Vec3f rotation2;
    stop->resetEnergy(0x16,
        temporaryVector(Vec2f(speed, lbl_102_rodata_2C)),
        fn_102_C5B8(&rotation2, lbl_102_rodata_2C, lbl_102_rodata_2C, lbl_102_rodata_2C),
        accesser);
    fn_102_B024(reinterpret_cast<char*>(stop) + 0x18,
        temporaryVector(Vec2f(data[9], lbl_102_rodata_2C)));
    fn_102_B024(reinterpret_cast<char*>(stop) + 0x28,
        temporaryVector(Vec2f(data[9], lbl_102_rodata_2C)));
    reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;
    accesser->getWorkManageModule().onFlag(0x12000001);
}
