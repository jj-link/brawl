#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/status/so_status_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

struct CaptainStopEnergyView : soKineticEnergy {
    Vec2f speed;
};

extern "C" {
extern const char lbl_100_data_6138[], lbl_100_data_16D4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_100_D02C(void*, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x118:
        if (accesser->getWorkManageModule().getInt(0x20000000) == 0) {
            CaptainStopEnergyView* stop =
                static_cast<CaptainStopEnergyView*>(__dynamic_cast(
                    accesser->getKineticModule().getEnergy(3), 0,
                    lbl_100_data_6138, lbl_100_data_16D4, 1));
            Vec2f speed;
            Vec2f::copy(speed, stop->getSpeed());
            float multiplier =
                soValueAccesser::getConstantFloat(accesser, 0xfa5, 0);
            stop->speed = speed * multiplier;
        }
        break;
    }
}
