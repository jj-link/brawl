#include <types.h>
#include <gf/gf_scene.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
extern const char lbl_1_data_67F0[];
void setNextScene__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void setNextSequence__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void fn_8005033C(void*);
}

extern "C" void fn_1_20E18(char* self) {
    const char* str = lbl_1_data_67F0;
    gfSceneManager* mgr = gfSceneManager::getInstance();
    fn_8005033C(g_GameGlobal->m_modeMelee);
    int cont = 1;
    while (cont) {
        cont = 0;
        switch (*(int*)(self + 8)) {
        case 9:
            setNextScene__14gfSceneManagerFv(mgr, str + 0xc, 2);
            *(int*)(self + 8) = 0;
            break;
        default: {
            int v = *(int*)((char*)mgr + 0x31c);
            *(int*)(self + 0xc) = v;
            if (v == 0x2a) {
                *(int*)(self + 8) = 1;
                cont = 1;
                *(int*)(self + 0x10) = 0x23;
                *(int*)((char*)mgr + 0x31c) = 0;
            } else {
                int r5;
                switch (v) {
                default: r5 = 0; break;
                case 1: r5 = 1; break;
                case 2: r5 = 2; break;
                case 3: r5 = 3; break;
                case 4: r5 = 4; break;
                case 5: r5 = 5; break;
                case 6: r5 = 6; break;
                case 7: r5 = 7; break;
                case 8: r5 = 8; break;
                case 9: r5 = 9; break;
                case 10: r5 = 10; break;
                case 11: r5 = 11; break;
                case 12: r5 = 12; break;
                case 13: r5 = 13; break;
                case 14: r5 = 14; break;
                case 15: r5 = 15; break;
                case 16: r5 = 16; break;
                case 17: r5 = 17; break;
                case 18: r5 = 18; break;
                case 19: r5 = 19; break;
                case 20: r5 = 20; break;
                case 21: r5 = 21; break;
                case 22: r5 = 22; break;
                case 23: r5 = 24; break;
                case 24: r5 = 25; break;
                case 25: r5 = 26; break;
                case 26: r5 = 27; break;
                case 27: r5 = 29; break;
                case 28: r5 = 30; break;
                case 29: r5 = 31; break;
                case 30: r5 = 34; break;
                case 31: r5 = 35; break;
                case 33: r5 = 38; break;
                case 32: r5 = 37; break;
                case 34: r5 = 39; break;
                case 35: r5 = 40; break;
                case 36: r5 = 41; break;
                case 37: r5 = 42; break;
                case 38: r5 = 43; break;
                case 39: r5 = 44; break;
                case 40: r5 = 45; break;
                case 41: r5 = 46; break;
                }
                setNextScene__14gfSceneManagerFv(mgr, str + 0x1c, r5);
                *(int*)(self + 8) = 1;
            }
            break;
        }
        case 1: {
            int v = *(int*)(self + 0x10);
            v = v != -1 ? v : mgr->unk1;
            *(int*)(self + 0x10) = -1;
            switch (v) {
            case 0:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x28, 1);
                *(int*)(self + 8) = 10;
                break;
            case 1:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x30, 0);
                *(int*)(self + 8) = 10;
                break;
            case 2:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x3c, 0);
                *(int*)(self + 8) = 10;
                break;
            case 3:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x48, 0);
                *(int*)(self + 8) = 10;
                break;
            case 4:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x54, 0);
                *(int*)(self + 8) = 10;
                break;
            case 5:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x64, 0);
                *(int*)(self + 8) = 10;
                break;
            case 6:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x70, 0);
                *(int*)(self + 8) = 10;
                break;
            case 7:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x80, 0);
                *(int*)(self + 8) = 10;
                break;
            case 8:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x90, 0);
                *(int*)(self + 8) = 10;
                break;
            case 9:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x98, 0);
                *(int*)(self + 8) = 10;
                break;
            case 10:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0xa8, 0);
                *(int*)(self + 8) = 10;
                break;
            case 11:
            case 37:
            case 38:
            case 39:
            case 40:
            case 41: {
                int r5 = 0;
                switch (mgr->unk1) {
                case 11: r5 = 0; break;
                case 37: r5 = 1; break;
                case 38: r5 = 2; break;
                case 39: r5 = 3; break;
                case 40: r5 = 4; break;
                case 41: r5 = 5; break;
                }
                setNextSequence__14gfSceneManagerFv(mgr, str + 0xb4, r5);
                *(int*)(self + 8) = 10;
                break;
            }
            case 12:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0xc0, 0);
                *(int*)(self + 8) = 10;
                break;
            case 13:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0xcc, 0);
                *(int*)(self + 8) = 10;
                break;
            case 14:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0xd4, 0);
                *(int*)(self + 8) = 10;
                break;
            case 15:
                setNextScene__14gfSceneManagerFv(mgr, str + 0xe0, 0);
                *(int*)(self + 8) = 2;
                break;
            case 16:
                setNextScene__14gfSceneManagerFv(mgr, str + 0xec, 0);
                *(int*)(self + 8) = 3;
                break;
            case 17:
                setNextScene__14gfSceneManagerFv(mgr, str + 0xf8, 0);
                *(int*)(self + 8) = 4;
                break;
            case 18:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x104, 0);
                *(int*)(self + 8) = 10;
                break;
            case 19:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x110, 0);
                *(int*)(self + 8) = 10;
                break;
            case 20:
                setNextScene__14gfSceneManagerFv(mgr, str + 0x120, 0);
                *(int*)(self + 8) = 5;
                break;
            case 21:
                setNextScene__14gfSceneManagerFv(mgr, str + 0x130, 0);
                *(int*)(self + 8) = 6;
                break;
            case 22:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x13c, 0);
                *(int*)(self + 8) = 10;
                break;
            case 35:
                setNextScene__14gfSceneManagerFv(mgr, str + 0x148, 0);
                *(int*)(self + 8) = 7;
                break;
            case 36:
                setNextScene__14gfSceneManagerFv(mgr, str + 0x154, 0);
                *(int*)(self + 8) = 8;
                break;
            case 24:
            case 25:
            case 26:
            case 27:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x160, mgr->unk1);
                *(int*)(self + 8) = 10;
                break;
            case 29:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x170, 0);
                *(int*)(self + 8) = 10;
                break;
            case 30:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x180, 0);
                *(int*)(self + 8) = 10;
                break;
            case 31:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x190, 0);
                *(int*)(self + 8) = 10;
                break;
            case 34:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x1a4, 0);
                *(int*)(self + 8) = 10;
                break;
            default:
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x1b0, 0);
                *(int*)(self + 8) = 10;
                break;
            }
            break;
        }
        case 5:
            setNextSequence__14gfSceneManagerFv(mgr, str + 0x1c0, 0x12);
            *(int*)(self + 8) = 10;
            break;
        case 2:
        case 3:
        case 4:
        case 6:
        case 7:
        case 8: {
            int r16;
            switch (*(int*)(self + 8)) {
            case 2: r16 = 15; break;
            case 3: r16 = 16; break;
            case 4: r16 = 17; break;
            case 6: r16 = 21; break;
            case 7: r16 = 38; break;
            case 8: r16 = 39; break;
            }
            setNextScene__14gfSceneManagerFv(mgr, str + 0x1c, r16);
            *(int*)(self + 8) = 1;
            break;
        }
        }
    }
}
