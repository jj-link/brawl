#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_71CC(void* owner, u8 flag);
extern char lbl_103_data_6FB8[];

void* fn_103_12E8C(void* self, void* arg) {
    fn_103_71CC(self, 0);
    *reinterpret_cast<void**>(self) = lbl_103_data_6FB8;
    *reinterpret_cast<void**>(reinterpret_cast<u8*>(self) + 0x8) = arg;
    *reinterpret_cast<s32*>(reinterpret_cast<u8*>(self) + 0xC) = -1;
    return self;
}
}
