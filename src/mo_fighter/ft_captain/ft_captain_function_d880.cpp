#include <so/so_module_accesser.h>
#pragma force_active on

struct CaptainParams {
    float unused;
    float multiplier;
};

struct CaptainEnergyView {
    char reserved[0x40];
    float value;
};

extern "C" {
CaptainParams* fn_100_8C4C();
extern const char lbl_100_data_6474[], lbl_100_data_16D4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_100_D880(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    soStatusModule* status = &accesser->getStatusModule();
    int previous = work->getInt(0x20000000);
    accesser->getSituationModule().getKind();

    switch (status->getStatusKind()) {
    case 0x115:
        if (previous == 0) {
            int count = work->getInt(0x20000001);
            if (count >= 1) {
                CaptainParams* params = fn_100_8C4C();
                float value = work->getFloat(0x21000004);
                value *= params->multiplier;

                CaptainEnergyView* energy =
                    static_cast<CaptainEnergyView*>(__dynamic_cast(
                        accesser->getKineticModule().getEnergy(0), 0,
                        lbl_100_data_6474, lbl_100_data_16D4, 1));
                energy->value = value;
                work->setFloat(value, 0x21000004);
                work->setInt(count - 1, 0x20000001);
            }
        }
        break;
    case 0x11b:
        break;
    }
}
