#pragma force_active on
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>

struct FlagByte { unsigned char flag : 1; };
extern "C" void fn_8014E520(void* self, int flag);

extern "C" void fn_80032840(u8* self, void* arg) {
    *(void**)(self + 0xA0) = arg;
    if (self[0x98] != 0) {
        ((gfFileIOHandle*)(self + 0x8))->unmountVF(0);
        ((FlagByte*)(self + 0xF8))->flag = 1;
        *(u32*)(self + 0xF4) = 0x1D;
    } else {
        *(u32*)(self + 0xF0) = 0;
    }
    if (*(void**)(self + 0x8C) != 0) {
        gfHeapManager::free(*(void**)(self + 0x8C));
        *(void**)(self + 0x8C) = 0;
    }
    if (*(void**)(self + 0x90) != 0) {
        gfHeapManager::free(*(void**)(self + 0x90));
        *(void**)(self + 0x90) = 0;
    }
    if (*(void**)(self + 0x94) != 0) {
        gfHeapManager::free(*(void**)(self + 0x94));
        *(void**)(self + 0x94) = 0;
    }
    if (*(void**)(self + 0x9C) != 0) {
        fn_8014E520(*(void**)(self + 0x9C), 1);
        *(void**)(self + 0x9C) = 0;
    }
}
