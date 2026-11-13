#include <gm/gm_global_mode_melee.h>
#include <cm/cm_camera_controller.h>
#include <gf/gf_camera.h>
#include <it/it_manager.h>
#include <ft/ft_manager.h>
#include <snd/snd_system.h>
#pragma force_active on
extern int g_IfMngr;
extern float lbl_27_rodata_4140[];
extern float lbl_805A02C8;
extern "C" int fn_8009C8C0(void*);
extern "C" void fn_27_10AD38(void*, void*, int, int);
extern "C" int fn_27_10CD54(void*, int, int);
extern "C" float fn_27_10CCA4(void*, int, int);
extern "C" void fn_800E5174(void*, int);
extern "C" void fn_800E55E8(void*, void*);
extern "C" void fn_800E4D28(void*, int);
extern "C" void fn_800E4E1C(void*, void*);
extern "C" void fn_800E57FC(void*, void*);
extern "C" void fn_80075F1C(void*, int, int);

inline unsigned char* getPane(int player)
{
    unsigned char* hud = (unsigned char*)g_IfMngr;
    return *(unsigned char**)(hud + hud[player + 0x68] * 4 + 0x4C);
}

extern "C" void fn_27_25614C(unsigned char* p, int active)
{
    float* constants = lbl_27_rodata_4140;
    int offset;
    unsigned char* d0;
    float* value;
    int forceMode;
    int soundCount, i, entry, player;
    if (g_IfMngr == 0 || g_ftManager == 0)
        return;
    if (active != 0) {
        active = 0;
        if (fn_8009C8C0(CameraController::getInstance()) != 0 &&
            itManager::getInstance()->getItemNum((itKind)0xA0) == 0)
            active = 1;
    }
    gfCameraManager* camera = gfCameraManager::getManager();
    if (camera != 0) {
        float h = camera->m_cameras[0].unkD0;
        float w = camera->m_cameras[0].unkCC;
        float edge = w * h;
        float value;
        if (p[0x10C])
            value = *(float*)(p + 0x110);
        else
            value = constants[3] + *(float*)(p + 0x110);
        p[0x10C] = value < edge;
    } else {
        p[0x10C] = 0;
    }
    float fZero, fHalfPi, fNegHalfPi, f240, fOne, f120;
    fZero = constants[1];
    fHalfPi = constants[6];
    fNegHalfPi = constants[7];
    f120 = constants[4];
    fOne = constants[3];
    f240 = constants[5];
    soundCount = 0;
    forceMode = (unsigned int)__cntlzw((*(gmGlobalModeMelee**)(p + 0x44))->m_meleeInitData.m_isStamina) >> 5;
    d0 = p;
    unsigned char markerPos[12];
    for (i = 0, offset = 0; i < 7; ++i, offset += 0x5C, d0 += 4) {
        entry = g_ftManager->getEntryId(i);
        if (entry != -1) {
            unsigned char* slot = (unsigned char*)*(void**)(p + 0x44) + offset;
            player = slot[0x9A];
            int condition = 0;
            int enabled = !((gmPlayerInitData*)(slot + 0x98))->m_isSpycloak;
            int first = 0;
            if (enabled && p[player + 0x6B] != 0)
                first = 1;
            if (first) {
                int second = 0;
                if (p[player + 0x72] != 0 ||
                    *(int*)(p + player * 4 + 0x7C) > 0 ||
                    p[0x10C] != 0)
                    second = 1;
                if (second)
                    condition = 1;
            }
            int alternate = enabled && p[player + 0x64] != 0;
            if (active && (alternate || condition)) {
                if (condition) {
                    if (*(int*)(getPane(player) + 0x354) != 1)
                        fn_800E5174(getPane(player), 1);
                    unsigned char tmp[12];
                    fn_27_10AD38(tmp, g_ftManager, entry, -1);
                    fn_800E55E8(getPane(player), tmp);
                    int* timer = (int*)(p + player * 4 + 0x7C);
                    if (*timer > 0)
                        --*timer;
                } else {
                    if (forceMode && *(unsigned int*)(d0 + 0xD0) >= 0x32) {
                        value = (float*)(p + player * 4 + 0x98);
                        int mode = *value < f120 ? 1 : 2;
                        if (mode != *(int*)(getPane(player) + 0x354))
                            fn_800E5174(getPane(player), mode);
                        *value += fOne;
                        if (f240 <= *value)
                            *value -= f240;
                    } else if (*(int*)(getPane(player) + 0x354) != 1) {
                        fn_800E5174(getPane(player), 1);
                    }
                    unsigned char tmp[12];
                    fn_27_10AD38(tmp, g_ftManager, entry, -1);
                    fn_800E55E8(getPane(player), tmp);
                }
            } else {
                if (*(int*)(getPane(player) + 0x354) != 0)
                    fn_800E5174(getPane(player), 0);
                *(float*)(p + player * 4 + 0x98) = fZero;
            }
            if (active && p[0x118] && p[player + 0xB4]) {
                if (getPane(player)[0x350] == 0)
                    fn_800E4D28(getPane(player), 1);
                Vec3f center = g_ftManager->getFighterCenterPos(entry, -1);
                fn_800E4E1C(getPane(player), &center);
                if (fn_27_10CD54(g_ftManager, entry, -1) != 0) {
                    int mode;
                    unsigned char* hud;
                    int side = lbl_805A02C8 < fNegHalfPi;
                    if (!side)
                        side = fHalfPi < lbl_805A02C8;
                    if (!side)
                        side = (*(int*)((unsigned char*)g_gfSceneRoot + 0x64) >> 24) != 0;
                    if (side) {
                        if (fZero > fn_27_10CCA4(g_ftManager, entry, -1))
                            mode = 2;
                        else
                            mode = 1;
                    } else {
                        if (fZero > fn_27_10CCA4(g_ftManager, entry, -1))
                            mode = 1;
                        else
                            mode = 2;
                    }
                    hud = (unsigned char*)g_IfMngr;
                    unsigned char* pane = *(unsigned char**)(hud + hud[player + 0x68] * 4 + 0x4C);
                    if (mode != *(int*)(pane + 0x2B0))
                        *(int*)(pane + 0x2B0) = mode;
                    if (((unsigned char*)*(void**)(p + 0x44))[offset + 0x99] == 0)
                        ++soundCount;
                } else {
                    unsigned char* pane = getPane(player);
                    if (*(int*)(pane + 0x2B0) != 0)
                        *(int*)(pane + 0x2B0) = 0;
                }
            } else {
                if (getPane(player)[0x350] != 0)
                    fn_800E4D28(getPane(player), 0);
                unsigned char* pane = getPane(player);
                if (*(int*)(pane + 0x2B0) != 0)
                    *(int*)(pane + 0x2B0) = 0;
            }
            if (active && p[0xC4] && *(int*)(getPane(player) + 0x554) > 0) {
                fn_27_10AD38(markerPos, g_ftManager, entry, -1);
                fn_800E57FC(getPane(player), markerPos);
            }
        }
    }
    if (soundCount != 0) {
        if (*(int*)(p + 0x114) < 0)
            *(int*)(p + 0x114) =
                g_sndSystem->playSE((SndID)0x11, -1, 0, 0, -1);
    } else if (*(int*)(p + 0x114) >= 0) {
        fn_80075F1C(g_sndSystem, *(int*)(p + 0x114), 0);
        *(int*)(p + 0x114) = -1;
    }
}
