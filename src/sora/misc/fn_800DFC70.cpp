#include <types.h>
#pragma force_active on

extern "C" int lbl_805A02DC;
extern "C" void* lbl_805A02E0;

class fnDFC70Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(int a, int b);
    char m_pad[0xE0];
    int m_E4;
};

extern "C" void fn_800DFC70(fnDFC70Base* self) {
    self->v11(self->m_E4, lbl_805A02DC);
    lbl_805A02E0 = self;
}
