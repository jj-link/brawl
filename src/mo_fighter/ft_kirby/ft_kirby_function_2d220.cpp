#include <so/so_module_accesser.h>
#pragma force_active on

struct KirbyEnergy {
    unsigned char padding[5];
    unsigned char flag : 1;
    unsigned char remaining : 7;
};

extern "C" {
extern const char lbl_96_data_CEF4[];
extern const char lbl_96_data_5E00[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_96_2D8B4(void*, soModuleAccesser*);
}

extern "C" void fn_96_2D220(void* self, soModuleAccesser* accesser)
{
    KirbyEnergy* energy = static_cast<KirbyEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(0),
        0,
        lbl_96_data_CEF4,
        lbl_96_data_5E00,
        1));

    switch (accesser->getStatusModule().getStatusKind()) {
    case 0:
        accesser->getWorkManageModule().onFlag(0x22000000);
        break;

    case 1:
        energy->flag = 0;
        fn_96_2D8B4(self, accesser);
        break;

    case 2:
    case 3:
    case 4:
        fn_96_2D8B4(self, accesser);
        break;
    }
}
