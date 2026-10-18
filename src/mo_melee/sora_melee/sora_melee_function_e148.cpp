#include <types.h>
#pragma force_active on

class soModelModuleImpl {
public:
    bool isEnvMap();
};

struct EnvFlags {
    u8 f0 : 1;
};

bool soModelModuleImpl::isEnvMap()
{
    return ((EnvFlags*)((char*)this + 0xc5))->f0;
}
