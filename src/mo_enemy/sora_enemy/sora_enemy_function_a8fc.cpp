#include <it/it_manager.h>
#include <so/so_value_accesser.h>
#pragma force_active on
struct Self { char pad[0xdc]; char accesser[8]; char* object; char pad2[0x1b4 - 0xe8]; soModuleEnumeration* modules; };
extern "C" void fn_27_28F8FC(BaseItem*, float);
extern "C" itManager* getInstance__9itManagerFv(char*);
extern float lbl_41_rodata_14;
extern "C" int fn_41_A8FC(Self* self, unsigned long variation) {
    if (!itManager::getInstance()->isCompItemKindArchive((itKind)0x17, 0, true)) {
        itManager::getInstance()->preloadItemKindArchive((itKind)0x17, 0, (itArchive::Type)0, true);
        return 1;
    }
    soModelModule* model = self->modules->m_modelModule;
    Vec3f pos = model->getNodeGlobalPosition(soValueAccesser::getValueInt((soModuleAccesser*)self->accesser, 0x59e6, 0), false);
    char* object = self->object;
    int id = *(int*)(object + 0x28);
    itManager* manager = getInstance__9itManagerFv(object);
    BaseItem* item = manager->createItem(&pos, lbl_41_rodata_14, (itKind)0x17, variation, id, 0, 0, 0xffff, 0, 0xffff);
    if (!item) return 0;
    fn_27_28F8FC(item, soValueAccesser::getValueFloat((soModuleAccesser*)self->accesser, 0xbf3, 0));
    item->updateNodeSRT();
    return 1;
}