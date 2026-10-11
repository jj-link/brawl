#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" {
extern const char lbl_99_data_639C[], lbl_99_data_171C[];
extern const float lbl_99_rodata_10;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_15FBC8(int);
}

extern "C" void fn_99_C7A0(void*, int, void*, soModuleAccesser* accesser) {
    fn_27_15FBC8(10);
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0,
        lbl_99_data_639C, lbl_99_data_171C, 1));
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 0x0c) = lbl_99_rodata_10;
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 0x10) =
        -soValueAccesser::getConstantFloat(accesser, 0xfc5, 0);
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 0x14) =
        soValueAccesser::getConstantFloat(accesser, 0xfc6, 0);
}
