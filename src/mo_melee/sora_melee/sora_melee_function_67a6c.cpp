#include <types.h>
#include <so/stop/so_stop_module_impl.h>
#include <so/so_module_accesser.h>
#include <so/so_world.h>
#include <so/link/so_link_module_impl.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

// shadow vtable layout for soStopModuleImpl (soStopModule group)
class soStopModuleV {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void cancelHitStop();
    virtual void setOtherStop(u32);
    virtual void cancelOtherStop();
    virtual void setLinkStop(u32);
};

void soStopModuleImpl::update() {
    if (g_soWorld->m_12 == 0) {
        s32* p18 = (s32*)((char*)this + 0x18);
        if (*p18 != 0) {
            *p18 = *p18 - 1;
            if (*p18 == 0) {
                unk1C_b4 = 0;
            }
        }
        s32* p10 = (s32*)((char*)this + 0x10);
        if (*p10 != 0) {
            *p10 = *p10 - 1;
            if (*p10 == 0) {
                m_isHit = 0;
            }
        }
    }
    if (unk1C_b3 == 1) {
        soLinkModule* link = m_moduleAccesser->m_enumerationStart->m_linkModule;
        if (link->isValidLinkStop() == 0) {
            ((soStopModuleV*)this)->setLinkStop(0);
            return;
        }
    }
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
            soLinkModule* link = m_moduleAccesser->m_enumerationStart->m_linkModule;
            link->leaveLinkStop();
            soStatusModule* status = m_moduleAccesser->m_enumerationStart->m_statusModule;
            status->leaveStop(m_moduleAccesser, isHit != 0, isDamage);
        }
    } else {
        if (!m_isStop) {
            m_isStop = 1;
            m_moduleAccesser->m_enumerationStart->m_linkModule->toLinkStop();
        }
    }
}
