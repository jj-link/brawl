#include <types.h>
#pragma force_active on

struct Ret { u32 a, b, c; };

class soSubObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual Ret v14(u32 a);
};

class soOwner {
public:
    u8 m_pad[0xdb4];
    soSubObj m_sub;
};

extern "C" Ret fn_27_290070(soOwner* o) {
    return o->m_sub.v14(0);
}
