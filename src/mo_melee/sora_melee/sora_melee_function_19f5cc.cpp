#pragma force_active on
typedef unsigned int u32;

extern char lbl_27_data_37EE0[];
extern "C" void fn_27_CDA70(void* self, int flag);
extern "C" void fn_27_CDCC4(void* self);
extern "C" void __construct_array(void* p, void (*ctor)(void*), void (*dtor)(void*), unsigned long size, int count);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void* self, int arg, long count);

struct soArrayVectorFlags {
    u32 top : 8;
    u32 b : 4;
    u32 c : 1;
    u32 rest : 19;
};

struct soArrayVectorCalc {
    char* m_vt0;
    char* m_vt1;
    soArrayVectorFlags m_flags;
};

extern "C" soArrayVectorCalc* fn_27_19F5CC(soArrayVectorCalc* self, int arg) {
    self->m_vt0 = lbl_27_data_37EE0;
    self->m_vt1 = lbl_27_data_37EE0 + 0x48;
    self->m_flags.top = 0;
    self->m_flags.b = arg;
    self->m_flags.c = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_CDCC4, (void (*)(void*))fn_27_CDA70, 0x10, 6);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell((char*)self + 4, arg, 6);
    return self;
}
