#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_103_data_1468[];
void fn_27_57EC4(int* p);
void fn_27_561E0(void*, void*, void*, void*, int, bool, void*);

void* fn_103_7EC4(void* self, void* a, void* b, void* c) {
    u8* object = static_cast<u8*>(self);
    *reinterpret_cast<void**>(object) = lbl_103_data_1468;
    for (s32 i = 0; i < 2; i++) {
        fn_27_57EC4(reinterpret_cast<int*>(object + i * 8 + 4));
    }
    fn_27_561E0(object + 0x14, a, self, b, 1, true, c);
    return self;
}
}
