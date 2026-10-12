// Keep the event switch table in its original four-byte-aligned REL range.
#pragma section data_type ".data$dedede1A290" ".bss"

#include <so/stageobject.h>
#include <mo_fighter/ft_dedede/ft_dedede_link_event.h>

extern "C" void fn_117_1A290(StageObject* object, soLinkEventArgs* event,
                             soModuleAccesser* accesser, StageObject* sender, int context) {
    switch (event->m_eventKind) {
    case 0x838:
        object->m_moduleAccesser->m_enumerationStart->m_workManageModule->offFlag(0x22000001);
        object->m_moduleAccesser->m_enumerationStart->m_workManageModule->onFlag(0x22000000);
        break;
    case 0x839:
        object->m_moduleAccesser->m_enumerationStart->m_workManageModule->onFlag(0x22000001);
        object->m_moduleAccesser->m_enumerationStart->m_workManageModule->onFlag(0x22000000);
        break;
    case 0x83a:
        object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusRequest(0, object->m_moduleAccesser);
        break;
    case 0x83b:
        object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusRequest(1, object->m_moduleAccesser);
        break;
    case 0x83c:
        object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusRequest(2, object->m_moduleAccesser);
        break;
    case 0x83d:
        object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusRequest(3, object->m_moduleAccesser);
        break;
    case 0x83e:
        object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusRequest(4, object->m_moduleAccesser);
        break;
    case 0x83f:
        object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusRequest(5, object->m_moduleAccesser);
        break;
    case 0x840:
        object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusRequest(6, object->m_moduleAccesser);
        break;
    case 0x841:
        object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusRequest(7, object->m_moduleAccesser);
        break;
    case 0x842:
        object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusRequest(8, object->m_moduleAccesser);
        break;
    case 0x843:
        object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusRequest(9, object->m_moduleAccesser);
        break;
    case 0x844:
        object->m_moduleAccesser->m_enumerationStart->m_workManageModule->onFlag(0x22000002);
        break;
    }
    fn_27_1DB0F0(object, event, accesser, sender, context);
}
