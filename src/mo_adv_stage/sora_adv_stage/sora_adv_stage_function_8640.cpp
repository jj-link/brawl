#include <gm/gm_global.h>
#include <ft/ft_manager.h>
#include <types.h>

#pragma force_active on

struct Stage {
    void setStageInEffectInit();
};

struct AdvStageFlagsView {
    unsigned char pad0[0x4924];
    unsigned char flags;
};

extern "C" void fn_40_8640(Stage* stage)
{
    AdvStageFlagsView* adv = (AdvStageFlagsView*)g_GameGlobal->m_advData;
    adv->flags &= ~0x04;

    g_ftManager->m_isHomerun = false;

    *(unsigned char*)((char*)g_ftManager + 0x6C) |= 0x80;

    stage->setStageInEffectInit();
}
