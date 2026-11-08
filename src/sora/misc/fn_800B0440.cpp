#include <gf/gf_file_io_handle.h>
#pragma force_active on
extern "C" void fn_800B00B0(void*, gfFileIOHandle*);
extern "C" void fn_800B0440(void* self) {
    unsigned char* p = (unsigned char*)self;
    if (p[0x1A4] == 0 && ((gfFileIOHandle*)(p + 0x1A8))->m_request != 0 && ((gfFileIOHandle*)(p + 0x1A8))->isReady()) {
        fn_800B00B0(self, (gfFileIOHandle*)(p + 0x1A8));
        p[0x1A4] = 1;
    }
}