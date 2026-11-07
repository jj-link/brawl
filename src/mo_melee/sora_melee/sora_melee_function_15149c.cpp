#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/effect/so_effect_module_impl.h>
#pragma force_active on

extern const float lbl_27_rodata_1E58;

struct FtObj {
    char pad[0x30];
    unsigned int state;
};

extern "C" void fn_27_15149C(void* self, soModuleAccesser* a, FtObj* obj, float f1, float f2) {
    if (f1 > lbl_27_rodata_1E58) {
        if (f2 >= soValueAccesser::getConstantFloat(a, 0xCD3, 0)) {
            switch (obj->state & 0x1F) {
            case 5:
                a->m_enumerationStart->m_effectModule->reqScreen(2);
                return;
            case 3:
                a->m_enumerationStart->m_effectModule->reqScreen(3);
                return;
            case 19:
                a->m_enumerationStart->m_effectModule->reqScreen(5);
                return;
            case 21:
                a->m_enumerationStart->m_effectModule->reqScreen(6);
                return;
            default:
                a->m_enumerationStart->m_effectModule->reqScreen(1);
                break;
            }
        }
    }
}
