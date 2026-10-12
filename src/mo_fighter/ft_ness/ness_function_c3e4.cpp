#include <ft/ft_common_data_accesser.h>
#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#include <math.h>

extern "C" {
extern const unsigned char lbl_101_data_3AB4[], lbl_101_data_4330[];
extern const float lbl_101_rodata_8, lbl_101_rodata_20;
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_101_15838(void*, unsigned int, int, const Vec3f*, const Vec2f*, float, float);
}

extern "C" int fn_101_C3E4(void* object, soModuleAccesser* accesser) {
    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(10));
    const float* parameters = *reinterpret_cast<const float**>(reinterpret_cast<unsigned char*>(data) + 0x80);
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(&accesser->getStageObject(), 0x3c,
        lbl_101_data_3AB4, lbl_101_data_4330, static_cast<short>(1)));
    Vec3f position = accesser->getModelModule().getNodeGlobalPosition(0x3b, false);
    float lr = accesser->getPostureModule().getLr();
    float scale = accesser->getPostureModule().getScale();
    position.m_x += lr * (parameters[4] * scale);
    position.m_y += parameters[5] * scale;
    position.m_z = lbl_101_rodata_8;
    float angle, speed;
    if (accesser->getSituationModule().getKind() == 0) {
        angle = parameters[2];
        speed = parameters[3];
    } else {
        angle = parameters[0];
        speed = parameters[1];
    }
    Vec2f velocity;
    velocity.m_x = lr * (speed * static_cast<float>(cos(angle)));
    velocity.m_y = speed * static_cast<float>(sin(angle));
    angle = lbl_101_rodata_20 * -angle;
    unsigned int taskId = fighter->m_taskId;
    int ownerId = fn_27_111364(fighter->getOwner());
    fn_101_15838(object, taskId, ownerId, &position, &velocity, lr, angle);
    return 0;
}
