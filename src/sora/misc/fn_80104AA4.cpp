#include <types.h>
#include <ut/ut_relocate.h>
#pragma force_active on

extern "C" {
void fn_80104B6C(void* self, void* table, u32 count, u32 arg, u32 prio);
void fn_80104C60(void* self, void* data);
}

extern char lbl_80409218[];
extern char lbl_8045D008[];

extern "C" void fn_80104AA4(void* self, u32 arg1, void* arg2, u32 arg3, u8* arg4, u32 arg5) {
    fn_80104B6C(self, lbl_80409218, 2, arg1, 0xC0);
    fn_80104C60(self, arg2);

    u32 count = 0;
    {
        utRelocate rel(arg4, arg5);
        s32* src = (s32*)rel.getPublicAddress(lbl_8045D008);
        u32* dst = (u32*)self;
        while (*src >= 0) {
            u32 v = *src++;
            count++;
            dst[59] = v;
            dst++;
        }
    }
    *(u32*)((u8*)self + 0x2EC) = count;
    *(u32*)((u8*)self + 0x10) = arg3;
}
