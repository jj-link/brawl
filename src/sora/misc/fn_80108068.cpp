#include <types.h>
#pragma force_active on

extern "C" void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
extern "C" void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);

extern "C" void* fn_80108068(u8* self, u32 arg1, u32 arg2, u32 arg3) {
    *(u32*)(self + 0x24) = arg1;
    *(u32*)(self + 0x38) = arg2;
    *(u32*)(self + 0x30) = 0;
    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(8, 0x28, 0x2A);
    *(void**)(self + 0x20) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x100, 2);
    *(u32*)(self + 0x0) = 0;
    *(u32*)(self + 0x4) = 0;
    *(u32*)(self + 0x8) = 0;
    *(u32*)(self + 0xC) = 0;
    *(u32*)(self + 0x10) = 0;
    *(u32*)(self + 0x14) = 0;
    *(u32*)(self + 0x18) = 0;
    *(u32*)(self + 0x1C) = 0;
    return self;
}
