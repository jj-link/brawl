#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
void* memset(void* dst, int c, unsigned int n);
extern unsigned char lbl_80461600[0x68];
extern unsigned char lbl_8059E7F0[0x7];
}

extern "C" void* fn_80151B38(void* self, unsigned char arg) {
    u8* p = (u8*)self;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, (const char*)lbl_8059E7F0, 0x26, 0xE, 0xD, true);
    *(u32*)(p + 0x40) = 0;
    *(u8**)(p + 0x3C) = lbl_80461600;
    *(u32*)(p + 0x44) = 0;
    p[0x48] = 0;
    p[0x49] = 0;
    *(u32*)(p + 0x4C) = 0;
    *(u32*)(p + 0x50) = 0;
    *(u32*)(p + 0x54) = 0;
    *(u32*)(p + 0x58) = 0;
    p[0x5C] = arg;
    memset(p + 0x60, 0, 0x18);
    p[0x2C] = p[0x2C] & ~2;
    return self;
}
