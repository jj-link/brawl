#include <so/so_value_accesser.h>
#include <mt/mt_prng.h>
#pragma force_active on
#pragma fp_contract off

extern const float lbl_27_rodata_7B94;
extern const float lbl_27_rodata_7B98;

extern "C" void fn_27_371DDC(void*, int kind, void*, void*, soModuleAccesser* accesser) {
    switch (kind) {
    case 2: {
        float chance = soValueAccesser::getConstantFloat(accesser, 0xFA0, 0);
        if (randf() >= chance) {
            Vec3f pos = accesser->m_enumerationStart->m_postureModule->getPos();
            if (!accesser->m_enumerationStart->m_workManageModule->isFlag(0x12000003)) {
                accesser->m_enumerationStart->m_effectModule->req((EfID)0x20000B, &pos, &Vec3f(lbl_27_rodata_7B94, lbl_27_rodata_7B94, lbl_27_rodata_7B94), lbl_27_rodata_7B98, 0, -1);
            } else {
                accesser->m_enumerationStart->m_effectModule->req((EfID)0x1210004, &pos, &Vec3f(lbl_27_rodata_7B94, lbl_27_rodata_7B94, lbl_27_rodata_7B94), lbl_27_rodata_7B98, 0, -1);
            }
        }
        break;
    }
    case 1: {
        Vec3f pos = accesser->m_enumerationStart->m_postureModule->getPos();
        if (!accesser->m_enumerationStart->m_workManageModule->isFlag(0x12000003)) {
            accesser->m_enumerationStart->m_effectModule->req((EfID)0x20000B, &pos, &Vec3f(lbl_27_rodata_7B94, lbl_27_rodata_7B94, lbl_27_rodata_7B94), lbl_27_rodata_7B98, 0, -1);
        } else {
            accesser->m_enumerationStart->m_effectModule->req((EfID)0x1210004, &pos, &Vec3f(lbl_27_rodata_7B94, lbl_27_rodata_7B94, lbl_27_rodata_7B94), lbl_27_rodata_7B98, 0, -1);
        }
        break;
    }
    }
}
