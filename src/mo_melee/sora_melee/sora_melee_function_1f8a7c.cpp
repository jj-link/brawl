#include <ai/ai_mgr.h>
#pragma force_active on

struct AiMgrFcView {
    char pad[0xFC];
    void* unkFC;
};

extern "C" void* fn_27_1F8A7C(void)
{
    return reinterpret_cast<AiMgrFcView*>(g_aiMgr)->unkFC;
}
