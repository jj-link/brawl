#pragma force_active on
typedef unsigned long u32;
extern "C" void* memcpy(void* dst, const void* src, u32 n);

extern "C" {
void fn_8006E7B0(char* p) {
    u32 n = *(u32*)(p + 0x8);
    *(u32*)(p + 0x8C) = n;
    memcpy(p + 0x90, p + 0xC, n << 4);
}
}
