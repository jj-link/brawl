#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

struct Enemy : StageObject {
    char pad[0x1b4 - 0x64];
    soModuleEnumeration* modules;
};

extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned int, unsigned int);
extern "C" void fn_41_51C4(void*, void*);
extern "C" void fn_41_4D14(Vec3f*, const Vec3f&, const Vec3f&);
extern "C" void fn_41_4D38(Vec3f*, const Vec3f&);

extern "C" void fn_41_4C20(Enemy* self, const Vec3f& target) {
    soModuleEnumeration* modules = self->modules;
    soModelModule* model = modules->m_modelModule;
    soPostureModule* posture = modules->m_postureModule;

    int node = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
        (char*)self + 0xdc, 0x59e6, 0);

    fn_41_51C4(self, 0);
    self->updateNodeSRT();

    Vec3f global = model->getNodeGlobalPosition(node, false);
    Vec3f offset;
    fn_41_4D14(&offset, target, global);

    Vec3f position = posture->getPos();
    fn_41_4D38(&position, offset);
    posture->setPos(&position);

    self->updateNodeSRT();
}
