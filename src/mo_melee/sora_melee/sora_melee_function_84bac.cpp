#include <types.h>
#pragma force_active on

class soGuessBase {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void call(u32 a, u32 b, u16* out, s32 n);
};

extern "C" {
void fn_27_84BAC(soGuessBase* p, u32 a, u32 b) {
    u16 tmp = 0;
    p->call(a, b, &tmp, -1);
}
}
