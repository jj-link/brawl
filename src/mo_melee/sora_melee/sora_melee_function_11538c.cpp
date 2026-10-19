#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
extern char* g_GameGlobal;
}

extern "C" void* fn_27_11538C(char* p) {
    s32 idx = *(s32*)(p + 0x58);
    char* g = g_GameGlobal;
    char* a = *(char**)(g + 0x8) + idx * 0x5c;
    s32 sub = *(u8*)(a + 0x9b);
    char* b = *(char**)(g + 0x18);
    return *(void**)(b + sub * 0x2ac + 0x27c);
}
