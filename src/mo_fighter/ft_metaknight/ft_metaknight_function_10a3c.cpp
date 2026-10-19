#include <types.h>
#pragma force_active on

extern "C" void fn_111_5E60(void* self, u8 flag);
extern "C" u8 lbl_111_data_6704[];

extern "C" void* fn_111_10A3C(void* self, void* arg) {
    fn_111_5E60(self, 0);
    *static_cast<u8**>(self) = lbl_111_data_6704;
    *reinterpret_cast<void**>(static_cast<u8*>(self) + 8) = arg;
    *reinterpret_cast<s32*>(static_cast<u8*>(self) + 0xC) = -1;
    return self;
}
