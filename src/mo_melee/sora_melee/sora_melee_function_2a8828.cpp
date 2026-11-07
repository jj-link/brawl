#include <it/it_manager.h>
#pragma force_active on

BaseItem* itManager::getItemFromInstanceId(int instanceId) {
    for (int i = 0; i < static_cast<soArrayFixed<BaseItem*>&>(m_itemArrayList).size(); i++) {
        BaseItem* item = static_cast<soArrayFixed<BaseItem*>&>(m_itemArrayList).at(i);
        if (item != 0 && (u32)instanceId == (u32)item->m_instanceId) {
            return item;
        }
    }
    return 0;
}