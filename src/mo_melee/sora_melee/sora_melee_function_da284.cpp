#include <types.h>
#pragma force_active on

struct soVirtIface {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8(s16 value) = 0;
};

struct soVirtHolder {
    u32 unk0;
    u32 unk4;
    soVirtIface* m_iface;
};

extern "C" {
void fn_27_DA284(soVirtHolder* holder, s16 value) {
    holder->m_iface->v8(value);
}
}
