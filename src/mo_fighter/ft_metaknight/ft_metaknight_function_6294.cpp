#include <types.h>
#pragma force_active on

extern "C" void fn_111_5E60(void* self, unsigned char flag);
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void* self, unsigned long id, void* accesser, unsigned char flag);

extern "C" void* fn_111_6294(void* self, s32 p2, s32 p3, s32 flag, void* p7) {
    fn_111_5E60(self, 0);
    *reinterpret_cast<unsigned char**>(self) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(self) + 8) = p7;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
        reinterpret_cast<unsigned char*>(self) + 0xC, 0, self, static_cast<unsigned char>(flag));
    return self;
}
