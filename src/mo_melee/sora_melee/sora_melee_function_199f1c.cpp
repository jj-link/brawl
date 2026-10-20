#include <types.h>
#pragma force_active on

struct soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    static void postInitialize(soArrayVectorCalcInterface& iface, s32 a, s32 b);
};

extern "C" {
extern u8 lbl_27_data_3CC78[];

struct FnObj27 {
    void* m_vtbl;   // 0x0
    void* m_iface;  // 0x4 (soArrayVectorCalcInterface begins here)
    u32 m_flags;    // 0x8
};

struct FnFlagBits {
    u32 a : 8;
    u32 b : 4;
    u32 c : 1;
    u32 d : 19;
};

FnObj27* fn_27_199F1C(FnObj27* self, s32 p2) {
    u8* base = lbl_27_data_3CC78;
    FnFlagBits* fb = reinterpret_cast<FnFlagBits*>(&self->m_flags);
    self->m_vtbl = base;
    self->m_iface = base + 0x48;
    fb->a = 0;
    fb->b = p2;
    fb->c = 0;
    soArrayVectorCalculator::postInitialize(*reinterpret_cast<soArrayVectorCalcInterface*>(&self->m_iface), p2, 7);
    return self;
}
}
