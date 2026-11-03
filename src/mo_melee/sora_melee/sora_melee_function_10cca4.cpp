#include <types.h>
#include <ft/ft_entry_manager.h>
#include <gf/gf_camera.h>
#pragma force_active on

extern "C" s32 fn_27_1190D0(void*);
extern "C" Vec3f fn_27_8CA78(void*);

extern "C" float fn_27_10CCA4(void* self, u32 entryId, s32 index) {
    void* obj;
    if (fn_27_1190D0(*(void**)((u8*)self + 0x154)) == 0) {
        obj = 0;
    } else if (index != -1) {
        u8* entry = (u8*)(*(ftEntryManager**)((u8*)self + 0x154))->getEntity(entryId);
        obj = *(void**)(entry + (index << 3) + 0x34);
    } else {
        u8* entry = (u8*)(*(ftEntryManager**)((u8*)self + 0x154))->getEntity(entryId);
        u32 n = entry[0xA];
        obj = *(void**)(entry + (n << 3) + 0x34);
    }
    Vec3f pos = fn_27_8CA78(obj);
    return pos.m_x - gfCameraManager::getManager()->m_cameras[0].m_targetPos.m_x;
}
