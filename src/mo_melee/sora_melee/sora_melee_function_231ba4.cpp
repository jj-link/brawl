#include <types.h>
#pragma force_active on

class Ground {
    char pad[0x6C];
    bool m_isVisible : 1;
    bool m_isVisibleByClipping : 1;
    bool m_isEnableCollisionStatus : 1;
    bool m_isEnableCollisionStatusByClipping : 1;
    bool m_isEnableCalcCollision : 1;
public:
    bool isEnableCalcCollision();
};

bool Ground::isEnableCalcCollision() {
    return m_isEnableCalcCollision;
}
