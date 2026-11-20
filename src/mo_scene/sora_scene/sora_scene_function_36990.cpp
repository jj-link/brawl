#include <gf/gf_scene.h>
#include <gm/gm_global.h>
#include <ip/ip_switch.h>
#pragma force_active on

extern "C" {
void setNextScene__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void setNextSequence__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void fn_1_3D2D8();
void fn_1_36C44(char*);
int fn_1_36CBC(char*);
extern char lbl_1_data_8A18[];
}

inline void resetScene(char* self) {
    *(int*)(self + 8) = 1;
    *(int*)(self + 12) = 3;
    *(unsigned char*)(self + 17) = 1;
    *(unsigned char*)(self + 16) = 13;
}

extern "C" void fn_1_36990(char* self) {
    const char* str = lbl_1_data_8A18;
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
            *(unsigned char*)(self + 17) = 0;
            *(unsigned char*)(self + 16) = 13;
            break;
        case 1:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x0c, *(unsigned char*)(self + 16));
            *(int*)(self + 8) = 2;
            break;
        case 2:
            cont = 1;
            *(int*)(self + 8) = *(int*)(self + 12);
            break;
        case 3:
            fn_1_3D2D8();
            setNextScene__14gfSceneManagerFv(mgr, str + 0x1c, 0);
            *(int*)(self + 8) = 4;
            break;
        case 4:
            switch (mgr->unk1) {
            case 1:
                *(int*)(self + 8) = 7;
                break;
            case 0:
                *(int*)(self + 8) = 1;
                *(int*)(self + 12) = 5;
                {
                    char* g = (char*)g_GameGlobal->m_modeMelee;
                    switch ((*(unsigned char*)(g + 8) >> 2) & 0x3F) {
                    case 0x10:
                    case 0xA:
                        fn_1_36C44(self);
                        *(unsigned char*)(self + 16) = 9;
                        break;
                    case 0x12:
                    case 0x9:
                        *(unsigned char*)(self + 16) = 0xA;
                        if (*(unsigned char*)(g + 0x63) == 0 && *(unsigned char*)(g + 0x64) == 0) {
                            *(unsigned char*)(g + 0x9A) = 0;
                            *(unsigned char*)(g + 0xF6) = 1;
                        }
                        break;
                    default:
                        *(unsigned char*)(self + 16) = 0;
                        *(unsigned char*)((char*)g_GameGlobal->m_modeMelee + 0xC) |= 0x80;
                        break;
                    }
                }
                break;
            }
            cont = 1;
            break;
        case 5:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x28, 0);
            *(int*)(self + 8) = 6;
            break;
        case 6: {
            int r0 = mgr->unk1;
            char* g = (char*)g_GameGlobal->m_modeMelee;
            switch (r0) {
            case 2:
                break;
            case 3:
                resetScene(self);
                break;
            case 1: {
                int t = (*(unsigned char*)(g + 8) >> 2) & 0x3F;
                switch (t) {
                case 0x12:
                case 9:
                    if (fn_1_36CBC(self) != 0) {
                        char* ip = (char*)ipSwitch::getInstance();
                        *(unsigned char*)(ip + 0x24) |= 0x80;
                        *(int*)(self + 8) = 5;
                    } else {
                        resetScene(self);
                    }
                    break;
                default:
                    resetScene(self);
                    break;
                }
                break;
            }
            }
            cont = 1;
            break;
        }
        case 7:
            setNextSequence__14gfSceneManagerFv(mgr, str + 0x30, 0xe);
            *(int*)(self + 8) = 8;
            break;
        }
    }
}
