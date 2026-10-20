#include <so/so_module_accesser.h>
#pragma force_active on

struct SnakeParameters {
    char pad[0x24];
    float speedY;
    float accelerationY;
    float brakeY;
    int duration;
};

struct SnakeObject {
    char pad[0x60];
    soModuleAccesser* accesser;
    char pad64[0x221c - 0x64];
    SnakeParameters* parameters;
};

extern "C" {
extern const unsigned char lbl_122_data_D658[], lbl_122_data_81AC[];
extern const float lbl_122_rodata_F0;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_122_1D380(SnakeObject*);
Vec3f* fn_122_D580(Vec3f*, float, float, float);
Vec2f* fn_122_145AC(Vec2f*, float, float);
void fn_122_12CC4(Vec2f*, const Vec2f*);

void fn_122_1D0D4(SnakeObject* object, const Vec2f* input) {
    if (object->accesser->getStatusModule().getStatusKind() == 2 ||
        object->accesser->getStatusModule().getStatusKind() == 3)
        return;

    fn_122_1D380(object);
    object->accesser->getWorkManageModule().setInt(
        object->parameters->duration, 0x10000005);
    object->accesser->getStatusModule().changeStatusForce(
        2, object->accesser);

    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        object->accesser->getKineticModule().getEnergy(0), 0,
        lbl_122_data_D658, lbl_122_data_81AC, static_cast<short>(1)));

    Vec3f rotation;
    Vec2f speed;
    energy->resetEnergy(
        0,
        fn_122_145AC(&speed, input->m_x, object->parameters->speedY),
        fn_122_D580(&rotation, lbl_122_rodata_F0,
                    lbl_122_rodata_F0, lbl_122_rodata_F0),
        object->accesser);

    Vec2f acceleration(lbl_122_rodata_F0, object->parameters->accelerationY);
    fn_122_12CC4((Vec2f*)((char*)energy + 0x10), &acceleration);

    Vec2f brake(lbl_122_rodata_F0, object->parameters->brakeY);
    fn_122_12CC4((Vec2f*)((char*)energy + 0x18), &brake);

    object->accesser->getWorkManageModule().offFlag(0x12000000);
    object->accesser->getLinkModule().setAttribute(
        3, static_cast<soLinkConnection::Attribute>(12), false);
}
}
