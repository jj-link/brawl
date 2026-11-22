#include <so/so_module_accesser.h>
#pragma force_active on
#pragma scheduling off
#pragma optimization_level 2
extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
extern const float lbl_27_rodata_7AF0;
extern const char lbl_27_data_2E5F8[], lbl_27_data_CDF8[];
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
float fn_27_192278(void*, unsigned long);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_27_331BEC(Vec3f*, float, float, float);
}
extern "C" void fn_27_3645BC(void*, soModuleAccesser* accesser) {
    int status = accesser->getStatusModule().getStatusKind();
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, accesser, 1)) {
    case 0x117:
        accesser->getWorkManageModule().setFloat(lbl_27_rodata_7AF0, 0x21000004);
        break;
    case 0x118: {
        soWorkManageModule& work = accesser->getWorkManageModule();
        float speed = work.getFloat(0x21000004) * fn_27_192278(accesser, 0xfa4);
        speed *= -accesser->getPostureModule().getLr();
        soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(3), 0,
            lbl_27_data_2E5F8, lbl_27_data_CDF8, 1));
        if (accesser->getSituationModule().getKind() == 0) {
            Vec2f velocity(speed, lbl_27_rodata_7AF0);
            Vec3f rotation;
            energy->resetEnergy(0, &velocity,
                fn_27_331BEC(&rotation, lbl_27_rodata_7AF0,
                            lbl_27_rodata_7AF0, lbl_27_rodata_7AF0),
                accesser);
        } else {
            Vec2f velocity(speed, lbl_27_rodata_7AF0);
            Vec3f rotation;
            energy->resetEnergy(6, &velocity,
                fn_27_331BEC(&rotation, lbl_27_rodata_7AF0,
                            lbl_27_rodata_7AF0, lbl_27_rodata_7AF0),
                accesser);
        }
        reinterpret_cast<unsigned char*>(energy)[5] |= 0x80;
        break;
    }
    }
}