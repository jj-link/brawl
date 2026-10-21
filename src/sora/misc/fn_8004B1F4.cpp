#pragma force_active on
typedef unsigned short u16;
extern "C" void* memcpy(void*, const void*, unsigned long);

extern "C" int fn_8004B1F4(char* self, const void* src, unsigned int size) {
    char* p = *(char**)(self + 0x24);
    int off = *(u16*)(p + 0x33A) + 0x388;
    *(u16*)(p + 0x33C) = off;
    *(u16*)(p + 0x33E) = size;
    memcpy(*(char**)(self + 0x24) + (u16)off, src, (u16)size);
    return 1;
}
