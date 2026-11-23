#include <ft/ft_manager.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/so_external_value_accesser.h>
#include <mt/mt_common.h>
#include <mt/mt_vector.h>
#include <orch_helpers.h>
#pragma force_active on

extern "C" int fn_27_1125B0(ftOwner*);
extern "C" const float lbl_27_rodata_26B0;
extern "C" const float lbl_27_rodata_26C0;

extern "C" float fn_27_194828(
    soModuleAccesser* accesser,
    unsigned long a,
    unsigned long b,
    unsigned long c
) {
    if (fn_27_1125B0(g_ftManager->getOwner(
            accesser->m_enumerationStart->m_workManageModule->getInt(0x10000000))) == 1) {
        int id = g_ftManager->getEntryId(0);
        if (g_ftManager->isValidEntryId(id) == 1) {
            float radius = soValueAccesser::getConstantFloat(accesser, a, 0);
            if (lbl_27_rodata_26B0 != radius) {
                const Vec3f target =
                    soExternalValueAccesser::getPos(g_ftManager->getFighter(id, -1));
                Vec3f diff;
                const Vec3f pos = accesser->m_enumerationStart->m_postureModule->getPos();
                Vec3fSub_v0420ad(&diff, &target, &pos);
                float radiusSq = radius * radius;
                float ySq = diff.m_y * diff.m_y;
                float xSq = diff.m_x * diff.m_x;
                float distSq = xSq + ySq;
                if (distSq > radiusSq) {
                    float dist = mtSqrtf(distSq);
                    float maxDist = soValueAccesser::getConstantFloat(accesser, b, 0);
                    float value = soValueAccesser::getConstantFloat(accesser, c, 0);
                    if (dist > maxDist) {
                        return value;
                    }
                    return lbl_27_rodata_26C0 +
                        (value - lbl_27_rodata_26C0) *
                        ((dist - radius) / (maxDist - radius));
                }
            }
        }
    }
    return lbl_27_rodata_26C0;
}
