#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_118_A3DC(void* self, u32 mask, u32 index) {
    u32* flags = *(u32**)((char*)self + 0x1c);
    flags[index] &= ~mask;
}
