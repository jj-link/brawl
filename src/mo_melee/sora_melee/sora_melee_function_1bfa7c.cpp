#include <types.h>
#pragma force_active on

struct soPrefixWork {
    u32 m_pad[4];
};

class soVirtualSub {
public:
    virtual void f0() = 0;
    virtual u32* f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
};

struct soOuterWork : soPrefixWork, soVirtualSub {};

extern "C" u32 fn_27_1BFA7C(soOuterWork& p) {
    soVirtualSub& sub = p;
    return sub.f1()[1];
}
