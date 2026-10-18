#pragma force_active on
typedef unsigned int u32;

extern "C" {
void fn_125_B328(void* self, u32 index) {
    u32* counts = *(u32**)((char*)self + 0xc);
    counts[index]++;
}
}
