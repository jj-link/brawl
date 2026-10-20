#include <types.h>
#pragma force_active on

extern "C" {
extern u8* g_ftManager;
int getEntryId__9ftManagerFi(void* self, int id);
void fn_27_10C280(void* self, u32 id, u32 arg);

int fn_1_7F20(u8* self, u32 arg) {
    *(u32*)(*(u8**)(self + 0x104) + 0xc) = arg;
    u8 flags = self[0xd8];
    if (!((flags >> 6) & 1) || ((flags >> 4) & 1)) {
        return 0;
    }
    void* ft = g_ftManager;
    int entry = getEntryId__9ftManagerFi(ft, 0);
    fn_27_10C280(ft, entry, arg);
    return 1;
}
}
