#pragma force_active on
typedef unsigned long u32;

extern "C" void* alloc__12gfMemoryPoolFPvUli(void* pool, u32 size, int align);
extern "C" void* fn_80025B78(void*, const char*, void*, unsigned long);

extern "C" void fn_800259C0(void* pool, u32 size) {
    void* p = alloc__12gfMemoryPoolFPvUli(pool, size, 0x20);
    if (p != 0) {
        p = fn_80025B78(p, 0, p, size);
    }
    if (p != 0) {
        unsigned char* b = (unsigned char*)p;
        b[0x11] = (unsigned char)(b[0x11] | 0x80);
    }
}
