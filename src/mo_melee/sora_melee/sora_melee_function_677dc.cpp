#include <types.h>
#include <so/stop/so_stop_module_impl.h>
#include <so/so_module_accesser.h>
#include <so/so_world.h>
#include <so/link/so_link_module_impl.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

void soStopModuleImpl::setLinkStop(u32 duration) {
    if (duration == 1) {
        if (m_isStop == 1) return;
    } else {
        if (unk1C_b3 == 1) {
            unk1C_b4 = 0;
            m_isHit = 0;
        }
    }
    unk1C_b3 = duration;
    u8 isHit = m_isHit;
    if (!isHit && !unk1C_b4 && !unk1C_b3 && !m_isSpecialStop && g_soWorld->m_12 == 0) {
        if (m_isStop == 1) {
            bool isDamage = m_isDamage != 0;
            *(s32*)((char*)this + 0x10) = 0;
            *(s32*)((char*)this + 0x14) = 0;
            m_isStop = 0;
            m_isHit = 0;
            unk1C_b3 = 0;
            m_isDamage = 0;
            m_moduleAccesser->m_enumerationStart->m_linkModule->leaveLinkStop();
            m_moduleAccesser->m_enumerationStart->m_statusModule->leaveStop(m_moduleAccesser, isHit != 0, isDamage);
        }
    } else {
        if (!m_isStop) {
            m_isStop = 1;
            m_moduleAccesser->m_enumerationStart->m_linkModule->toLinkStop();
        }
    }
}