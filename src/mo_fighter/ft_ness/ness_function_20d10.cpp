#include <so/so_module_accesser.h>
#pragma force_active on

class NessPhysics : public soNull, public soNullable {
public:
    virtual ~NessPhysics();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void update(const Vec3f*, const Vec3f*);
};

inline NessPhysics& getNessPhysics(const soModuleAccesser* accesser) {
    return *(NessPhysics*)accesser->m_enumerationStart->m_physicsModule;
}

extern "C" void fn_101_20D10(void*, soModuleAccesser* accesser) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    soLinkModule& link = accesser->getLinkModule();
    NessPhysics& physics = getNessPhysics(accesser);

    int node = work.getInt(0x20000000);
    Vec3f pos = link.getModelConstraintTargetNodePosition();
    Vec3f parentPos = link.getParentModelNodeGlobalPosition(5, (u32)node, false);
    physics.update(&pos, &parentPos);
}
