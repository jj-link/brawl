#include <gf/gf_scene.h>
#include <gm/gm_global.h>

#pragma force_active on

namespace Original {
extern "C" char __RTTI__7gfScene[];
}

struct UnkParam {
    union {
        bool asBool;
        unsigned int asInt;
    } unk0;
    unsigned int unk4;
};

extern "C" {
void setNextScene__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void setNextSequence__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_1_3D2D8();
int fn_80052DB0();
void fn_1_2A444(void*);
void fn_1_2AA5C(void*);
void fn_1_2A038(void*);
void fn_1_2A2CC(void*);
void fn_800532F0(unsigned int, int);
unsigned int fn_80051514(int, int);
void fn_80051440(unsigned int);
void fn_80158BE0();
void fn_80159704();
void fn_1_29DA0(void*, unsigned char, unsigned char, unsigned char,
                unsigned char, int, int);
void fn_1_29CC0(void*, unsigned char, int, int);
unsigned int fn_1_2AB94(unsigned char);

extern char lbl_1_data_7A28[];
extern char lbl_1_data_13D0[];
extern char* lbl_805A01D8;
}

#define I(p, o) (*(int*)((char*)(p) + (o)))
#define U(p, o) (*(unsigned int*)((char*)(p) + (o)))
#define B(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define H(p, o) (*(unsigned short*)((char*)(p) + (o)))
#define F(p, o) (*(float*)((char*)(p) + (o)))

struct NameCopy {
    unsigned short values[5];
};

struct TailCopy {
    unsigned int values[3];
};

static inline void copyPlayer(char* dst, const char* src) {
    B(dst, 0) = B(src, 0);
    B(dst, 1) = B(src, 1);
    B(dst, 2) = B(src, 2);
    B(dst, 3) = B(src, 3);
    B(dst, 4) = B(src, 4);
    B(dst, 5) = B(src, 5);
    B(dst, 6) = B(src, 6);
    B(dst, 7) = B(src, 7);
    B(dst, 8) = B(src, 8);
    B(dst, 9) = B(src, 9);
    B(dst, 10) = B(src, 10);
    B(dst, 11) = B(src, 11);
    *(NameCopy*)(dst + 12) = *(const NameCopy*)(src + 12);
    H(dst, 22) = H(src, 22);
    B(dst, 24) = B(src, 24);
    B(dst, 25) = B(src, 25);
    B(dst, 26) = B(src, 26);
    B(dst, 27) = B(src, 27);
    B(dst, 28) = B(src, 28);
    B(dst, 29) = B(src, 29);
    B(dst, 30) = B(src, 30);
    B(dst, 31) = B(src, 31);
    H(dst, 32) = H(src, 32);
    H(dst, 34) = H(src, 34);
    H(dst, 36) = H(src, 36);
    H(dst, 38) = H(src, 38);
    H(dst, 40) = H(src, 40);
    H(dst, 42) = H(src, 42);
    F(dst, 44) = F(src, 44);
    F(dst, 48) = F(src, 48);
    F(dst, 52) = F(src, 52);
    F(dst, 56) = F(src, 56);
    B(dst, 60) = B(src, 60);
    B(dst, 61) = B(src, 61);
    B(dst, 62) = B(src, 62);
    B(dst, 63) = B(src, 63);
    F(dst, 64) = F(src, 64);
    F(dst, 68) = F(src, 68);
    F(dst, 72) = F(src, 72);
    B(dst, 76) = B(src, 76);
    *(TailCopy*)(dst + 80) = *(const TailCopy*)(src + 80);
}

extern "C" void fn_1_2943C(char* self) {
    const char* str = lbl_1_data_7A28;
    gfSceneManager* mgr = gfSceneManager::getInstance();
    int cont = 1;
    char* data = (char*)g_GameGlobal->m_advData;
    int total;
    UnkParam stack18, stack10, stack8;

    while (cont) {
        cont = 0;
        switch (U(self, 8)) {
        default:
            I(self, 8) = 0;
        case 0:
            I(self, 8) = 1;
            cont = 1;
            I(self, 12) = 3;
            B(self, 16) = 13;
            break;

        case 1:
            setNextScene__14gfSceneManagerFv(mgr, str + 16, B(self, 16));
            I(self, 8) = 2;
            break;

        case 2:
            cont = 1;
            I(self, 8) = I(self, 12);
            break;

        case 3:
            fn_1_3D2D8();
            setNextScene__14gfSceneManagerFv(mgr, str + 32, 0);
            B(g_GameGlobal->m_selCharData, 8) = 1;
            B(g_GameGlobal->m_selCharData, 4) = 6;
            if (g_GameGlobal->m_advData) {
                stack10.unk0.asInt =
                    g_GameGlobal->m_advData->m_record.unk4928;
                stack10.unk4 =
                    g_GameGlobal->m_advData->m_record.unk492C;
            } else {
                stack18.unk0.asBool = false;
                stack18.unk4 = -1;
                stack10 = stack18;
            }
            stack8 = stack10;
            B(g_GameGlobal->m_selCharData, 0) = stack8.unk4 + 1;
            I(self, 40) = fn_80052DB0();
            I(self, 8) = 4;
            break;

        case 4:
            switch (mgr->unk1) {
            case 0:
                I(self, 8) = 17;
                break;
            case 1: {
                I(self, 8) = 1;
                I(self, 12) = 5;
                B(self, 16) = 6;
                gmGlobalModeMelee* p = g_GameGlobal->m_modeMelee;
                p->m_playersInitData[0].m_state = 3;
                p->m_playersInitData[1].m_state = 3;
                p->m_playersInitData[2].m_state = 3;
                p->m_playersInitData[3].m_state = 3;
                fn_1_2A444(self);
                fn_1_2AA5C(self);
                break;
            }
            }
            cont = 1;
            break;

        case 5:
            fn_1_2A038(self);
            setNextScene__14gfSceneManagerFv(mgr, str + 56, 0);
            I(self, 8) = 6;
            break;

        case 6: {
            unsigned int result = 0;
            unsigned int two = (B(data, 0x606) >> 7) & 1;
            total = I(data, 0x4918);
            gmResultInfo* info = g_GameGlobal->m_resultInfo;
            if (two)
                total += I(data, 0x491C);
            fn_800532F0(U(info, 0x1384) / 60, (two != 0) + 1);

            switch (B(data, 0x605)) {
            default:
            case 1:
                if ((B(data, 0x606) >> 7) & 1)
                    result = fn_80051514(1, total);
                else
                    result = fn_80051514(0, total);
                I(self, 0x20) = I(data, 0x61C);
                I(self, 0x1C) = I(self, 0x1C) + 1;
                if (I(self, 0x1C) >= 10) {
                    I(self, 8) = 1;
                    I(self, 12) = 13;
                    B(self, 16) = 2;
                } else {
                    I(self, 8) = 7;
                }
                break;

            case 5:
                I(self, 8) = 15;
                I(self, 0x24) = 15;
                break;

            case 3:
                if ((B(data, 0x606) >> 7) & 1)
                    result = fn_80051514(3, total);
                else
                    result = fn_80051514(2, total);
                I(self, 8) = 1;
                I(self, 12) = 9;
                B(self, 16) = 2;
                break;
            }

            if (result < 1)
                result = 1;
            fn_80051440(result);
            fn_80158BE0();
            fn_80159704();
            cont = 1;
            break;
        }

        case 7:
            fn_1_2A2CC(self);
            setNextScene__14gfSceneManagerFv(mgr, str + 56, 0);
            I(self, 8) = 8;
            break;

        case 8:
            switch (B(data, 0x605)) {
            default:
            case 1:
                I(self, 8) = 5;
                break;
            case 5:
                I(self, 8) = 15;
                I(self, 0x24) = 15;
                break;
            }
            fn_80158BE0();
            fn_80159704();
            cont = 1;
            break;

        case 9: {
            gmGlobalModeMelee* p = g_GameGlobal->m_modeMelee;
            gmSelCharData* q = g_GameGlobal->m_selCharData;
            if ((B(g_GameGlobal->m_advData, 0x606) >> 7) & 1)
                fn_1_29DA0(self, B(p, 0x98), B(q, 0xBD),
                            B(p, 0xF4), B(q, 0x119), 0, I(self, 0x1C));
            else
                fn_1_29CC0(self, B(p, 0x98), 0, I(self, 0x1C));

            char* scene = (char*)mgr->searchScene(str + 64);
            int stage = I(self, 0x1C);
            I(scene, 0x360) = 0;
            I(scene, 0x364) = 0;
            I(scene, 0x368) = 0;
            I(scene, 0x36C) = 0;
            B(scene, 0x370) = 1;
            I(scene, 0x374) = stage;
            setNextScene__14gfSceneManagerFv(mgr, str + 64, 0);
            I(self, 8) = 10;
            break;
        }

        case 10:
            I(self, 8) = 15;
            cont = 1;
            I(self, 0x24) = 15;
            I(lbl_805A01D8, 0x174) = 45;
            break;

        case 13: {
            gmGlobalModeMelee* p = g_GameGlobal->m_modeMelee;
            gmSelCharData* q = g_GameGlobal->m_selCharData;
            if ((B(g_GameGlobal->m_advData, 0x606) >> 7) & 1)
                fn_1_29DA0(self, B(p, 0x98), B(q, 0xBD),
                            B(p, 0xF4), B(q, 0x119), 1, I(self, 0x20));
            else
                fn_1_29CC0(self, B(p, 0x98), 1, I(self, 0x20));

            char* scene = (char*)__dynamic_cast(
                mgr->searchScene(str + 76), 4, lbl_1_data_13D0,
                Original::__RTTI__7gfScene, 0);
            I(scene, 0x14B8) = I(self, 0x20);
            setNextScene__14gfSceneManagerFv(
                mgr, str + 76, B(self, 0x11) + 100);
            I(self, 8) = 14;
            break;
        }

        case 14:
            if (fn_1_2AB94(B(self, 0x11)) == 1) {
                char* p = (char*)g_GameGlobal->m_modeMelee;
                char* adv = (char*)g_GameGlobal->m_advData;
                char* dst = *(char**)((char*)g_GameGlobal + 12);
                copyPlayer(dst, p + 0x98);
                if (((B(adv, 0x606) >> 7) & 1) &&
                    B(p, 0x98) != 7 && B(p, 0x98) != 21) {
                    dst = *(char**)((char*)g_GameGlobal + 12);
                    copyPlayer(dst, p + 0xF4);
                }
            }
            I(self, 8) = 15;
            cont = 1;
            I(self, 0x24) = 14;
            break;

        case 15:
            setNextSequence__14gfSceneManagerFv(
                mgr, str + 88, I(self, 0x24));
            break;

        case 16:
            I(g_GameGlobal->m_setRule, 0x24) = I(self, 0x28);
            cont = 1;
            I(self, 8) = 0;
            break;

        case 17:
            setNextSequence__14gfSceneManagerFv(mgr, str + 104, 7);
            I(self, 8) = 18;
            break;
        }
    }
}
