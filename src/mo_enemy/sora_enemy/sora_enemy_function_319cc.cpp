#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/link/so_link_module_impl.h>
#include <so/ground/so_ground_module_impl.h>
#include <em/wnem/wn_em_report.h>
#pragma force_active on
extern "C" char lbl_41_data_4608[];
extern "C" char lbl_41_data_4636[];
extern "C" void fn_41_319CC(char* self) {
    soModuleAccesser* access = *(soModuleAccesser**)(self + 0x6c);
    int value = access->m_enumerationStart->m_workManageModule->getInt(0x10000005);
    int node = *(int*)(self + 0x218c);
    if ((unsigned int)(value + 0x10000) == 0xffff || (unsigned int)(*(int*)(*(char**)(self + 0x2184) + 0x20) + 0x10000) == 0xffff || (unsigned int)(node + 0x10000) == 0xffff) {
        wnemReport(lbl_41_data_4608);
        return;
    }
    if (*(int*)(self + 0x21dc) == 2)
        (*(soModuleAccesser**)(self + 0x6c))->m_enumerationStart->m_linkModule->setAttribute(3, (soLinkConnection::Attribute)9, true);
    (*(soModuleAccesser**)(self + 0x6c))->m_enumerationStart->m_linkModule->setModelConstraintPosOrt(3, *(int*)(*(char**)(self + 0x2184) + 0x20), node, 11, true);
    if (*(int*)(self + 0x21dc) == 2) {
        (*(soModuleAccesser**)(self + 0x6c))->m_enumerationStart->m_linkModule->setAttribute(3, (soLinkConnection::Attribute)9, true);
        wnemReport(lbl_41_data_4636);
    }
    (*(soModuleAccesser**)(self + 0x6c))->m_enumerationStart->m_groundModule->setCorrect((soGroundShapeImpl::CorrectKind)0, 0);
}