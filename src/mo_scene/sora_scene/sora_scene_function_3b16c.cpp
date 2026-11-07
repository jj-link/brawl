#include <gf/gf_scene.h>
#include <gm/gm_global.h>
#pragma force_active on
extern "C" {
void setNextScene__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void setNextSequence__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void fn_1_3B398(void*);
void fn_80053218(unsigned int, int);
unsigned int* fn_8004E580(GameGlobal*);
extern const char lbl_1_data_95A0[];
void fn_1_3B16C(char* self) {
    const char* str = lbl_1_data_95A0;
    int bit;
    gfSceneManager* mgr = gfSceneManager::getInstance();
    int cont = 1;
    while (cont) {
        cont = 0;
        switch (*(unsigned int*)(self + 8)) {
        default:
            *(int*)(self + 8) = 0;
        case 0:
            *(int*)(self + 8) = 1;
            cont = 1;
            *(int*)(self + 12) = 3;
            *(unsigned char*)(self + 16) = 13;
            break;
        case 1:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x198, *(unsigned char*)(self + 16));
            *(int*)(self + 8) = 2;
            break;
        case 2:
            cont = 1;
            *(int*)(self + 8) = *(int*)(self + 12);
            break;
        case 3:
            fn_1_3B398(self);
            setNextScene__14gfSceneManagerFv(mgr, str + 0x1a8, *(unsigned char*)(self + 17));
            *(int*)(self + 8) = 4;
            break;
        case 4:
            *(int*)(self + 8) = 1;
            cont = 1;
            *(int*)(self + 12) = 5;
            *(unsigned char*)(self + 16) = 0;
            break;
        case 5:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x1b8, 0);
            *(int*)(self + 8) = 6;
            break;
        case 6: {
            fn_80053218(*(unsigned int*)((char*)g_GameGlobal->m_resultInfo + 0x1384) / 60, 1);
            char* result = (char*)g_GameGlobal->m_resultInfo;
            if ((unsigned char)result[0x1378] != 9 && (unsigned char)result[0x32] == 0) {
                int n = *(unsigned char*)(self + 17);
                unsigned int* flags = fn_8004E580(g_GameGlobal);
                int bit = n * 3 + 1;
                flags[bit / 32] |= 1 << (bit % 32);
            }
            int i = 0;
            bit = 0;
            for (; i < 14; i++, bit += 3) {
                unsigned int* flags = fn_8004E580(g_GameGlobal);
                flags[bit / 32] &= ~(1 << (bit % 32));
            }
            *(int*)(self + 8) = 7;
            cont = 1;
            break;
        }
        case 7:
            setNextSequence__14gfSceneManagerFv(mgr, str + 0x1c0, 23);
            *(int*)(self + 8) = 8;
            break;
        }
    }
}
}