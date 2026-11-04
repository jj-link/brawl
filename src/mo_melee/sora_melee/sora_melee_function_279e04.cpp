#include <gr/gr_madein.h>
#include <ft/ft_manager.h>
#include <st/st_melee.h>
#include <mt/mt_vector.h>
#pragma force_active on

void grMadein::onInflictEach(soCollisionLog* collisionLog, float power) {
    Vec3f pos = getPos();
    Vec3f playerPos;
    ftManager* manager = g_ftManager;
    int entryId = manager->getEntryIdFromTaskId(collisionLog->m_taskId, 0);
    if (entryId != -1) {
        *(int*)((char*)m_attackInfo + 0x24) = manager->getPlayerNo(entryId);
        if (stMelee::getPlayerPosition(*(int*)((char*)m_attackInfo + 0x24), &playerPos) == true) {
            Vec3f copy(pos);
            *(float*)((char*)m_attackInfo + 0x20) = power;
            *((char*)m_attackInfo + 0x1c + *(int*)((char*)m_attackInfo + 0x24)) = 1;
            Vec3f difference;
            Vec3fSub(&difference, &copy, &playerPos);
            *(Vec3f*)((char*)m_attackInfo + 0x10) = difference;
        }
    }
}
