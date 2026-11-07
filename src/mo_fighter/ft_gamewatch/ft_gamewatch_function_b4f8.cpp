#include <it/it_manager.h>
#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
extern const float lbl_107_rodata_30;
extern const float lbl_107_rodata_C;
Vec3f* fn_107_B444(Vec3f*, float, float, float);
}

extern "C" void fn_107_B4F8(void*, void* arg1, soModuleAccesser* accesser) {
    if (accesser->m_enumerationStart->m_motionModule->getKind() == 0x1d6) {
        if (accesser->m_enumerationStart->m_workManageModule->isFlag(0x1200003F) == false && *((unsigned char*)arg1 + 0x22) == 0xA) {
            accesser->m_enumerationStart->m_workManageModule->onFlag(0x1200003F);
            Vec3f rot;
            fn_107_B444(&rot, lbl_107_rodata_C, lbl_107_rodata_30, lbl_107_rodata_C);
            int zero = 0;
            Vec3f pos = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0x1d, &rot, zero, zero);
            float lr = accesser->m_enumerationStart->m_postureModule->getLr();
            itManager::getInstance()->createItem(&pos, lr, (itKind)0x40, 0, -1, NULL, zero);
        }
    }
}
