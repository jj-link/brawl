#include <types.h>
#include <gf/gf_scene.h>
#include <gm/gm_global.h>
#include <mu/wifi/mu_wifi_interface.h>

#pragma force_active on

struct SceneSeq {
    char pad[8];
    int state;
    int sub;
    unsigned char flag;
};

extern "C" {
extern char lbl_1_data_8F38[];

void setNextScene__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void setNextSequence__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void fn_1_38E98(SceneSeq*);
void fn_1_390F8(SceneSeq*);
void fn_1_3964C();
void fn_1_3D2D8();
void fn_1_3D450();
int fn_80052DB0(void*);
void fn_800533C8(unsigned int);
void fn_800CCEC4(void*, int);
}

extern "C" void fn_1_38AB0(SceneSeq* self) {
    const char* base = lbl_1_data_8F38;
    char* p18;
    gfSceneManager* mgr = gfSceneManager::getInstance();
    int again = 1;

    while (again) {
        unsigned char c3 = 3U;
        unsigned char c3e = 0x3EU;
        again = 0;
        switch (self->state) {
        default:
            self->state = 0;
            again = 1;
            break;
        case 0:
            self->state = 1;
            again = 1;
            self->sub = 3;
            self->flag = 0xD;
            break;
        case 1:
            setNextScene__14gfSceneManagerFv(mgr, base + 0x14, self->flag);
            self->state = 2;
            break;
        case 2:
            again = 1;
            self->state = self->sub;
            break;
        case 3: {
            fn_1_3D2D8();
            setNextScene__14gfSceneManagerFv(mgr, base + 0x24, 0);
            *(unsigned char*)(*(char**)((char*)g_GameGlobal + 0x10) + 8) = 1;
            *(unsigned char*)(*(char**)((char*)g_GameGlobal + 0x10) + 4) = 0xD;
            p18 = *(char**)((char*)g_GameGlobal + 0x10);
            *p18 = fn_80052DB0(g_GameGlobal) + 1;
            self->state = 4;
            break;
        }
        case 4:
            switch (*(int*)((char*)mgr + 0x284)) {
            case 0:
                self->state = 0xB;
                break;
            case 2:
                self->state = 0xC;
                break;
            case 1:
                self->state = 5;
                break;
            }
            again = 1;
            break;
        case 5:
            if ((s32)g_muWifiInterfaceTask == 0) {
                self->state = 0xC;
                again = 1;
            } else {
                fn_1_38E98(self);
                self->state = 1;
                again = 1;
                self->sub = 6;
                self->flag = 8;
            }
            break;
        case 6:
            setNextScene__14gfSceneManagerFv(mgr, base + 0x38, 0);
            self->state = 7;
            break;
        case 7:
            switch (*(int*)((char*)mgr + 0x284)) {
            case 2:
            default:
                self->state = 8;
                break;
            case 3:
                self->sub = 0xB;
                break;
            case 4:
                self->sub = 0xC;
                break;
            case 5:
                self->sub = 0xB;
                break;
            case 6:
                self->sub = 0xC;
                break;
            }
            if (self->state != 8) {
                self->state = 1;
                self->flag = 2;
            }
            again = 1;
            break;
        case 8:
            fn_1_390F8(self);
            self->state = 1;
            again = 1;
            self->sub = 9;
            self->flag = 9;
            break;
        case 9:
            setNextScene__14gfSceneManagerFv(mgr, base + 0x38, 0);
            self->state = 0xA;
            break;
        case 10: {
            fn_800533C8(
                *(unsigned int*)(*(char**)((char*)g_GameGlobal + 0x18) + 0x1384) / 60);
            fn_1_3964C();
            unsigned char* d = *(unsigned char**)((char*)g_GameGlobal + 8);
            for (int i = 0; i < 7; ++i) {
                if (d[0x99 + i * 0x5C] == 1) {
                    d[0x99 + i * 0x5C] = c3;
                    d[0x98 + i * 0x5C] = c3e;
                }
            }
            switch (*(int*)((char*)mgr + 0x284)) {
            case 2:
            default:
                self->state = 0;
                break;
            case 3:
                self->sub = 0xB;
                break;
            case 4:
                self->sub = 0xC;
                break;
            case 5:
                self->sub = 0xB;
                break;
            case 6:
                self->sub = 0xC;
                break;
            }
            if (self->state != 0) {
                self->state = 1;
                self->flag = 2;
            }
            again = 1;
            break;
        }
        case 11:
            fn_800CCEC4((void*)g_muWifiInterfaceTask, 0);
            setNextSequence__14gfSceneManagerFv(mgr, base + 0x40, 0x19);
            self->state = 0xD;
            break;
        case 12:
            fn_1_3D450();
            setNextSequence__14gfSceneManagerFv(mgr, base + 0x40, 0x23);
            self->state = 0xD;
            break;
        }
    }
}
