#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

extern "C" void fn_800FABEC(void* self) {
    unsigned char* p = (unsigned char*)self;
    if (p[0x14]) {
        if (((gfFileIOHandle*)(p + 0x10))->isReady()) {
            gfHeapManager::free(((gfFileIOHandle*)(p + 0x10))->getBuffer());
        } else {
            ((gfFileIOHandle*)(p + 0x10))->cancelRequest();
        }
        ((gfFileIOHandle*)(p + 0x10))->release();
        p[0x14] = 0;
    }
}