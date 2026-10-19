#pragma force_active on
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_121_1AC4(void* self, int val);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_121_27F4(void* self, void*, void*, unsigned char kind, void* context) {
    fn_121_1AC4(self, 0);
    *reinterpret_cast<void**>(self) = lbl_27_data_2C030;
    *reinterpret_cast<void**>((unsigned char*)self + 0x8) = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc((unsigned char*)self + 0xC, 0, self, kind);
    return self;
}
