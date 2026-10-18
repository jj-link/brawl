#include <ai/ai_mgr.h>
#include <ft/ft_manager.h>
#include <types.h>
#pragma force_active on

struct AiMgrSlots {
    char pad[0x4c];
    void* first[7];
    void* second[7];
};

extern "C" void fn_27_1F25C8(void* self, int playerNo, int flag);
extern "C" void fn_27_1FAD54(void* input);

extern "C" void fn_27_1F2468(void* self, int entryId) {
    int playerNo = g_ftManager->getPlayerNo(entryId);
    fn_27_1F25C8(self, playerNo, 1);
    if (playerNo < 0 || playerNo >= 7) {
        return;
    }
    AiMgrSlots* mgr = reinterpret_cast<AiMgrSlots*>(g_aiMgr);
    if (mgr->first[playerNo] != NULL) {
        fn_27_1FAD54(mgr->first[playerNo]);
    }
    mgr = reinterpret_cast<AiMgrSlots*>(g_aiMgr);
    if (mgr->second[playerNo] != NULL) {
        fn_27_1FAD54(mgr->second[playerNo]);
    }
}
