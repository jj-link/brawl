#include <types.h>
#pragma force_active on

extern "C" void fn_27_20084(void* p, float f);

class soAnimChr {
public:
    void setFrame(float frame);
};

class PadBase {
public:
    u32 m_pad0;
    u32 m_pad1;
};

class IVirt : public PadBase {
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
};

extern "C" {
void fn_27_14A68(u8* self, float f) {
    reinterpret_cast<soAnimChr*>(self + 0x3c)->setFrame(f);
    if (*(u32*)(self + 0x3c) != 0) {
        u8* p = *(u8**)(self + 0x168);
        p = *(u8**)(p + 0xd8);
        p = *(u8**)(p + 0x4);
        reinterpret_cast<IVirt*>(p)->v7();
    }
    fn_27_20084(self + 0xc8, f);
}
}
