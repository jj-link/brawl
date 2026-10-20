#include <types.h>
#pragma force_active on

struct soIfaceBase {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
};

struct soPadBase {
    u32 pad[4];
};

struct soOwner : public soPadBase, public soIfaceBase {
    void v0() {}
    void v1() {}
    void v2() {}
    void v3() {}
    void v4() {}
    void v5() {}
    void v6() {}
    void v7() {}
    void v8() {}
    void v9() {}
    void v10() {}
    void v11() {}
    void v12() {}
    void v13() {}
    void v14() {}
    void v15() {}
};

extern "C" void fn_27_F79C4(soOwner& p) {
    static_cast<soIfaceBase&>(p).v13();
}
