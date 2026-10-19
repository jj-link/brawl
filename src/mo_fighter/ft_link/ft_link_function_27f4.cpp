#include <new>
#pragma force_active on

extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_93_1AC4(void*, int);
extern "C" void __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_93_27F4(void* self, void*, void*, unsigned long kind, void* context) {
    fn_93_1AC4(self, 0);
    *(unsigned char**)self = lbl_27_data_2C030;
    *(void**)((unsigned char*)self + 0x8) = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc((unsigned char*)self + 0xC, 0, self, (unsigned char)kind);
    return self;
}
