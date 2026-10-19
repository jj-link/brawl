#pragma force_active on
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_126_50F0(void* self, unsigned char value);
extern "C" void __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_126_5524(void* self, void*, void*, unsigned char value, void* context) {
    unsigned char* object = static_cast<unsigned char*>(self);
    fn_126_50F0(self, 0);
    *reinterpret_cast<unsigned char**>(object) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(object + 0x8) = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(object + 0xC, 0, self, value);
    return self;
}
