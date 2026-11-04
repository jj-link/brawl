#pragma force_active on
#include <gm/gm_global.h>
#include <gm/gm_result_info.h>
#include <snd/snd_system.h>
#include <mu/mu_msg.h>
#include <mu/menu.h>

extern const char* lbl_8059E348;
extern char* lbl_8045B650[][2];
extern "C" char* fn_800AFA8C();

extern "C" void fn_800E7BD0(void* self) {
    gmResultInfo* resultInfo = g_GameGlobal->m_resultInfo;

    g_sndSystem->playSE((SndID)0x1EF1, -1, 0, 0, -1);
    if (*(u8*)((char*)resultInfo + 0x1378) == gmResultInfo::Decision_NoContest) {
        (*(MuMsg**)((char*)self + 0x654))->printf(0, lbl_8059E348);
        return;
    }
    if (!resultInfo->m_isTeams) {
        muMenu::exchangeGmCharacterKind2MuStockchkind(
            *(u8*)((char*)&resultInfo->m_playersResultInfo[*(int*)((char*)self + 0xB8)]));
        (*(MuMsg**)((char*)self + 0x654))->printf(0, fn_800AFA8C());
        return;
    }
    (*(MuMsg**)((char*)self + 0x654))->printf(0, lbl_8045B650[*(int*)((char*)self + 0xBC)][0]);
}
