#pragma force_active on
#include <it/item.h>

extern "C" int fn_27_28CCF0(BaseItem*, int);
extern "C" void fn_27_28F6D4(BaseItem*, int, int, float, float);

extern const float lbl_27_rodata_46C8;
extern const float lbl_27_rodata_46D8;

extern "C" void fn_27_29CD7C(void*, BaseItem* item, int kind, float rate)
{
    switch (kind) {
    case 0:
        item->changeMotion(7, false);
        item->m_moduleAccesser->m_enumerationStart->m_motionModule->setRate(rate);
        break;
    case 1:
        item->changeMotion(8, false);
        item->m_moduleAccesser->m_enumerationStart->m_motionModule->setRate(rate);
        break;
    case 2:
        item->changeMotion(9, false);
        item->m_moduleAccesser->m_enumerationStart->m_motionModule->setRate(rate);
        break;
    case 3:
        item->changeMotion(10, false);
        break;
    case 4: {
        float value = item->getParamFloat(0x15AE);
        fn_27_28F6D4(item, 3, fn_27_28CCF0(item, 0x63CE),
                     lbl_27_rodata_46C8, value);
        break;
    }
    case 5:
        fn_27_28F6D4(item, 3, 1,
                     lbl_27_rodata_46C8, lbl_27_rodata_46D8);
        break;
    }
}
