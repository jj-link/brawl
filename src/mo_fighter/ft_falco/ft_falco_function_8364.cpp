#pragma force_active on
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_108_7F30(void* self, int arg);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_108_8364(void* self, int unused1, int unused2, unsigned int kind, void* context) {
    unsigned int* object = static_cast<unsigned int*>(self);
    fn_108_7F30(self, 0);
    object[0] = reinterpret_cast<unsigned int>(lbl_27_data_2C030);
    object[2] = reinterpret_cast<unsigned int>(context);
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(reinterpret_cast<unsigned char*>(self) + 0xC, 0, self, static_cast<unsigned char>(kind));
    return self;
}
