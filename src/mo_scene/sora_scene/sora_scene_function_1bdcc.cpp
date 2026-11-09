#include <types.h>
#include <gf/gf_application.h>
#include <gf/gf_scene.h>
#include <gf/gf_resource_loader.h>
#include <gm/gm_global.h>
#include <mu/adv/mu_adv_seal.h>
#pragma force_active on

extern "C" {
void* fn_80158BE0();
void fn_80159420(void*);
int fn_8015A33C(void*);
void fn_8015A358(void*);
}
struct UnkParam {
    union { bool asBool; u32 asInt; } unk0;
    u32 unk4;
};
struct SealSelf {
    void* unk0;
    void* unk4;
    muAdvSealTask* unk8;
    s32 unkC;
    gfArchive* unk10;
    gfResourceLoader* unk14;
};
extern "C" s32 fn_1_1BDCC(SealSelf* self) {
    switch (self->unkC) {
    case 4:
        if (self->unk14->isLoaded()) {
            UnkParam stack20;
            UnkParam stack18;
            UnkParam stack10;
            muAdvSealTaskParam param = {};
            if (g_GameGlobal->m_advData) {
                stack18.unk0.asInt = g_GameGlobal->m_advData->m_record.unk4928;
                stack18.unk4 = g_GameGlobal->m_advData->m_record.unk492C;
            } else {
                stack10.unk0.asBool = false;
                stack10.unk4 = -1;
                stack18 = stack10;
            }
            stack20 = stack18;
            param.unk4 = stack20.unk4;
            self->unk8 = muAdvSealTask::create(&param, self->unk10);
            g_gfApplication->unkD0.endKeepScreen();
            self->unkC = 0;
        }
        break;
    case 0:
        if (self->unk8 && self->unk8->unk40) self->unkC = 1;
        break;
    case 1:
        fn_80159420(fn_80158BE0());
        self->unkC = 2;
        break;
    case 2:
        if (fn_8015A33C(fn_80158BE0())) {
            fn_8015A358(fn_80158BE0());
            self->unkC = 3;
        }
        break;
    case 3: {
        self->unkC = 4;
        gfSceneManager* mgr = gfSceneManager::getInstance();
        mgr->unk1 = 0;
        mgr->processStep = 2;
        break;
    }
    }
    return 0;
}