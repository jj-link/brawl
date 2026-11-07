#include <nt/nt_offline.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

extern "C" void fn_8014CA6C(u8* self, void* src, u32 size);

struct FriendSubObj {
    char pad0[0x8];
    gfFileIOHandle handle;
    char pad0C[0xA0 - 0xC];
    s32 unkA0;
    char padA4[0xF0 - 0xA4];
    s32 unkF0;
};

extern "C" s32 fn_800DACBC(ntFriendInfo* arg0) {
    char* self = (char*)arg0;
    u32 size;
    FriendSubObj* temp_r30 = *(FriendSubObj**)(self + 0x60);
    if (temp_r30->unkF0 == 0) {
        if (temp_r30->unkA0 == 0) {
            u8* inst = (u8*)ntFriendInfo::getInstance();
            size = temp_r30->handle.getSize();
            fn_8014CA6C(inst, temp_r30->handle.getBuffer(), size);
            gfHeapManager::free(temp_r30->handle.getBuffer());
            if (*(u8*)(self + 0x6C) != 0) {
                *(s32*)(self + 0x48) = 0;
                return 4;
            }
            return 5;
        }
        return 1;
    }
    return *(s32*)(self + 0x50);
}
