#include <types.h>
#include <revolution/OS/OSError.h>
#pragma force_active on

struct Sub {
    char pad[0x50];
    s32 f50;
    char pad54[2];
    u8 f56;
    char pad57[3];
    u8 f5A;
    u8 f5B;
    char pad5C;
    u8 a : 4;
    u8 flag : 1;
    u8 b : 3;
};

struct LoaderManager {
    Sub* entries[7];
};

struct Player {
    u8 f0;
    char pad1[4];
    u8 f5;
    char pad6[0x56];
};

extern "C" LoaderManager* g_stLoaderManager;
extern "C" void* g_GameGlobal;
extern char lbl_1_data_25C[];

extern "C" s32 fn_1_3134(s32, u8, u8);

extern "C" void fn_1_32F8() {
    void* mode = *(void**)((char*)g_GameGlobal + 8);
    for (int i = 0; i < 7; ++i) {
        Sub* s = g_stLoaderManager->entries[i];
        if (s) {
            s->flag = 0;
        }
    }

    Player* init = (Player*)((char*)mode + 0x98);
    for (int i = 0; i < 4; i++) {
        OSReport(lbl_1_data_25C, i, init[i].f0, init[i].f5);
        s32 result = fn_1_3134(i, init[i].f0, init[i].f5);
        if (result != -1) {
            u8 t5A = g_stLoaderManager->entries[i]->f5A;
            u8 t5B = g_stLoaderManager->entries[i]->f5B;
            s32 t50 = g_stLoaderManager->entries[i]->f50;
            u8 t56 = g_stLoaderManager->entries[i]->f56;
            g_stLoaderManager->entries[i]->f5A = g_stLoaderManager->entries[result]->f5A;
            g_stLoaderManager->entries[i]->f5B = g_stLoaderManager->entries[result]->f5B;
            g_stLoaderManager->entries[i]->f50 = g_stLoaderManager->entries[result]->f50;
            g_stLoaderManager->entries[i]->f56 = g_stLoaderManager->entries[result]->f56;
            g_stLoaderManager->entries[result]->f5A = t5A;
            g_stLoaderManager->entries[result]->f5B = t5B;
            g_stLoaderManager->entries[result]->f50 = t50;
            g_stLoaderManager->entries[result]->f56 = t56;
        }
    }
}
