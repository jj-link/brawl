#include <types.h>
#pragma force_active on

struct soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void postInitialize(soArrayVectorCalcInterface& iface, long a, long b);
};

extern char lbl_27_data_3BE98[0x90];

struct soArrayVectorFlags {
    u32 a : 4;
    u32 b : 2;
    u32 c : 1;
    u32 d : 25;
};

struct soArrayVectorHolder {
    void* m_vt0;
    void* m_vt1;
    soArrayVectorFlags m_flags;
};

extern "C" {
soArrayVectorHolder* fn_27_197E94(soArrayVectorHolder* self, u32 mode) {
    char* p = lbl_27_data_3BE98;
    self->m_vt0 = p;
    p += 0x48;
    self->m_vt1 = p;
    self->m_flags.a = 0;
    self->m_flags.b = mode;
    self->m_flags.c = 0;
    soArrayVectorCalculator* calc = (soArrayVectorCalculator*)((char*)self + 4);
    long unused;
    calc->postInitialize(*(soArrayVectorCalcInterface*)mode, 1, unused);
    return self;
}
}
