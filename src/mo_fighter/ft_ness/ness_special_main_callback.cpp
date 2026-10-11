#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/link/so_link_module_impl.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <math.h>

extern "C" double fn_101_CA34(double value);
extern "C" void fn_8003DBA8(Vec2f* vector);
extern "C" float fn_8003DDD0(const Vec2f* lhs, const Vec2f* rhs);

extern "C" void fn_101_11814(void*, soModuleAccesser* accesser)
{
    soWorkManageModule& work = accesser->getWorkManageModule();
    soSituationModule& situation = accesser->getSituationModule();
    soPostureModule& posture = accesser->getPostureModule();
    soStatusModule& status = accesser->getStatusModule();
    soGroundModule& ground = accesser->getGroundModule();
    soLinkModule& link = accesser->getLinkModule();

    if (!link.isLink(6)) {
        return;
    }

    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(10));
    const unsigned char* parameters =
        *reinterpret_cast<const unsigned char**>(reinterpret_cast<unsigned char*>(data) + 0x84);
    bool nearby = false;
    int state = work.getInt(0x20000003);
    work.getInt(0x20000004);
    float scale = posture.getScale();
    Vec3f position = posture.getPos();
    Vec3f parentPosition = link.getParentModelNodeGlobalPosition(6, static_cast<u32>(0), false);
    // Both queries are observable virtual calls, although only the first result is used.
    Vec3f parentAlternate = link.getParentModelNodeGlobalPosition(6, static_cast<u32>(0), true);
    position.m_y += 5.0f * scale;
    if (fn_101_CA34(position.m_x - parentPosition.m_x) < 8.333333f * scale &&
        fn_101_CA34(position.m_y - parentPosition.m_y) < 12.333333f * scale) {
        nearby = true;
    }

    switch (state) {
    case 0:
        if (nearby) {
            state = 2;
            Vec2f touchNormal;
            Vec2f displacement;
            displacement.m_x = position.m_x - parentPosition.m_x;
            displacement.m_y = position.m_y - parentPosition.m_y;
            float horizontalSign = displacement.m_x >= 0.0f ? 1.0f : -1.0f;
            float verticalSign = displacement.m_y >= 0.0f ? 1.0f : -1.0f;
            float facingAdjustedX = displacement.m_x * horizontalSign;
            float angle = atan2(displacement.m_y, facingAdjustedX);
            posture.setLr(horizontalSign);
            work.setFloat(verticalSign, 0x21000005);
            work.setFloat(angle, 0x21000004);
            work.offFlag(0x22000011);

            if (situation.getKind() == 0) {
                touchNormal = ground.getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0);
                fn_8003DBA8(&touchNormal);
                fn_8003DBA8(&displacement);
                float collisionAngle = fn_8003DDD0(&touchNormal, &displacement);
                if (collisionAngle < 1.5707963267948966f) {
                    work.onFlag(0x22000011);
                }
                float threshold = 0.017453292519943295f *
                    (90.0f + *reinterpret_cast<const float*>(parameters + 0x24));
                if (collisionAngle > threshold) {
                    status.changeStatusRequest(0x4A, accesser);
                } else {
                    status.changeStatusRequest(0x11C, accesser);
                }
            } else {
                work.onFlag(0x22000011);
                status.changeStatusRequest(0x11C, accesser);
            }
        }
        break;
    case 1:
        if (!nearby) {
            state = 0;
        }
        break;
    }
    work.setInt(state, 0x20000003);
}
