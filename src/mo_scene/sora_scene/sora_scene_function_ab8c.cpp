#include <gf/gf_scene.h>
#include <gm/gm_global.h>
#include <mt/mt_prng.h>
#include <types.h>
#pragma force_active on

inline void init(s32* p, s32* a) { *p = -1; *a = -1; }

extern "C" int fn_1_AB8C(char* arg0) {
    char* task = *(char**)(arg0 + 8);
    int state = *(int*)(task + 0x48);
    switch (state) {
    case 1: {
        gfSceneManager* mgr = gfSceneManager::getInstance();
        mgr->unk1 = 1;
        mgr->processStep = 2;
        s32 k = 0;
        u8 n = *(u8*)g_GameGlobal->m_tournamentData;
        s32 arr[16];
        char* p = (char*)g_GameGlobal->m_tournamentData;
        for (int i = 0; i < 16; i++) {
            *(s32*)(p + 0x28 + i * 0x28) = -1;
            arr[i] = -1;
        }
        while (k < n) {
            s32 idx;
            do { idx = randi(n); } while (arr[idx] != -1);
            arr[idx] = k;
            k++;
        }
        char* q = p + 8;
        s32* src = arr;
        for (s32 i = 0; i < 16; i++) {
            if (*(u8*)q == 0) {
                *(s32*)(q + 0x20) = *src++;
            }
            q += 0x28;
        }
        break;
    }
    case 2: {
        gfSceneManager* mgr = gfSceneManager::getInstance();
        mgr->unk1 = 0;
        mgr->processStep = 2;
        break;
    }
    }
    return 0;
}