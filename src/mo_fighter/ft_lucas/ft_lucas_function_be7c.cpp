#include <ft/ft_common_data_accesser.h>
#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_114_data_3400[], lbl_114_data_3C7C[];
extern const float lbl_114_rodata_8, lbl_114_rodata_20;
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_114_15390(void* object, unsigned int taskId, int ownerId, const Vec3f* position, const Vec2f* velocity, float lr, float angle);
}

extern "C" int fn_114_BE7C(void* object, soModuleAccesser* accesser) {
    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(0x1a));
    const float* parameters = *reinterpret_cast<const float**>(reinterpret_cast<unsigned char*>(data) + 0x80);
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(accesser->m_stageObject, 0x3c,
        lbl_114_data_3400, lbl_114_data_3C7C, static_cast<short>(1)));
    Vec3f position = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0x39, false);
    float lr = accesser->m_enumerationStart->m_postureModule->getLr();
    float scale = accesser->m_enumerationStart->m_postureModule->getScale();
    position.m_x += lr * (parameters[4] * scale);
    position.m_y += parameters[5] * scale;
    position.m_z = lbl_114_rodata_8;
    float angle, speed;
    if (accesser->m_enumerationStart->m_situationModule->getKind() == 0) {
        angle = parameters[2];
        speed = parameters[3];
    } else {
        angle = parameters[0];
        speed = parameters[1];
    }
    Vec2f velocity;
    velocity.m_x = lr * (speed * static_cast<float>(cos(angle)));
    velocity.m_y = speed * static_cast<float>(sin(angle));
    angle = lbl_114_rodata_20 * -angle;
    unsigned int taskId = fighter->m_taskId;
    int ownerId = fn_27_111364(fighter->getOwner());
    fn_114_15390(object, taskId, ownerId, &position, &velocity, lr, angle);
    return 0;
}
