#include <types.h>
#include <it/it_manager.h>
#include <so/model/so_model_module_impl.h>
#include <mt/mt_vector.h>

#pragma force_active on

extern "C" {
void fn_41_534C(Vec3f* out, const Vec3f* in);
void wnemReport__FPCce(const char* fmt, ...);
extern const char lbl_41_data_4768[];
extern const char lbl_41_data_479D[];
}

extern "C" int fn_41_320F8(char* self, itKind kind, u32 variation, char* position) {
    if (kind == -1) {
        return 0;
    }

    if (!itManager::getInstance()->isCompItemKindArchive(kind, 0, true)) {
        itManager::getInstance()->preloadItemKindArchive(kind, 0, (itArchive::Type)0, true);
        return 1;
    }

    char* itemManager = *(char**)(self + 0x6c);
    char* owner = *(char**)(itemManager + 8);
    int ownerTask = *(int*)(owner + 0x28);
    itManager* mgr = itManager::getInstance();

    BaseItem* item = mgr->createItem(kind, variation, ownerTask, NULL, 0, 0xffff, 0, 0xffff);
    if (item != NULL) {
        soModelModule* resource = *(soModelModule**)(*(char**)(*(char**)(self + 0x6c) + 0xd8) + 4);
        Vec3f warped;
        Vec3f offset;
        offset.m_x = *(float*)(position + 0x1c);
        offset.m_y = *(float*)(position + 0x20);
        offset.m_z = *(float*)(position + 0x24);
        Vec3f pos = resource->getNodeGlobalPosition(*(u32*)(position + 0x18), &offset, false, false);
        fn_41_534C(&warped, &pos);
        item->warp(&warped);
        item->updateNodeSRT();
    } else {
        wnemReport__FPCce(lbl_41_data_4768);
        return 0;
    }

    wnemReport__FPCce(lbl_41_data_479D);
    return 1;
}
