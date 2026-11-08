#include <cstring>
#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_48_data_138[];
extern char lbl_48_data_144[];
u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(const void* mdl);
void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(const void* mdl, u32 index);
}

extern "C" s32 fn_48_1838(void* unused, const void* mdl, u32 key) {
    s32 count = 0;
    u32 n = GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(mdl);
    for (u32 i = 0; i < n; i++) {
        char* node = (char*)GetResNode__Q34nw4r3g3d6ResMdlCFUl(mdl, i);
        u32 off = *(u32*)(node + 0x5C);
        char* entry = off != 0 ? node + off : 0;
        if (entry != 0) {
            u32 k = entry != 0 ? *(u32*)(entry + 0xC) : 0;
            if (key == k) {
                u32 noff = *(u32*)(node + 0x8);
                char* name = noff != 0 ? node + noff : 0;
                if (strstr(name, lbl_48_data_138) != 0 || strstr(name, lbl_48_data_144) != 0) {
                    count++;
                }
            }
        }
    }
    return count;
}
