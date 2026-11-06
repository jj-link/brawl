#pragma force_active on
#include <types.h>
#include <mt/mt_vector.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/controller/so_controller_impl.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>

extern "C" {
void fn_27_30FC50(void* self, soModuleAccesser* accesser);
void* __dynamic_cast(void* p, long offset, const void* srcType, const void* dstType, short hint);
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_7458;
}

extern "C" void fn_27_310124(void* self, soModuleAccesser* accesser) {
    int state = accesser->getWorkManageModule().getInt(0x20000000);
    if (state != accesser->getWorkManageModule().getInt(0x20000001)) {
        fn_27_30FC50(self, accesser);
    }
    switch (state) {
    case 0:
        if (accesser->getSituationModule().getKind() == 2) {
            if (accesser->getWorkManageModule().getInt(0x20000002) == 0) {
                soKineticEnergy* energy = reinterpret_cast<soKineticEnergy*>(__dynamic_cast(
                    accesser->getKineticModule().getEnergy(1), 0,
                    lbl_27_data_2E430, lbl_27_data_CDF8, 1));
                float zero = lbl_27_rodata_7458;
                Vec2f v2;
                Vec3f v3;
                v3.m_x = zero;
                v3.m_y = zero;
                v3.m_z = zero;
                v2.m_x = zero;
                v2.m_y = zero;
                energy->resetEnergy(0, &v2, &v3, accesser);
                *reinterpret_cast<float*>(reinterpret_cast<u8*>(energy) + 0x10) = -soValueAccesser::getConstantFloat(accesser, 0xFA8, 0);
                *(reinterpret_cast<u8*>(energy) + 5) |= 0x80;
            }
        }
        break;
    case 1: {
        soControllerModule* controller = &accesser->getControllerModule();
        int mask = soController::getButtonMask(soController::Pad_Button_Special);
        int trigger = controller->getTrigger().m_mask;
        if (trigger & mask) {
            accesser->getWorkManageModule().incInt(0x20000000);
            accesser->getWorkManageModule().onFlag(0x22000011);
            accesser->getWorkManageModule().onFlag(0x22000010);
            fn_27_30FC50(self, accesser);
        }
        break;
    }
    case 2:
        if (accesser->getSituationModule().getKind() == 2) {
            if (accesser->getWorkManageModule().getInt(0x20000002) == 0) {
                soKineticEnergy* energy = reinterpret_cast<soKineticEnergy*>(__dynamic_cast(
                    accesser->getKineticModule().getEnergy(1), 0,
                    lbl_27_data_2E430, lbl_27_data_CDF8, 1));
                float zero = lbl_27_rodata_7458;
                Vec2f v2;
                Vec3f v3;
                v3.m_x = zero;
                v3.m_y = zero;
                v3.m_z = zero;
                v2.m_x = zero;
                v2.m_y = zero;
                energy->resetEnergy(0, &v2, &v3, accesser);
                *reinterpret_cast<float*>(reinterpret_cast<u8*>(energy) + 0x10) = -soValueAccesser::getConstantFloat(accesser, 0xFAD, 0);
                *(reinterpret_cast<u8*>(energy) + 5) |= 0x80;
            }
        }
        break;
    }
}
