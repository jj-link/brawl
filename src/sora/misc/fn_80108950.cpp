#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

extern "C" {
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, int, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);

void* fn_80108950(u8* self, u32 arg1) {
    void* msg;
    *(u32*)(self + 0x28) = arg1;
    *(u32*)(self + 0x24) = 0;
    *(u32*)(self + 0x2C) = 0;
    *(u8*)(self + 0x34) = 0;
    *(u8*)(self + 0x39) = 0;
    *(u32*)(self + 0x3C) = 0;
    *(u32*)(self + 0x40) = 0;
    msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(8, 0x28, 0x2A);
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
    *(u8*)(self + 0x35) = 0;
    *(u8*)(self + 0x37) = 0;
    *(u8*)(self + 0x30) = 0;
    *(u8*)(self + 0x32) = 0;
    *(u8*)(self + 0x36) = 0;
    *(u8*)(self + 0x38) = 0;
    *(u8*)(self + 0x31) = 0;
    *(u8*)(self + 0x33) = 0;
    return self;
}
}
