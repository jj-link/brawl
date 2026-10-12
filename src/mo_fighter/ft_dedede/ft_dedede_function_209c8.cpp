#include <so/so_module_accesser.h>

namespace {
// The team module remains an opaque member of soModuleEnumeration.
class DededeTeamModule {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual void reserved10();
    virtual void setTeam(int, bool);
    virtual void reserved18();
    virtual void reserved1C();
    virtual void setLrTeam(int);
    virtual void setOwnerTeam(int);
};
struct DededeAttachmentNode {
    unsigned char prefix[4];
    int node;
};
struct DededeAttachmentObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char middle[0x58];
    DededeAttachmentNode* attachment;
};
inline DededeTeamModule* teamModule(DededeAttachmentObject* object) {
    return static_cast<DededeTeamModule*>(object->accesser->m_enumerationStart->m_teamModule);
}
}

extern "C" void fn_117_209C8(DededeAttachmentObject* object, int owner, int targetNode, int team) {
    soModuleAccesser* accesser = object->accesser;
    if (accesser->getLinkModule().link(3, owner)) {
        object->accesser->getLinkModule().setModelConstraintPosOrt(
            3, object->attachment->node, targetNode, 3, true);
        accesser->getWorkManageModule().setInt(owner, 0x20000007);
        teamModule(object)->setTeam(team, true);
        teamModule(object)->setLrTeam(-1);
        teamModule(object)->setOwnerTeam(owner);
        accesser->getStatusModule().changeStatusForce(1, accesser);
    }
}
