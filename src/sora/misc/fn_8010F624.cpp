#include <types.h>
#include <gf/gf_file_io_handle.h>
#include <nw4r/g3d/g3d_resfile.h>
#pragma force_active on

extern "C" int fn_8010F624(void* obj) {
    char* self = (char*)obj;
    void* res2;
    void* res;
    void* buffer;
    if ((((u32)*(u8*)self >> 7) & 1) == 1) {
        return 1;
    }
    gfFileIOHandle* h = (gfFileIOHandle*)(self + 0x14);
    int i = 0;
    do {
        if (!h->isReady()) {
            return 0;
        }
        i++;
        h = (gfFileIOHandle*)((char*)h + 4);
    } while (i < 2);
    res = 0;
    if (((gfFileIOHandle*)(self + 0x14))->getReturnStatus() == 0x15)
        buffer = 0;
    else {
        buffer = ((gfFileIOHandle*)(self + 0x14))->getBuffer();
        ((gfFileIOHandle*)(self + 0x14))->release();
    }
    if (buffer) {
        res = buffer;
        nw4r::g3d::ResFile::Init(&res);
    }
    *(void**)(self + 8) = res;
    res2 = 0;
    if (((gfFileIOHandle*)(self + 0x18))->getReturnStatus() == 0x15)
        buffer = 0;
    else {
        buffer = ((gfFileIOHandle*)(self + 0x18))->getBuffer();
        ((gfFileIOHandle*)(self + 0x18))->release();
    }
    if (buffer) {
        res2 = buffer;
        nw4r::g3d::ResFile::Init(&res2);
    }
    *(void**)(self + 0xc) = res2;
    *(u8*)self |= 0x80;
    return 1;
}
