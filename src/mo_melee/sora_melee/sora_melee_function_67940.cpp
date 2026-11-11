#include <types.h>
#define private public
#include <so/stop/so_stop_module_impl.h>
#undef private
#include <so/so_module_accesser.h>
#include <so/so_world.h>
#include <so/link/so_link_module_impl.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

extern "C" void setSpecialStop__16soStopModuleImplFUl(soStopModuleImpl* self, u32 duration) {
    bool isDamage = false;
    soStopModuleImpl* saved = self;
    self->m_isSpecialStop = duration;
    u32 isHit = self->m_isHit;
    if (!isHit && !self->unk1C_b4 && !self->unk1C_b3 &&
        !self->m_isSpecialStop && g_soWorld->m_12 == 0) {
        if (self->m_isStop == 1) {
            isDamage = self->m_isDamage != 0;
            *(s32*)((char*)self + 0x10) = 0;
            *(s32*)((char*)self + 0x14) = 0;
            self->m_isStop = 0;
            self->m_isHit = 0;
            self->unk1C_b3 = 0;
            self->m_isDamage = 0;
            saved->m_moduleAccesser->m_enumerationStart->m_linkModule->leaveLinkStop();
            saved->m_moduleAccesser->m_enumerationStart->m_statusModule->leaveStop(
                saved->m_moduleAccesser, isHit != 0, isDamage);
        }
    } else if (!self->m_isStop) {
        self->m_isStop = 1;
        saved->m_moduleAccesser->m_enumerationStart->m_linkModule->toLinkStop();
    }
}