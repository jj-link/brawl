#pragma force_active on
extern "C" char lbl_27_data_1C768[];
extern "C" void fn_27_CE0BC(void);
extern "C" void fn_27_25290(void);
typedef unsigned int u32;

struct BF {
    u32 a : 12;
    u32 b : 6;
    u32 c : 1;
    u32 d : 13;
};

extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void* self, void* iface, long a);

extern "C" void* fn_27_CEBE8(void* self, void* arg) {
    char* p = (char*)self;
    BF* bf = (BF*)(p + 8);
    *(char**)p = lbl_27_data_1C768;
    *(char**)(p + 4) = lbl_27_data_1C768 + 0x48;
    bf->a = 0;
    bf->b = (u32)arg;
    bf->c = 0;
    __construct_array(p + 0xC, (void (*)(void*))fn_27_CE0BC, (void (*)(void*))fn_27_25290, 0x30, 0x16);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(p + 4, arg, 0x16);
    return self;
}
