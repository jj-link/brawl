#include <types.h>
#pragma force_active on

class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    static void postInitialize(soArrayVectorCalcInterface& iface, long n, long m);
    static int resize(soArrayVectorCalcInterface& iface, long n, bool a, bool b, long c, long d, long e);
};

class SoSubObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(void* p);
    virtual void v11();
    virtual void v12();
    virtual long v13();
    virtual bool v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual long v27();
    virtual long v28();
};

extern "C" {
extern char lbl_27_data_1E938[];
extern char lbl_27_data_1B58[];
extern char lbl_27_data_46770[];
extern char lbl_27_data_12F08;
extern char lbl_27_data_12F98;
extern char lbl_27_bss_5260[];
extern char lbl_27_bss_5254[];
extern signed char lbl_27_bss_526C;
extern signed char lbl_27_bss_5220;
extern char lbl_27_bss_5270[];
extern char lbl_27_bss_5224[];
void fn_27_9FA44(void*);
void fn_27_9FA50(void*, int);
void fn_27_82C54(void*, int);
void fn_27_82C94(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), u32, int);
void* __register_global_object(void*, void (*)(void*, int), void*);
void fn_27_9747C(void*, void*, void*, u32, void*, void*, u32, void*, u32, int, u32, void*);
}

struct SoOuterBits {
    u32 top : 4;
    u32 b : 2;
    u32 c : 1;
    u32 rest : 25;
};

extern "C" void* fn_27_1E3A1C(void* self, void* a1, u32 a2, u32 a3, u32 a4, u32 a5, void* a6) {
    char* p = (char*)self;
    SoOuterBits* bits = (SoOuterBits*)(p + 8);
    char* vt = lbl_27_data_1E938;
    *(char**)(p + 0) = vt;
    vt += 0x48;
    *(char**)(p + 4) = vt;
    bits->top = 0;
    bits->b = 1;
    bits->c = 0;
    __construct_array(p + 0xC, (void (*)(void*))fn_27_9FA44, (void (*)(void*))fn_27_9FA50, 0x2C, 1);
    soArrayVectorCalculator::postInitialize(*reinterpret_cast<soArrayVectorCalcInterface*>(p + 4), 1, 1);

    char* sub = p + 0x3c;
    *(char**)(sub + 0) = lbl_27_data_1B58;
    *(char**)(sub + 4) = lbl_27_data_1B58 + 0x48;
    *(u32*)(sub + 8) &= 0x01FFFFFF;
    SoSubObj* o = (SoSubObj*)sub;
    int n = soArrayVectorCalculator::resize(*reinterpret_cast<soArrayVectorCalcInterface*>(sub + 4), 1, o->v4(), o->v14(), o->v13(), o->v27(), o->v28());
    int i = 0;
    while (i < n) {
        o->v10(lbl_27_data_46770);
        i++;
    }
    if (!lbl_27_bss_526C) {
        *(char**)lbl_27_bss_5270 = 0;
        *(char**)lbl_27_bss_5270 = &lbl_27_data_12F08;
        __register_global_object(lbl_27_bss_5270, fn_27_82C54, lbl_27_bss_5260);
        lbl_27_bss_526C = 1;
    }
    void** g = (void**)lbl_27_bss_5270;
    if (!lbl_27_bss_5220) {
        *(char**)lbl_27_bss_5224 = 0;
        *(char**)lbl_27_bss_5224 = &lbl_27_data_12F98;
        __register_global_object(lbl_27_bss_5224, fn_27_82C94, lbl_27_bss_5254);
        lbl_27_bss_5220 = 1;
    }
    fn_27_9747C(p + 0x4C, a1, self, a2, p + 0x3c, g, a3, a6, a4, -1, a5, lbl_27_bss_5224);
    return self;
}
