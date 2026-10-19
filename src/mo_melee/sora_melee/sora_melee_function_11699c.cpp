#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" void* fn_27_111D7C(void* p);
extern void** g_ftEntryManager;

extern "C" {
void* fn_27_11699C(char* self, int unused, u32 mode) {
    if (mode == 1) {
        s32 id = *(s32*)(self + 0x50);
        if (id != -1) {
            char* base = (char*)*g_ftEntryManager;
            return fn_27_111D7C(*(void**)(base + (u8)id * 0x244 + 0x28));
        }
    }
    return fn_27_111D7C(*(void**)(self + 0x28));
}
}
