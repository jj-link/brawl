#pragma force_active on
typedef unsigned int u32;

extern "C" char lbl_27_data_383B8[];
extern "C" void fn_27_CDA70(void* self, int flag);
extern "C" void* fn_27_CDCC4(void* self);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void* self, void* iface, long a);

struct Hdr {
    void* vt0;
    void* vt1;
    u32 a : 4;
    u32 b : 2;
    u32 c : 1;
    u32 rest : 25;
};

extern "C" void* fn_27_19EAA4(void* self, int flag) {
    Hdr* h = (Hdr*)self;
    h->vt0 = lbl_27_data_383B8;
    h->vt1 = lbl_27_data_383B8 + 0x48;
    h->a = 0;
    h->b = flag;
    h->c = 0;

    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_CDCC4, (void (*)(void*))fn_27_CDA70, 0x10, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell((char*)self + 0x4, (void*)(long)flag, 1);
    return self;
}
