#include <gf/gf_pad_system.h>
#include <gf/gf_scene.h>
#include <snd/snd_system.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const char lbl_12_data_60[1];
extern const char lbl_12_data_90[1];
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

struct Self {
    char _0[0x44];
    int m_result;
};

static inline gfPadStatus getSysPad() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    return status;
}

extern "C" int fn_12_1184(Self* self) {
    if (getSysPad().m_buttonsPressedThisFrame.bits & 0x1300) {
        g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
        __dynamic_cast(gfSceneManager::getInstance()->m_currentScene, 4, &lbl_12_data_60, &lbl_12_data_90, 0);
        gfSceneManager* mgr = gfSceneManager::getInstance();
        mgr->unk1 = 1;
        mgr->processStep = 2;
    }
    return self->m_result;
}
