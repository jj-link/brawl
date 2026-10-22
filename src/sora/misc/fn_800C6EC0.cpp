#include <types.h>
#pragma force_active on

extern "C" char* strcat(char* dst, const char* src);

extern "C" void fn_800C6EC0(void* self, u32* args, u32 a, u32 b) {
    u8* p = (u8*)self;
    u32 v = args[0];
    p[0x204] = 0;
    strcat((char*)(p + 0x204), (const char*)(args + 1));
    p[0x380] = 1;
    *(u32*)(p + 0x384) = v;
    *(char**)(p + 0x388) = (char*)(p + 0x204);
    *(u32*)(p + 0x38c) = a;
    *(u32*)(p + 0x390) = b;
    *(u32*)(p + 0x350) = 4;
}
