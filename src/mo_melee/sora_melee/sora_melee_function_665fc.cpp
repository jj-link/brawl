#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct Holder {
    char pad[0xd8];
    soModuleEnumeration* modules;
};
struct Self {
    char pad[0x10];
    Holder* holder;
    unsigned int parentNode;
    unsigned int node;
};
extern "C" Vec2f fn_27_665FC(Self* self, bool flag) {
    Vec3f a = self->holder->modules->m_linkModule->getParentModelNodeGlobalPosition(0, self->parentNode, flag);
    Vec3f b = self->holder->modules->m_modelModule->getNodeGlobalPosition(self->node, flag);
    Vec2f result;
    result.m_x = a.m_x - b.m_x;
    result.m_y = a.m_y - b.m_y;
    return result;
}