#pragma force_active on
typedef unsigned long u32;

extern "C" {
extern void* memcpy(void* dst, const void* src, u32 n);

void* fn_8006E7C8(char* self) {
    u32 n = *(u32*)(self + 0x8c);
    *(u32*)(self + 0x8) = n;
    return memcpy(self + 0xc, self + 0x90, n << 4);
}
}
