#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void fn_113_CC74(void* self, u32 value, u32 index) {
    u32* works = *(u32**)((u8*)self + 0x1c);
    works[index] |= value;
}
