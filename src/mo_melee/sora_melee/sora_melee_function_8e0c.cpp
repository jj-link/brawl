#include <types.h>
#pragma force_active on

namespace nw4r {
namespace g3d {
class ScnMdl;
}
} // namespace nw4r

class soModelModuleImpl {
public:
    void setScnMdlExtern(nw4r::g3d::ScnMdl* mdl);

    char _spacer1[0xC];
    nw4r::g3d::ScnMdl* m_scnMdl; // +0xC
    char _spacer2[0xB3];
    u8 m_scnMdlExternFlag; // +0xC3
};

void soModelModuleImpl::setScnMdlExtern(nw4r::g3d::ScnMdl* mdl) {
    m_scnMdl = mdl;
    m_scnMdlExternFlag = 3;
}
