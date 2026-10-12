#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" {
void fn_117_F2D8(void*, soModuleAccesser*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_117_data_84DC[], lbl_117_data_36A8[];
extern const float lbl_117_rodata_40;
}

extern "C" void fn_117_F15C(void* self, soModuleAccesser* accesser) {
    fn_117_F2D8(self, accesser);
    soWorkManageModule& work = accesser->getWorkManageModule();
    int limit = soValueAccesser::getConstantInt(accesser, 0x5DC5, 0);
    if (work.getInt(0x20000002) <= limit) {
        accesser->getWorkManageModule().addInt(1, 0x20000002);
    }
    soWorkManageModule& updatedWork = accesser->getWorkManageModule();
    int updatedLimit = soValueAccesser::getConstantInt(accesser, 0x5DC5, 0);
    int count = updatedWork.getInt(0x20000002);
    if (count == updatedLimit) {
        soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(1), 0,
            lbl_117_data_84DC, lbl_117_data_36A8, 1));
        Vec3f rotation(lbl_117_rodata_40, lbl_117_rodata_40, lbl_117_rodata_40);
        Vec2f speed(lbl_117_rodata_40, lbl_117_rodata_40);
        energy->resetEnergy(0, &speed, &rotation, accesser);
        // soEnable's packed enable flag occupies the high bit of byte five.
        reinterpret_cast<unsigned char*>(energy)[5] |= 0x80;
    }
}
