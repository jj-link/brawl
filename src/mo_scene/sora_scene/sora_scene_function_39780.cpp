#include <types.h>
#include <gf/gf_scene.h>
#include <gm/gm_global.h>
#pragma force_active on
extern "C" {
extern const char lbl_1_data_9068[];
extern char* g_gfApplication;
extern int g_muWifiInterfaceTask;
void fn_1_3D2D8();
void fn_1_3D450();
void fn_1_39BB0(char*);
void fn_1_39DF0(char*);
void fn_1_39F9C(char*);
int fn_80052DB0();
void fn_800533C8(unsigned int);
void* fn_800CB834(int);
void fn_800CCEC4(int, int);
void fn_800CFE1C(int);
void setNextScene__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void setNextSequence__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void fn_1_39780(char* self) {
    const char* str = lbl_1_data_9068;
    char* p;
    gfSceneManager* mgr = gfSceneManager::getInstance();
    int cont = 1;
    while (cont) {
        cont = 0;
        switch (*(unsigned int*)(self + 8)) {
        default:
            *(int*)(self + 8) = 9;
            *(int*)(self + 0xC) = 1;
            *(unsigned char*)(self + 0x10) = 13;
            cont = 1;
            break;
        case 1:
            fn_1_3D2D8();
            g_gfApplication[0x110] = 0;
            setNextScene__14gfSceneManagerFv(mgr, str + 0x14, 0);
            *(unsigned char*)(*(char**)((char*)g_GameGlobal + 0x10) + 8) = 1;
            *(unsigned char*)(*(char**)((char*)g_GameGlobal + 0x10) + 4) = 14;
            p = *(char**)((char*)g_GameGlobal + 0x10);
            *(unsigned char*)p = fn_80052DB0() + 1;
            *(int*)(self + 8) = 2;
            break;
        case 2:
            switch (*(int*)((char*)mgr + 0x284)) {
            case 0: *(int*)(self + 8) = 0xB; break;
            case 2: *(int*)(self + 8) = 0xC; break;
            case 1: *(int*)(self + 8) = 3; break;
            }
            cont = 1;
            break;
        case 3:
            if (g_muWifiInterfaceTask == 0) {
                *(int*)(self + 8) = 0xC;
                cont = 1;
            } else {
                fn_1_39BB0(self);
                *(int*)(self + 8) = 9;
                cont = 1;
                *(int*)(self + 0xC) = 4;
                *(unsigned char*)(self + 0x10) = 8;
            }
            break;
        case 4:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x28, 0);
            *(int*)(self + 8) = 5;
            break;
        case 5:
            switch (*(int*)((char*)mgr + 0x284)) {
            case 2:
            default: *(int*)(self + 8) = 6; break;
            case 3: *(int*)(self + 0xC) = 0xB; break;
            case 4: *(int*)(self + 0xC) = 0xC; break;
            case 5: *(int*)(self + 0xC) = 0xB; break;
            case 6: *(int*)(self + 0xC) = 0xC; break;
            }
            if (*(int*)(self + 8) != 6) {
                *(int*)(self + 8) = 9;
                *(unsigned char*)(self + 0x10) = 2;
            }
            cont = 1;
            break;
        case 6:
            fn_1_39DF0(self);
            {
                unsigned char v = *((unsigned char*)fn_800CB834(g_muWifiInterfaceTask) + 0xA);
                *(unsigned char*)(*(char**)((char*)g_GameGlobal + 0x10) + 1) = v;
            }
            *(int*)(self + 8) = 9;
            *(int*)(self + 0xC) = 7;
            *(unsigned char*)(self + 0x10) = 10;
            cont = 1;
            break;
        case 7:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x28, 0);
            *(int*)(self + 8) = 8;
            break;
        case 8:
            fn_800533C8(*(unsigned int*)(*(char**)((char*)g_GameGlobal + 0x18) + 0x1384) / 60);
            switch (*(int*)((char*)mgr + 0x284)) {
            default:
                fn_1_39DF0(self);
                *(int*)(self + 8) = 7;
                break;
            case 1:
                if (*(unsigned char*)(*(char**)((char*)g_GameGlobal + 0x18) + 0x1378) == 9) {
                    *(int*)(self + 0xC) = 1;
                    *(unsigned char*)(self + 0x10) = 13;
                    *(int*)(self + 8) = 9;
                } else {
                    int n = *(int*)(self + 0x14) + 1;
                    *(int*)(self + 0x14) = n;
                    if (*(unsigned char*)(self + 0x11) == 0 && *(unsigned char*)(self + 0x12) == 0 && *(int*)(self + 0x18) > n) goto retry;
                    if (*(unsigned char*)(self + 0x11) != 0 || *(unsigned char*)(self + 0x12) != 0 || *(int*)(self + 0x1C) >= 1) goto quit;
                    *(int*)(self + 0x14) = 0;
                    *(int*)(self + 0x1C) = *(int*)(self + 0x1C) + 1;
                    goto retry;
                quit:
                    *(int*)(self + 0xC) = 1;
                    *(unsigned char*)(self + 0x10) = 13;
                    *(int*)(self + 8) = 9;
                    break;
                retry:
                    *(int*)(self + 8) = 7;
                    fn_1_39F9C(self);
                    fn_800CFE1C(g_muWifiInterfaceTask);
                }
                break;
            case 3:
                *(int*)(self + 0xC) = 0xB;
                *(unsigned char*)(self + 0x10) = 2;
                *(int*)(self + 8) = 9;
                break;
            case 4:
                *(int*)(self + 0xC) = 0xC;
                *(unsigned char*)(self + 0x10) = 2;
                *(int*)(self + 8) = 9;
                break;
            case 5:
                *(int*)(self + 0xC) = 0xB;
                *(unsigned char*)(self + 0x10) = 2;
                *(int*)(self + 8) = 9;
                break;
            case 6:
                *(int*)(self + 0xC) = 0xC;
                *(unsigned char*)(self + 0x10) = 2;
                *(int*)(self + 8) = 9;
                break;
            }
            cont = 1;
            break;
        case 9:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x30, *(unsigned char*)(self + 0x10));
            *(int*)(self + 8) = 10;
            break;
        case 10:
            cont = 1;
            *(int*)(self + 8) = *(int*)(self + 0xC);
            break;
        case 11:
            fn_800CCEC4(g_muWifiInterfaceTask, 0);
            setNextSequence__14gfSceneManagerFv(mgr, str + 0x40, 0x1A);
            *(int*)(self + 8) = 13;
            break;
        case 12:
            fn_1_3D450();
            setNextSequence__14gfSceneManagerFv(mgr, str + 0x40, 0x23);
            *(int*)(self + 8) = 13;
            break;
        }
    }
}
}