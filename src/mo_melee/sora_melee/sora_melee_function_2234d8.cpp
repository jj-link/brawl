#include <types.h>
#pragma force_active on

struct StageItemPosInfo {
    u8 pad[0x54];
    u8 m_count;
};

class Stage {
public:
    u8 getItemPosCount();

private:
    u8 pad[0x90];
    StageItemPosInfo* m_itemPosInfo;
};

u8 Stage::getItemPosCount() {
    if (m_itemPosInfo == nullptr) {
        return 0;
    }
    return m_itemPosInfo->m_count;
}
