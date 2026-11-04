#include <gf/gf_file_io_handle.h>
#include <gf/gf_archive.h>
#include <ty/ty_fig_listmng.h>
#include <gm/gm_global.h>
#include <sr/sr_common.h>
#include <stdio.h>
#pragma force_active on

extern char lbl_26_data_0[];
extern "C" void fn_800151FC(void*, const char*, int, int, int, int);

extern "C" void fn_26_A0C(u8* self) {
    char buf[24];
    char* base = lbl_26_data_0;
    ((gfFileIOHandle*)(self + 0x9fc))->readRequest(base + 0x28, (Heaps::HeapType)0x2b, 0, 0);
    sprintf(buf, base + 0x10, (*(tyFigListDataManager**)(self + 0x1f0))->getFigDataId(*(u32*)(self + 0x48))->name);
    ((gfFileIOHandle*)(self + 0x103c))->readRequest(buf, (Heaps::HeapType)0x2b, 0, 0);
    ((gfFileIOHandle*)(self + 0xd1c))->readRequest(base + 0x48, (Heaps::HeapType)0x2b, 0, 0);
    if (!((((u8*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >> 7) & 1)) {
        ((gfFileIOHandle*)(self + 0x11cc))->readRequest(base + 0x60, (Heaps::HeapType)0x2b, 0, 0);
    } else {
        ((gfFileIOHandle*)(self + 0x11cc))->readRequest(base + 0x88, (Heaps::HeapType)0x2b, 0, 0);
    }
    gfArchive* archive = new ((Heaps::HeapType)0x2a) gfArchive;
    *(gfArchive**)(self + 0x135c) = archive;
    fn_800151FC(archive, base + 0xb8, 0x2b, 0, 0, 0xff);
    *(int*)(self + 0x1368) = 2;
}