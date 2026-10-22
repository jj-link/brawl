#include <types.h>
#pragma force_active on

namespace nw4r {
namespace g3d {
class ScnMdl;
}
}

class gfModelAnimation {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12(int);
    virtual void f13();
    virtual int f14(u32);
    void unbind(nw4r::g3d::ScnMdl *arg);
};

extern u32 lbl_804068F8[];

void gfModelAnimation::unbind(nw4r::g3d::ScnMdl *arg) {
    u32 *var_r31 = lbl_804068F8;
    for (int i = 0; i < 6; i++) {
        int result = f14(*var_r31);
        if (result != 0) {
            f12(result);
        }
        var_r31++;
    }
}
