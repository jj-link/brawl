#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_27_30130(void* p) {
    *(u8*)(*(u8**)((u8*)p + 0x4) + 0x6d) &= 0xFFFFFF00;
    *(u32*)(*(u8**)((u8*)p + 0x4) + 0x6c) &= 0x00FFFFFF;
}
