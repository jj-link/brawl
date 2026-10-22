#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

extern "C" void* fn_802DA104(int);
extern "C" char lbl_80487B10[];

extern "C" void* fn_802DDA34(void* self, void* arg) {
    char* p = (char*)self;
    *(u32*)(p + 0x8) = 0;
    *(u16*)(p + 0x6) = 1;
    *(void**)(p + 0x0) = lbl_80487B10;
    *(char**)(p + 0xC) = p + 0x18;
    *(u32*)(p + 0x10) = 0;
    *(u32*)(p + 0x14) = 0x80000008;
    *(void**)(p + 0x28) = arg;
    char* q = (char*)fn_802DA104(0);
    *(void**)(p + 0x2C) = q;
    *(u16*)(q + 0x8) = 0;
    *(u16*)(q + 0xA) = 3;
    *(u32*)(q + 0xC) = 0;
    *(u32*)(q + 0x10) = 0;
    *(u32*)(q + 0x14) = 0;
    *(u32*)(q + 0x18) = 0;
    *(u32*)(q + 0x1C) = 0;
    *(u32*)(q + 0x20) = 0;
    *(u32*)(q + 0x24) = 0;
    return self;
}
