#include <cstring>
#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <gf/gf_scene.h>
#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_800B9984(void*);
extern char lbl_18_data_664[];
extern char lbl_18_data_6D0[];
extern char lbl_18_data_700[];
}
struct MenuRule {
    u32 _00, _04, _08, _0c, _10, _14;
    u8 _18[0x28];
    u16 _40, _42;
    u8 _44;
    u8 _45[0x543];
    u32 _588, _58c, _590, _594, _598;
};
extern "C" u32 fn_18_12E0(MenuRule* self) {
    u32 result = 0;
    u8 i;
    s32 scenePtr = 0;
    if (strcmp(gfSceneManager::getInstance()->m_currentScene->m_sceneName, lbl_18_data_664) == 0) {
        char* p = (char*)__dynamic_cast(gfSceneManager::getInstance()->m_currentScene, 4, lbl_18_data_6D0, lbl_18_data_700, 0);
        scenePtr = *(s32*)(p + 0xAB8);
    }
    if (self->_44 == 0 || scenePtr > 0) {
        ((gfPadStatus*)self)->init();
        return 0;
    }
    gfPadStatus st;
    gfPadStatus pads[8];
    if (self->_44 == 0xFF) {
        g_gfPadSystem->getSysPadStatus(0xF0, (gfPadStatus*)self);
        fn_800B9984(&self->_588);
        self->_14 = self->_598;
        self->_04 = self->_590;
    } else {
        scenePtr = 0;
        i = 0;
        do {
            if (self->_44 & (1 << (u8)scenePtr)) {
                g_gfPadSystem->getSysPadStatus((u8)scenePtr, &pads[i]);
                fn_800B9984((char*)self + (u8)scenePtr * 0xA8 + 0x48);
                i++;
            }
            scenePtr++;
        } while ((u32)scenePtr < 8);
        fn_800B9984(&self->_588);
        gfPadSystem::merge(pads, i, (gfPadStatus*)self);
        for (u8 j = 0; j < 8; j++) {
            if (self->_44 & (1u << j)) {
                self->_14 |= *(u32*)((char*)self + j * 0xA8 + 0x58);
                self->_04 |= *(u32*)((char*)self + j * 0xA8 + 0x50);
            }
        }
    }
    if (self->_0c & 0x100) result |= 0x200;
    if (self->_0c & 0x40) result |= 0x40;
    if (self->_0c & 0x20) result |= 0x80;
    if (self->_0c & 0x400) result |= 0x400;
    if (self->_0c & 0x800) result |= 0x800;
    if (self->_0c & 0x1000) result |= 0x100;
    if ((self->_0c & 0x100) || (self->_0c & 0x1000)) {
        result |= 0x10;
        u16 k = 0;
        for (k = 0; k < 4; k++) {
            g_gfPadSystem->getSysPadStatus(k, &st);
            if ((st.m_buttonsPressedThisFrame.bits & 0x100) || (st.m_buttonsPressedThisFrame.bits & 0x1000)) {
                self->_40 = k;
                break;
            }
        }
    }
    if (self->_0c & 0x200) result |= 0x20;
    if (self->_14 & 0x8) result |= 0x1;
    if (self->_14 & 0x4) result |= 0x2;
    if (self->_14 & 0x1) result |= 0x4;
    if (self->_14 & 0x2) result |= 0x8;
    if ((self->_0c & 0x100) && (self->_0c & 0x1000) && (self->_0c & 0x40) && (self->_0c & 0x20)) result |= 0x1000;
    return result;
}