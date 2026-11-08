#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_37BA8(void* p, int val);
extern "C" void fn_27_37C10(void* p, int val);

class soInner {
public:
    int m_unk0;
    unsigned char m_pad4[0x84];
    int m_unk88;
};

class soOwner {
public:
    virtual void v0();
    virtual soInner* get(int arg);
};

class soSelf {
public:
    unsigned char m_pad0[0x30];
    soOwner* m_unk30;
    unsigned char m_pad34[0x68 - 0x34];
    unsigned char m_unk68[4];
};

extern "C" void fn_27_39D80(soSelf* self, int arg) {
    if (self->m_unk30->get(arg)->m_unk0 != 0) {
        soInner* p = self->m_unk30->get(arg);
        p->m_unk0 = 0;
        int v = self->m_unk30->get(arg)->m_unk88;
        if (fn_27_37BA8(&self->m_unk68, v) == 1) {
            fn_27_37C10(&self->m_unk68, v);
        }
    }
}
