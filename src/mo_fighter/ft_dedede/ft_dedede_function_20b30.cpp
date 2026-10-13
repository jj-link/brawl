#include <mo_fighter/ft_dedede/ft_dedede_reflect.h>

namespace {
// Extend the existing partial follower interface to the observed query slot.
class DededeFollowerQuery : public DededeReflectFighter {
public:
    virtual void reserved234();
    virtual void reserved238();
    virtual void reserved23C();
    virtual void reserved240();
    virtual void reserved244();
    virtual void reserved248();
    virtual int isUnavailable();
};
}

extern "C" bool fn_117_20B30(void* object) {
    DededeFollowerQuery* follower = static_cast<DededeFollowerQuery*>(object);
    switch (follower->m_moduleAccesser->getStatusModule().getStatusKind()) {
    case 0: case 1: case 7: case 8: case 9:
        return false;
    default:
        return !follower->isUnavailable();
    }
}
