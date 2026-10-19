#include <types.h>
#pragma force_active on

extern "C" void fn_10_145F0(void* self, int a);
extern "C" void fn_10_148E8(void* self, int a);
extern "C" void fn_800B9804(void*, int);
extern "C" void fn_10_11C50(void* self);

extern "C" void fn_10_13068(void* self, int a) {
    u8* base = (u8*)self;
    fn_10_145F0(self, 0x23);
    fn_10_148E8(self, a);
    fn_800B9804(base + 4, a & 0xFF);
    fn_10_11C50(self);
    u8* block = *(u8**)(base + 0x1A8);
    *(float*)(block + 0x90) = *(float*)(block + 0x84);
    *(float*)(block + 0x94) = *(float*)(block + 0x88);
    *(float*)(block + 0x98) = *(float*)(block + 0x8C);
    *(int*)base = 0;
}
