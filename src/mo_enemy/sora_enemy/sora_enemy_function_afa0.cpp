#include <types.h>
#pragma force_active on

class emManager {
public:
    static emManager* getInstance();
    void* getEnemyPtrFromId(int id);
};

extern void* g_stTriggerMng;
extern "C" void* fn_27_233264(void* mgr, u32 kind, s32 r5, s32 count);
extern "C" void fn_41_B1E8(void* a, void* b, void* c, s32 d, s32 e);

extern "C" void fn_41_AFA0(void* p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6) {
    void* id = fn_27_233264(g_stTriggerMng, p2, p3, p6);
    void* ptr = emManager::getInstance()->getEnemyPtrFromId((int)id);
    if (ptr == nullptr) {
        return;
    }
    if (p5 > 0 && p4 != 0) {
        fn_41_B1E8(p1, p1, ptr, p4, p5);
    }
    *(s32*)((u8*)ptr + 0xC8) = *(s32*)((u8*)p1 + 0xC8);
}
