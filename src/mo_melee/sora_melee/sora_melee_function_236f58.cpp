#include <types.h>
#include <ft/ft_manager.h>
#pragma force_active on

extern "C" s32 fn_27_10B224(ftManager* manager, void* base, s32* ids, void* buf, s32 flag);

struct FnArg {
    u8 pad0[0x8];
    u8* flag;
    u8 pad1[0x4];
    u8 base[0x10];
    s32 playerNo;
    u8 flag2;
};

extern "C" void fn_27_236F58(FnArg* arg) {
    s32 ids[16];
    u8 buf[0xC0];
    if (g_ftManager != NULL) {
        s32 count = fn_27_10B224(g_ftManager, arg->base, ids, buf, 0);
        for (s32 i = 0; i < count; i++) {
            if (arg->playerNo == g_ftManager->getPlayerNo(ids[i])) {
                *arg->flag = 1;
            }
        }
        if (arg->flag2 != 0) {
            for (s32 i = 0; i < count; i++) {
                if (g_ftManager->getPlayerNo(ids[i]) == 1) {
                    *arg->flag = 1;
                }
            }
        }
    }
}
