#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_96_F540(void* self, u32 index) {
    u32* table = *(u32**)((char*)self + 0xc);
    table[index]++;
}
