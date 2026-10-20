#include <types.h>
#pragma force_active on

class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void postInitialize(soArrayVectorCalcInterface& iface, s32 n, s32 m);
};

struct soBits {
    u32 x : 10;
    u32 a : 5;
    u32 b : 1;
    u32 c : 16;
};

extern "C" {
extern u8 lbl_27_data_399D8[];
void* fn_27_19A05C(void* self, u32 arg);
}

void* fn_27_19A05C(void* self, u32 arg) {
    u32* p = (u32*)self;
    soBits* bits = (soBits*)&p[2];
    p[0] = (u32)lbl_27_data_399D8;
    p[1] = (u32)(lbl_27_data_399D8 + 0x48);
    bits->x = 0;
    bits->a = arg;
    bits->b = 0;
    soArrayVectorCalculator* calc = (soArrayVectorCalculator*)&p[1];
    s32 m;
    calc->postInitialize(*(soArrayVectorCalcInterface*)arg, 8, m);
    return self;
}
