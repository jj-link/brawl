#include <types.h>
#pragma force_active on

class gfTask {
public:
    enum Category { Category_Info = 0 };
};

extern "C" {
extern const char lbl_80454AF0[];
extern char lbl_80454B10[];
gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(gfTask*, const char*, gfTask::Category, int, int, bool);

gfTask* fn_8009A104(gfTask* self) {
    char* p = (char*)self;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_80454AF0, (gfTask::Category)0x23, 0xe, 0xd, true);
    *(char**)(p + 0x3c) = lbl_80454B10;
    *(u8*)(p + 0x40) = 1;
    *(u8*)(p + 0x41) = 0;
    *(u8*)(p + 0x42) = 1;
    *(u8*)(p + 0x43) = 1;
    *(u8*)(p + 0x44) = 1;
    *(u8*)(p + 0x45) = 1;
    *(u8*)(p + 0x46) = 0;
    *(u8*)(p + 0x47) = 0;
    *(u32*)(p + 0x48) = 0;
    *(u32*)(p + 0x4c) = 0;
    *(u32*)(p + 0x50) = 0;
    *(u32*)(p + 0x54) = 0;
    *(u32*)(p + 0x58) = 0;
    *(u8*)(p + 0x5c) = 0;
    *(u32*)(p + 0x60) = 0;
    *(u32*)(p + 0x64) = 0;
    *(u32*)(p + 0x68) = 0x80000000;
    *(u32*)(p + 0x6c) = 0;
    *(u32*)(p + 0x70) = 0;
    *(u32*)(p + 0x74) = 0x80000000;
    *(u8*)(p + 0x78) = 0;
    *(u32*)(p + 0x84) = 0;
    *(u32*)(p + 0x88) = 0;
    *(u32*)(p + 0x8c) = 0;
    *(u32*)(p + 0x90) = 0;
    *(u32*)(p + 0x94) = 0;
    *(u32*)(p + 0x98) = 0;
    *(u32*)(p + 0x9c) = 0;
    *(u32*)(p + 0xa0) = 0;
    *(u32*)(p + 0xa4) = 0;
    *(u32*)(p + 0xa8) = 0;
    return self;
}
}
