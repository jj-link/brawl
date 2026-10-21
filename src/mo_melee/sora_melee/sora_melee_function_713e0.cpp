#include <types.h>
#pragma force_active on

extern "C" void fn_27_7021C(void* self, int arg, float f);
extern "C" void fn_27_714A4(short* out, int* src);

struct Iface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual int* v21(int index);
};

struct Owner {
    u8 pad[0x20];
    Iface* m_iface;
};

extern "C" void fn_27_713E0(Owner* self, int arg1, short* arg2, float farg0) {
    short sp8;
    if (*arg2 != 0) {
        int count = self->m_iface->v4();
        for (int i = 0; i < count; i++) {
            int* p = self->m_iface->v21(i);
            fn_27_714A4(&sp8, p);
            if (sp8 & *arg2) {
                fn_27_7021C((void*)*p, arg1, farg0);
            }
        }
    }
}
