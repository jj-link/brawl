#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_45940[];
extern "C" char lbl_27_data_CDF8[];

extern "C" void fn_27_2EBCD0(void*, soModuleAccesser* accesser) {
    int statusKind = accesser->m_enumerationStart->m_statusModule->getStatusKind();
    int kind;
    void* energy;
    void* result;
    switch (statusKind) {
        case 0:
            kind = accesser->m_enumerationStart->m_situationModule->getKind();
            energy = accesser->m_enumerationStart->m_kineticModule->getEnergy(2);
            result = __dynamic_cast(energy, 0, lbl_27_data_45940, lbl_27_data_CDF8, 1);
            if (kind == 2) {
                ((unsigned char*)result)[5] |= 0x80;
            }
            break;
        case 1:
            if (accesser->m_enumerationStart->m_workManageModule->getInt(0x10000006)) {
                accesser->m_enumerationStart->m_workManageModule->setInt(0, 0x10000006);
            }
            break;
    }
}