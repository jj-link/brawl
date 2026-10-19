#pragma force_active on
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_102_60D0(void*, int);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_102_6504(void* object, int a1, int a2, unsigned int kind, void* context) {
    unsigned char* self = static_cast<unsigned char*>(object);
    fn_102_60D0(object, 0);
    *reinterpret_cast<void**>(self) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(self + 8) = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(self + 0xC, 0, object, static_cast<unsigned char>(kind));
    return object;
}
