#include <types.h>
#pragma force_active on

extern "C" int fn_800BC8D4(void* p);

struct gfSceneManager {
    static void* getInstance();
};

extern "C" s32 fn_1_76C8(u8* self) {
    if (self[0xc] == 0) {
        u8* obj = *(u8**)(self + 8);
        if (*(s32*)(obj + 0x44) >= 2) {
            self[0xc] = 1;
        }
    }
    if (fn_800BC8D4(*(void**)(self + 8)) != 0) {
        u8* mgr = (u8*)gfSceneManager::getInstance();
        *(s32*)(mgr + 0x284) = 0;
        *(s32*)(mgr + 0x288) = 2;
    }
    return 0;
}
