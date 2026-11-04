#include <types.h>
#pragma force_active on
struct Manager { u8 pad[0x6f]; u8 a : 3; u8 flag : 1; u8 b : 4; };
struct Obj { u8 pad[0x138]; u8 flags; u8 pad2[3]; };
extern Manager* g_ftManager;
extern "C" void fn_27_158D6C(void*, int);
extern "C" void fn_27_132278(Obj* self, u32 arg) {
    if (arg == 1u && (u32)(g_ftManager->flag != 0) == 1u) {
        if (!((self->flags >> 1) & 1)) {
            fn_27_158D6C((char*)self + 0x13c, 1);
            self->flags |= 2;
        }
    } else if (((u32)(self->flags >> 1) & 1u) == 1u) {
        fn_27_158D6C((char*)self + 0x13c, 0);
        self->flags &= ~2;
    }
}