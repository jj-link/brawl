#include <gf/gf_scene.h>
#pragma force_active on
struct SixShorts { unsigned short a[6]; };
struct ThreeWords { int a[3]; };
extern "C" {
void setNextScene__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void setNextSequence__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void fn_1_3D2D8();
void fn_1_347F0(void*);
int fn_80052DB0();
void fn_800532F0(unsigned int, int);
unsigned int fn_80056FDC();
extern char lbl_1_data_85E8[];
extern char* g_GameGlobal;
extern char* g_gfApplication;
}
extern "C" void fn_1_34398(char* self) {
    const char* str = lbl_1_data_85E8;
    char* p;
    gfSceneManager* mgr = gfSceneManager::getInstance();
    int cont = 1;
    while (cont) {
        cont = 0;
        switch (*(unsigned int*)(self + 8)) {
        default:
            *(int*)(self + 8) = 0;
            cont = 1;
            break;
        case 0:
            g_gfApplication[0x110] = 0;
            *(int*)(self + 8) = 1;
            *(int*)(self + 0xc) = 3;
            self[0x10] = 13;
            cont = 1;
            break;
        case 1:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x10, *(unsigned char*)(self + 0x10));
            *(int*)(self + 8) = 2;
            break;
        case 2:
            cont = 1;
            *(int*)(self + 8) = *(int*)(self + 0xc);
            break;
        case 3: {
            fn_1_3D2D8();
            setNextScene__14gfSceneManagerFv(mgr, str + 0x20, 0);
            (*(char**)(g_GameGlobal + 0x10))[8] = 1;
            (*(char**)(g_GameGlobal + 0x10))[4] = 7;
            p = *(char**)(g_GameGlobal + 0x10);
            p[0] = fn_80052DB0() + 1;
            *(int*)(self + 0x1c) = fn_80052DB0();
            *(int*)(self + 8) = 4;
            break;
        }
        case 4:
            switch (*(int*)((char*)mgr + 0x284)) {
            case 0: *(int*)(self + 8) = 10; break;
            case 1: *(int*)(self + 8) = 5; break;
            }
            cont = 1;
            break;
        case 5:
            fn_1_347F0(self);
            *(int*)(self + 8) = 1;
            cont = 1;
            *(int*)(self + 0xc) = 6;
            self[0x10] = 0;
            break;
        case 6:
            g_gfApplication[0x110] = self[0x18];
            setNextScene__14gfSceneManagerFv(mgr, str + 0x38, 0);
            *(int*)(self + 8) = 7;
            break;
        case 7: {
            g_gfApplication[0x110] = 0;
            fn_800532F0(*(unsigned int*)(*(char**)(g_GameGlobal + 0x18) + 0x1384) / 60,
                (*(unsigned char*)(*(char**)(g_GameGlobal + 8) + 9) >> 2) & 7);
            switch (*(int*)((char*)mgr + 0x284)) {
            case 2:
                self[0x19] = 1;
                cont = 1;
                *(int*)(self + 8) = 5;
                break;
            default:
                *(int*)(self + 8) = 1;
                cont = 1;
                *(int*)(self + 0xc) = 8;
                self[0x10] = 13;
                break;
            }
            break;
        }
        case 8: {
            if (*(unsigned char*)(*(char**)(g_GameGlobal + 0x18) + 0x1378) == 5 &&
                fn_80056FDC() == 1) {
                char* dst = *(char**)(g_GameGlobal + 0xc);
                char* src = *(char**)(g_GameGlobal + 8) +
                    (((*(unsigned char*)(*(char**)(g_GameGlobal + 0x18) + 0x1f) - 1) == 0) * 0x5c);
                dst[0x00] = src[0x98];
                dst[0x01] = src[0x99];
                dst[0x02] = src[0x9a];
                dst[0x03] = src[0x9b];
                dst[0x04] = src[0x9c];
                dst[0x05] = src[0x9d];
                dst[0x06] = src[0x9e];
                dst[0x07] = src[0x9f];
                dst[0x08] = src[0xa0];
                dst[0x09] = src[0xa1];
                dst[0x0a] = src[0xa2];
                dst[0x0b] = src[0xa3];
                *(SixShorts*)(dst + 0x0c) = *(SixShorts*)(src + 0xa4);
                dst[0x18] = src[0xb0];
                dst[0x19] = src[0xb1];
                dst[0x1a] = src[0xb2];
                dst[0x1b] = src[0xb3];
                dst[0x1c] = src[0xb4];
                dst[0x1d] = src[0xb5];
                dst[0x1e] = src[0xb6];
                dst[0x1f] = src[0xb7];
                *(unsigned short*)(dst + 0x20) = *(unsigned short*)(src + 0xb8);
                *(unsigned short*)(dst + 0x22) = *(unsigned short*)(src + 0xba);
                *(unsigned short*)(dst + 0x24) = *(unsigned short*)(src + 0xbc);
                *(unsigned short*)(dst + 0x26) = *(unsigned short*)(src + 0xbe);
                *(unsigned short*)(dst + 0x28) = *(unsigned short*)(src + 0xc0);
                *(unsigned short*)(dst + 0x2a) = *(unsigned short*)(src + 0xc2);
                *(float*)(dst + 0x2c) = *(float*)(src + 0xc4);
                *(float*)(dst + 0x30) = *(float*)(src + 0xc8);
                *(float*)(dst + 0x34) = *(float*)(src + 0xcc);
                *(float*)(dst + 0x38) = *(float*)(src + 0xd0);
                dst[0x3c] = src[0xd4];
                dst[0x3d] = src[0xd5];
                dst[0x3e] = src[0xd6];
                dst[0x3f] = src[0xd7];
                *(float*)(dst + 0x40) = *(float*)(src + 0xd8);
                *(float*)(dst + 0x44) = *(float*)(src + 0xdc);
                *(float*)(dst + 0x48) = *(float*)(src + 0xe0);
                dst[0x4c] = src[0xe4];
                *(ThreeWords*)(dst + 0x50) = *(ThreeWords*)(src + 0xe8);
                *(int*)(*(char**)(g_GameGlobal + 0x1c) + 0x24) =
                    (int)(*(unsigned char*)(src + 0x9f) - 1);
            }
            setNextSequence__14gfSceneManagerFv(mgr, str + 0x40, 0x10);
            break;
        }
        case 9:
            *(int*)(*(char**)(g_GameGlobal + 0x1c) + 0x24) = *(int*)(self + 0x1c);
            *(int*)(self + 8) = 1;
            cont = 1;
            *(int*)(self + 0xc) = 3;
            self[0x10] = 13;
            break;
        case 10:
            g_gfApplication[0x110] = self[0x18];
            setNextSequence__14gfSceneManagerFv(mgr, str + 0x50, 9);
            *(int*)(self + 8) = 11;
            break;
        }
    }
}
