#include <types.h>
#include <gf/gf_file_io_handle.h>
#include <gm/gm_global.h>
#include <nw4r/g3d/g3d_resfile.h>
#pragma force_active on

extern char lbl_8045D840[];

extern "C" void fn_8010F4AC(void* obj, int async) {
        void* res2;
    char* self = (char*)obj;
    const char* data = "/info/info_stgedit.brres";
    if (async)
        ((gfFileIOHandle*)(self + 0x14))->readRequest(data, (HeapType)9, 0, 0);
    else
        ((gfFileIOHandle*)(self + 0x14))->read(data, (HeapType)9, 0);
    u8 flag = *(u8*)((char*)g_GameGlobal->getGlobalRecordMenuDatap() + 0x28);
    const char* path = ((flag >> 7) & 1) ? "/info/defaultcamera/InfoWide.brres" : "/info/defaultcamera/Info.brres";
    if (async)
        ((gfFileIOHandle*)(self + 0x18))->readRequest(path, (HeapType)9, 0, 0);
    else
        ((gfFileIOHandle*)(self + 0x18))->read(path, (HeapType)9, 0);
    if (!async) {
        void* res = 0;
        void* buffer;
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
    }
}