#pragma force_active on
extern "C" {
void fn_91_1A70(void*, int);
void __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);
extern unsigned char lbl_27_data_2C030[];

void* fn_91_27B0(void* object, int a2, int a3, unsigned char flag, void* accesser) {
    unsigned char* self = static_cast<unsigned char*>(object);
    fn_91_1A70(object, 0);
    *reinterpret_cast<unsigned char**>(self) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(self + 8) = accesser;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(self + 0xc, 0, self, flag);
    return object;
}
}
