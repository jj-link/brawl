#include <ft/ft_manager.h>
#include <types.h>
#pragma force_active on

extern "C" int fn_27_10A0C4(ftManager* self, int entryId);

struct FighterTeamInfo {
    int _0;
    int _4;
    int m_entryId;
    int m_team;
    int m_unk;
};

extern "C" void fn_27_140398(FighterTeamInfo* obj) {
    obj->m_team = g_ftManager->getTeam(obj->m_entryId, true, true);
    obj->m_unk = fn_27_10A0C4(g_ftManager, obj->m_entryId);
}
