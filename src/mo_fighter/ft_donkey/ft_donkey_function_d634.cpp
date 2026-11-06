#include <ft/ft_common_data_accesser.h>
#include <gr/collision/gr_collision_status.h>
#include <mt/mt_vector.h>
#include <so/so_module_accesser.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" void fn_92_D634(void*, soModuleAccesser* accesser)
{
    soCollisionAttackModule& attack = accesser->getCollisionAttackModule();
    soWorkManageModule& work = accesser->getWorkManageModule();
    soPostureModule& posture = accesser->getPostureModule();
    soGroundModule& ground = accesser->getGroundModule();

    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(1));
    const float* values = *reinterpret_cast<const float* const*>(reinterpret_cast<const unsigned char*>(data) + 0x88);

    Vec3f pos = posture.getPos();
    float scale = posture.getLr();

    if (work.isFlag(0x22000011)) {
        work.offFlag(0x22000011);
        if (ground.isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) {
            for (int i = 0; i < 4; i++) {
                if (attack.isAttack(i, false)) {
                    float term = values[1] * scale;
                    float offset = values[0] * (float)i - 1.5f * values[0];
                    offset += term;
                    offset *= posture.getScale();
                    Vec3f adjusted = pos;
                    Vec3f down;
                    down.m_x = 0.0f;
                    down.m_y = -2.0f;
                    down.m_z = 0.0f;
                    adjusted.m_x += offset;
                    if (ground.getDownCorrectPos(&adjusted, &down, 0) == 0) {
                        adjusted = pos;
                    }
                    adjusted.m_y += 2.0f;
                    Vec3fSub(&adjusted, &adjusted, &pos);
                    Vec3f v;
                    v.m_x = adjusted.m_z;
                    v.m_y = adjusted.m_y;
                    v.m_z = adjusted.m_x * scale;
                    attack.setOffset(i, &v);
                }
            }
        }
    }
}
