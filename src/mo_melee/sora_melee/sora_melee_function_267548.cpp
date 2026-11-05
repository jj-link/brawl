#include <gr/gr_yakumono.h>

#pragma force_active on

extern "C" void fn_27_2636F0(void*, int, int, soCollisionAttackData*);

void grYakumono::setAttackGimmick(int index, int groupIndex, u32 nodeIndex,
                                  AttackData* grAttackData, AttackDetails* grAttackDetails) {
    soCollisionAttackData attackData;

    grAttackData->m_nodeIndex = nodeIndex;
    setSoCollisionAttackData(&attackData, grAttackData, grAttackDetails);
    fn_27_2636F0(m_yakumono, index, groupIndex, &attackData);
}
