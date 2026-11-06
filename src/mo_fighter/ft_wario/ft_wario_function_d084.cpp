#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_110_D084(void*, soModuleAccesser* accesser) {
    if (accesser->m_enumerationStart->m_statusModule->getStatusKind() == 0x127) {
        soLinkModule* link = accesser->m_enumerationStart->m_linkModule;
        if (link->isLink(6)) {
            int node = accesser->m_enumerationStart->m_modelModule->getCorrectNodeId(0x130);
            link->removeModelConstraint(true);
            link->setModelConstraintPosOrt(6, node, 0, 3, false);
        }
    }
}
