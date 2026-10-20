#include <types.h>
#pragma force_active on

extern "C" {
void exit__6gfTaskFv(void*);

s32 fn_6_9DC8(u8* self) {
    u8* task = *(u8**)(self + 0x750);
    if (*(s32*)(task + 0x104) == 3) {
        u8 flag = *(task + 0x100);
        exit__6gfTaskFv(task);
        *(u8**)(self + 0x750) = 0;
        return flag ? 14 : 7;
    }
    return *(s32*)(self + 0x124);
}
}
