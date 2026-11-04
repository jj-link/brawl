#include <so/so_value_accesser.h>
#include <so/link/so_link_module_impl.h>
#pragma force_active on

struct Other { char pad[0x98]; unsigned int id; };
extern "C" int fn_27_63438(void*, float);

extern "C" bool fn_27_186DB4(void*, soModuleAccesser* a, Other* b) {
    if (!a->m_enumerationStart->m_linkModule->isLink(0))
        return false;
    if (b->id == (unsigned int)a->m_enumerationStart->m_linkModule->getParentTaskId(0))
        return false;
    float f = a->m_enumerationStart->m_linkModule->getParentDamageReaction(0);
    return fn_27_63438(a, f * soValueAccesser::getConstantFloat(a, 2002, 0)) < 3;
}