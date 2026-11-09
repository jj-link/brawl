#include <gf/gf_scene.h>
#include <gm/gm_global.h>
#pragma force_active on
struct Flags {
    unsigned char mode : 6;
    unsigned char unused : 2;
    unsigned char rule : 3;
    unsigned char rest : 5;
};
extern "C" {
void setNextScene__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void setNextSequence__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void fn_1_3D2D8();
void fn_1_24860(void*, int);
void fn_80053704(int, int);
extern const char lbl_1_data_7170[];
extern unsigned char lbl_1_bss_18C0;
extern char* g_gfApplication;
void fn_1_2442C(char* self) {
    const char* str = lbl_1_data_7170;
    gfSceneManager* mgr = gfSceneManager::getInstance();
    int cont = 1;
    while (cont) {
        cont = 0;
        switch (*(unsigned int*)(self + 8)) {
        default:
            *(int*)(self + 8) = 0;
        case 0:
            g_gfApplication[0x110] = 0;
            *(int*)(self + 8) = 1;
            *(int*)(self + 12) = 3;
            *(int*)(self + 20) = 0;
            *(unsigned char*)(self + 16) = 2;
            cont = 1;
            break;
        case 1:
            setNextScene__14gfSceneManagerFv(mgr, str + 12, *(unsigned char*)(self + 16));
            *(int*)(self + 8) = 2;
            break;
        case 2:
            cont = 1;
            *(int*)(self + 8) = *(int*)(self + 12);
            break;
        case 3:
            setNextScene__14gfSceneManagerFv(mgr, str + 28, *(int*)(self + 20));
            *(int*)(self + 8) = 4;
            break;
        case 4:
            switch (mgr->unk1) {
            case 0: *(int*)(self + 8) = 18; break;
            case 1: *(int*)(self + 8) = 5; *(int*)(self + 20) = 0; break;
            }
            cont = 1;
            break;
        case 5:
            setNextScene__14gfSceneManagerFv(mgr, str + 40, *(int*)(self + 20));
            *(int*)(self + 8) = 6;
            break;
        case 6:
            switch (mgr->unk1) {
            case 0: *(int*)(self + 8) = 3; *(int*)(self + 20) = 1; break;
            case 1: *(int*)(self + 8) = 7; break;
            }
            cont = 1;
            break;
        case 7:
            ((char*)g_GameGlobal->m_selCharData)[3] = ((char*)g_GameGlobal->m_tournamentData)[2];
            ((char*)g_GameGlobal->m_selCharData)[4] = 1;
            ((char*)g_GameGlobal->m_selCharData)[8] = 0;
            *(int*)(self + 8) = 1;
            *(int*)(self + 12) = 8;
            *(unsigned char*)(self + 16) = 13;
            cont = 1;
            break;
        case 8:
            fn_1_3D2D8();
            setNextScene__14gfSceneManagerFv(mgr, str + 52, 0);
            *(int*)(self + 8) = 9;
            break;
        case 9:
            switch (mgr->unk1) {
            case 0:
                *(int*)(self + 8) = 5;
                *(int*)(self + 20) = ((unsigned char*)g_GameGlobal->m_selCharData)[5] + 2;
                break;
            case 1:
                *(int*)(self + 8) = 10;
                ((char*)g_GameGlobal->m_tournamentData)[2] = ((char*)g_GameGlobal->m_selCharData)[3];
                break;
            }
            cont = 1;
            break;
        case 10:
            setNextScene__14gfSceneManagerFv(mgr, str + 72, 0);
            ((char*)g_GameGlobal->m_selCharData)[4] = 1;
            *(int*)(self + 8) = 11;
            break;
        case 11:
            switch (mgr->unk1) {
            case 0:
                ((char*)g_GameGlobal->m_selCharData)[3] = ((char*)g_GameGlobal->m_tournamentData)[2];
                ((char*)g_GameGlobal->m_selCharData)[4] = 1;
                ((char*)g_GameGlobal->m_selCharData)[8] = 0;
                *(int*)(self + 8) = 8;
                break;
            case 1:
            case 3: {
                int val = 0;
                if (mgr->unk1 == 3) val = 0x35;
                *(int*)(self + 8) = 12;
                fn_1_24860(self, val);
                break;
            }
            case 2: break;
            }
            cont = 1;
            break;
        case 12:
            *(int*)(self + 8) = 1;
            cont = 1;
            *(int*)(self + 12) = 13;
            *(unsigned char*)(self + 16) = 0;
            break;
        case 13:
            g_gfApplication[0x110] = self[24];
            setNextScene__14gfSceneManagerFv(mgr, str + 88, 0);
            *(int*)(self + 8) = 14;
            break;
        case 14:
            *(int*)(self + 8) = 15;
            cont = 1;
            g_gfApplication[0x110] = 0;
            break;
        case 15: {
            char* p = (char*)g_GameGlobal->m_modeMelee;
            char* result = (char*)g_GameGlobal->m_resultInfo;
            ((Flags*)(p + 8))->mode = 32;
            *(short*)(p + 0x1a) = 40;
            *(int*)(p + 0x20) = 0;
            p[0x16] = 0;
            if (((Flags*)(p + 8))->rule == 1)
                *(int*)(result + 8) = ((unsigned char*)g_GameGlobal->m_setRule)[4];
            fn_80053704(0, 0);
            *(int*)(self + 8) = 1;
            cont = 1;
            *(int*)(self + 12) = 16;
            *(unsigned char*)(self + 16) = 3;
            break;
        }
        case 16:
            setNextScene__14gfSceneManagerFv(mgr, str + 96, 0);
            *(int*)(self + 8) = 17;
            break;
        case 17:
            *(int*)(self + 8) = 1;
            cont = 1;
            *(int*)(self + 12) = 5;
            *(int*)(self + 20) = 1;
            *(unsigned char*)(self + 16) = 2;
            break;
        case 18:
            ((char*)g_GameGlobal->m_setRule)[5] = lbl_1_bss_18C0;
            setNextSequence__14gfSceneManagerFv(mgr, str + 108, 5);
            *(int*)(self + 8) = 19;
            break;
        }
    }
}
}