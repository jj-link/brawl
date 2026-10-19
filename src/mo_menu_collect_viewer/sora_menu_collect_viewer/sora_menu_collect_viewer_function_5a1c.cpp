#include <types.h>
#pragma force_active on

extern "C" void exit__6gfTaskFv(void*);

extern "C" void fn_6_5A1C(u8* self, s32 val) {
    u8* obj = *(u8**)(self + 0x1ac);
    u8* task = *(u8**)(obj + 0x1cfc);
    if (task == nullptr || *(s32*)(task + 0x104) == 3) {
        if (task != nullptr) {
            exit__6gfTaskFv(task);
        }
        *(u8**)(obj + 0x1cfc) = nullptr;
        u8* obj2 = *(u8**)(self + 0x1ac);
        *(s32*)(obj2 + 0x1bfc) = val;
    }
}
