#include <cm/cm_camera_controller.h>
#include <gm/gm_global.h>
#include <gf/gf_file_io_handle.h>
#pragma force_active on
extern "C" {
extern char lbl_1_data_3C58[];
void* fn_800AFB94(const char*, int, const char*);
void fn_1_B5A4(u8* self) {
    char* base = lbl_1_data_3C58;
    *(void**)(self + 0x35c) = fn_800AFB94(base + 0x40, 0x64, 0);
    CameraController::getInstance()->changeInput(CameraController::MenuFixed);
    *(u32*)(self + 0x380) = 0;
    u8* rec = (u8*)g_GameGlobal->getGlobalRecordMenuDatap();
    gfFileIOHandle* handle = (gfFileIOHandle*)(self + 0x3a4);
    char* name = base + 0x8c;
    if ((rec[0x28] >> 7) & 1) name = base + 0x5c;
    handle->readRequest(name, (HeapType)0x2b, 0, 0);
    ((gfFileIOHandle*)(self + 0x384))->readRequest(base + 0xb8, (HeapType)0x2b, 0, 0);
    ((gfFileIOHandle*)(self + 0x388))->readRequest(base + 0xdc, (HeapType)0x2b, 0, 0);
    ((gfFileIOHandle*)(self + 0x38c))->readRequest(base + 0x108, (HeapType)0x2b, 0, 0);
    ((gfFileIOHandle*)(self + 0x390))->readRequest(base + 0x120, (HeapType)0x2b, 0, 0);
    ((gfFileIOHandle*)(self + 0x394))->readRequest(base + 0x140, (HeapType)0x2b, 0, 0);
    ((gfFileIOHandle*)(self + 0x398))->readRequest(base + 0x164, (HeapType)0x2b, 0, 0);
    ((gfFileIOHandle*)(self + 0x39c))->readRequest(base + 0x180, (HeapType)0x2b, 0, 0);
    ((gfFileIOHandle*)(self + 0x3a0))->readRequest(base + 0x198, (HeapType)0x2b, 0, 0);
}
}