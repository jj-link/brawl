#include <types.h>
#pragma force_active on

class soFlagObj {
public:
    char pad[0x24];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 flag : 1;
};

class soIfaceA {
public:
    virtual void vf0();
    virtual soFlagObj* vf1();
};

class soIfaceB {
public:
    virtual void vf0();
    virtual void* vf1(void* arg);
};

class soOwner {
public:
    char pad[0x90];
    soIfaceA* m_iface;
};

extern "C" int fn_27_20440(void* p);

extern "C" int fn_27_17E00(soOwner* self, void* arg) {
    soFlagObj* obj = self->m_iface->vf1();
    if (!obj->flag) {
        void* r = ((soIfaceB*)self->m_iface)->vf1(arg);
        return fn_27_20440(r);
    }
    return 0;
}
