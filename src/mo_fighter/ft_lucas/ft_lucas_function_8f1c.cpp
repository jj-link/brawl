#pragma force_active on
extern "C" void fn_114_8AE8(void* self, unsigned char value);
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_114_8F1C(void* self, int unused1, int unused2, unsigned char kind, void* accesser) {
    fn_114_8AE8(self, 0);
    unsigned long* words = reinterpret_cast<unsigned long*>(self);
    words[0] = reinterpret_cast<unsigned long>(lbl_27_data_2C030);
    words[2] = reinterpret_cast<unsigned long>(accesser);
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(reinterpret_cast<unsigned char*>(self) + 0xC, 0, self, kind);
    return self;
}
