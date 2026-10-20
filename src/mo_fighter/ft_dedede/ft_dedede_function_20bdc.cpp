#include <mo_fighter/ft_dedede/ft_dedede_reflect.h>
#pragma force_active on

namespace {
class DededeFollowerView : public DededeReflectFighter {
public:
    virtual void reserved234();
    virtual void reserved238();
    virtual void onStatusOne();
};
}

extern "C" void fn_117_20BDC(DededeFollowerView* follower) {
    switch (follower->m_moduleAccesser->getStatusModule().getStatusKind()) {
    case 1:
        follower->onStatusOne();
        break;
    }
}
