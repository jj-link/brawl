#pragma force_active on
typedef unsigned short u16;

extern "C" {
void* fn_80111BB8(char* a, char* b, unsigned long idx) {
    u16 n = *(u16*)(b + 0x4a);
    char* base = *(char**)(a + 0xc);
    char* p = base + (n << 3);
    return p + (idx << 3);
}
}
