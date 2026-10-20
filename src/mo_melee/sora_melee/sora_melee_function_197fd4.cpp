#pragma force_active on
class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void postInitialize(soArrayVectorCalcInterface& iface, long a, long b);
};

extern "C" char lbl_27_data_3BB10[];

struct fn_27_197FD4_bits {
    unsigned int a : 6;
    unsigned int b : 3;
    unsigned int c : 1;
    unsigned int d : 22;
};

struct fn_27_197FD4_obj {
    void* m0;
    void* m4;
    unsigned int m8;
};

extern "C" {
soArrayVectorCalculator* fn_27_197FD4(fn_27_197FD4_obj* self, unsigned int flags, long x, long y) {
    self->m0 = lbl_27_data_3BB10;
    self->m4 = lbl_27_data_3BB10 + 0x48;
    fn_27_197FD4_bits* bits = reinterpret_cast<fn_27_197FD4_bits*>(&self->m8);
    bits->a = 0;
    bits->b = flags;
    bits->c = 0;
    soArrayVectorCalculator* calc = reinterpret_cast<soArrayVectorCalculator*>(&self->m4);
    calc->postInitialize(*reinterpret_cast<soArrayVectorCalcInterface*>(flags), 3, y);
    return reinterpret_cast<soArrayVectorCalculator*>(self);
}
}
