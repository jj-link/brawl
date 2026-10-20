#include <types.h>
#pragma force_active on

extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
extern char lbl_27_data_4E038[];
extern u8* g_GameGlobal;

void* fn_27_241E30(void* self, const char* name) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, name, 0, 13, 6, true);
    u8* p = (u8*)self;
    *(char**)(p + 0x3c) = lbl_27_data_4E038;
    p[0x40] = 0;
    p[0x41] = 0;
    p[0x42] = 0;
    p[0x43] = 0;
    *(u32*)(p + 0x44) = 0;
    *(u32*)(p + 0x44) = *(u32*)(g_GameGlobal + 0x8);
    return self;
}
}
