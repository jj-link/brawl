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
void setNextScene__14gfSceneManagerFv(void*, const char*, int);
void setNextSequence__14gfSceneManagerFv(void*, const char*, int);
void fn_1_23270(void*);
void fn_80053704(int, int);
extern const char lbl_1_data_6F50[];
extern unsigned char lbl_1_bss_18B0;
extern char* lbl_1_bss_18B4;
extern char* g_gfApplication;

void fn_1_22D3C(char* self) {
    const char* str = lbl_1_data_6F50;
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
            cont = 1;
            *(int*)(self + 0xc) = 3;
            *(int*)(self + 0x14) = 0;
            *(unsigned char*)(self + 0x10) = 13;
            break;
        case 1:
            setNextScene__14gfSceneManagerFv(mgr, str + 24, *(unsigned char*)(self + 0x10));
            *(int*)(self + 8) = 2;
            break;
        case 2:
            cont = 1;
            *(int*)(self + 8) = *(int*)(self + 0xc);
            break;
        case 3:
            setNextScene__14gfSceneManagerFv(mgr, str + 40, *(int*)(self + 0x14));
            *(int*)(self + 8) = 4;
            break;
        case 4:
            switch (mgr->unk1) {
            case 0: *(int*)(self + 8) = 19; break;
            case 1: *(int*)(self + 8) = 5; break;
            case 2: *(int*)(self + 8) = 7; break;
            }
            cont = 1;
            break;
        case 5:
            setNextScene__14gfSceneManagerFv(mgr, str + 12, 0);
            *((unsigned char*)g_GameGlobal->m_selCharData + 4) = 3;
            *(unsigned char*)(lbl_1_bss_18B4 + 0x448) = 1;
            *(int*)(lbl_1_bss_18B4 + 0x444) = 0;
            *(int*)(self + 8) = 6;
            break;
        case 6:
            switch (mgr->unk1) {
            case 0:
                *(int*)(self + 8) = 3;
                *(int*)(self + 0x14) = 1;
                break;
            case 1:
            case 3: {
                int flag = mgr->unk1 == 3;
                lbl_1_bss_18B0 = flag;
                *((unsigned char*)g_GameGlobal->m_tournamentData + 0x50a) = flag;
                *(int*)(self + 8) = 3;
                *(int*)(self + 0x14) = 2;
                break;
            }
            }
            cont = 1;
            break;
        case 7:
            *(int*)(self + 8) = 8;
            cont = 1;
            *(int*)(self + 0x14) = 0;
            break;
        case 8:
            setNextScene__14gfSceneManagerFv(mgr, str + 52, *(int*)(self + 0x14));
            *(int*)(self + 8) = 9;
            break;
        case 9:
            switch (mgr->unk1) {
            case 0:
                switch (*((unsigned char*)g_GameGlobal->m_tournamentData + 5)) {
                case 0:
                    *(int*)(self + 8) = 10;
                    *(int*)(lbl_1_bss_18B4 + 0x444) = 1;
                    break;
                case 1: {
                    unsigned char* p = (unsigned char*)g_GameGlobal->m_selCharData;
                    int missing = 0;
                    if (p[0xb9] == 0) missing = 1;
                    else if (p[0x115] == 0) missing = 1;
                    else if (p[0x171] == 0) missing = 1;
                    else if (p[0x1cd] == 0) missing = 1;
                    if (missing == 0) {
                        *(int*)(self + 8) = 10;
                        *(int*)(lbl_1_bss_18B4 + 0x444) = 1;
                    } else {
                        *(int*)(self + 8) = 10;
                        *(int*)(lbl_1_bss_18B4 + 0x444) = 0;
                    }
                    break;
                }
                case 2:
                    *(int*)(self + 8) = 13;
                    *(int*)(lbl_1_bss_18B4 + 0x444) = 0;
                    break;
                }
                break;
            case 2:
                *(int*)(self + 8) = 3;
                *(int*)(self + 0x14) = 3;
                break;
            case 1:
                *(int*)(self + 8) = 3;
                *(int*)(self + 0x14) = 2;
                break;
            case 3:
                *(int*)(self + 8) = 19;
                break;
            }
            cont = 1;
            break;
        case 10:
            cont = 1;
            *(int*)(self + 8) = 11;
            break;
        case 11:
            setNextScene__14gfSceneManagerFv(mgr, str + 12, 0);
            *((unsigned char*)g_GameGlobal->m_selCharData + 4) = 3;
            *(unsigned char*)(lbl_1_bss_18B4 + 0x448) = 0;
            *(int*)(self + 8) = 12;
            break;
        case 12:
            switch (mgr->unk1) {
            case 0:
                *(short*)((char*)g_GameGlobal->m_selStageData + 0x22) = 1;
            case 1:
            case 3: {
                int flag = mgr->unk1 == 3;
                lbl_1_bss_18B0 = flag;
                *((unsigned char*)g_GameGlobal->m_tournamentData + 0x50a) = flag;
                *(int*)(self + 8) = 13;
                break;
            }
            }
            cont = 1;
            break;
        case 13:
            fn_1_23270(self);
            *(int*)(self + 8) = 1;
            cont = 1;
            *(int*)(self + 0xc) = 14;
            *(unsigned char*)(self + 0x10) = 0;
            break;
        case 14:
            g_gfApplication[0x110] = *(unsigned char*)(self + 0x18);
            setNextScene__14gfSceneManagerFv(mgr, str + 64, 0);
            *(int*)(self + 8) = 15;
            break;
        case 15:
            cont = 1;
            g_gfApplication[0x110] = 0;
            *(int*)(self + 8) = 16;
            break;
        case 16: {
            char* p = (char*)g_GameGlobal->m_modeMelee;
            char* result = (char*)g_GameGlobal->m_resultInfo;
            ((Flags*)(p + 8))->mode = 32;
            *(short*)(p + 0x1a) = 40;
            *(int*)(p + 0x20) = 0;
            p[0x16] = 0;
            if (((Flags*)(p + 8))->rule == 1) {
                *(int*)(result + 8) = *((unsigned char*)g_GameGlobal->m_setRule + 4);
            }
            fn_80053704(0, 0);
            *(int*)(self + 8) = 1;
            cont = 1;
            *(int*)(self + 0xc) = 17;
            *(unsigned char*)(self + 0x10) = 3;
            break;
        }
        case 17:
            setNextScene__14gfSceneManagerFv(mgr, str + 72, 0);
            *(int*)(self + 8) = 18;
            break;
        case 18:
            *(int*)(self + 8) = 1;
            cont = 1;
            *(int*)(self + 0xc) = 8;
            *(int*)(self + 0x14) = 1;
            *(unsigned char*)(self + 0x10) = 13;
            break;
        case 19:
            g_gfApplication[0x110] = *(unsigned char*)(self + 0x18);
            setNextSequence__14gfSceneManagerFv(mgr, str + 84, 4);
            *(unsigned char*)(lbl_1_bss_18B4 + 0x448) = 1;
            *(int*)(lbl_1_bss_18B4 + 0x444) = 0;
            { char* p = lbl_1_bss_18B4;
            *(int*)(p + 0x35c) = -1;
            *(int*)(p + 0x360) = 0xf0; }
            *(int*)(self + 8) = 20;
            break;
        }
    }
}
}