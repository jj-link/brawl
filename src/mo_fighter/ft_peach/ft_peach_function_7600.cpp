#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_data_2C030[];
void* fn_103_71CC(void* owner, u8 flag);
void __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void* self, u32 a, void* b, u8 c);
}

extern "C" void* fn_103_7600(void* self, u32 unused4, u32 unused5, u32 flag, void* value) {
    fn_103_71CC(self, 0);
    *reinterpret_cast<unsigned char**>(self) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(static_cast<u8*>(self) + 0x8) = value;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(static_cast<u8*>(self) + 0xC, 0, self, static_cast<u8>(flag));
    return self;
}
