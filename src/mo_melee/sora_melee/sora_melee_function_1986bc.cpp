#pragma force_active on
struct soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void postInitialize(soArrayVectorCalcInterface& iface, long a, long b);
};

struct fn27Flags {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 1;
    unsigned int d : 25;
};

extern "C" {
extern char lbl_27_data_3BF88[];
void fn_27_9FB70(void*);
void fn_27_9FB88(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

extern "C" void* fn_27_1986BC(void* self, soArrayVectorCalcInterface* iface) {
    char* p = (char*)self;
    fn27Flags* fl = (fn27Flags*)(p + 8);
    long b;
    *(char**)p = lbl_27_data_3BF88;
    *(char**)(p + 4) = lbl_27_data_3BF88 + 0x48;
    fl->a = 0;
    fl->b = (unsigned int)iface;
    fl->c = 0;
    __construct_array(p + 0xc, (void (*)(void*))fn_27_9FB70, (void (*)(void*))fn_27_9FB88, 0xc, 1);
    ((soArrayVectorCalculator*)(p + 4))->postInitialize(*iface, 1, b);
    return self;
}
