#pragma force_active on
extern "C" {
void fn_92_6DC4(void*, unsigned char);
void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);
extern unsigned char lbl_27_data_2C030[];
}

extern "C" void* fn_92_71F8(void* self, void*, void*, unsigned int kind, unsigned int context) {
    fn_92_6DC4(self, 0);
    *(void**)self = lbl_27_data_2C030;
    *(void**)((unsigned char*)self + 8) = (void*)context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc((unsigned char*)self + 0xC, 0, self, (unsigned char)kind);
    return self;
}
