#pragma force_active on

typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef short s16;

extern "C" {
extern void fn_27_CD5E0(void*);
extern void fn_27_46700(void*, s16);
extern void __construct_array(void*, void (*)(void*), void (*)(void*), u32, s32);
extern s32 resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(void*, s32, s32, s32, s32, s32, s32);
extern char lbl_27_data_384B0[];
}

struct SoraVecCalc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(s32);
    virtual void v11();
    virtual void v12();
    virtual s32 v13();
    virtual s32 v14();
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
    virtual s32 v27();
    virtual s32 v28();
};

extern "C" void* fn_27_19E6E8(void* arg0, s32 arg1, s32 arg2) {
    char* p = (char*)arg0;
    *(void**)p = lbl_27_data_384B0;
    *(void**)(p + 4) = lbl_27_data_384B0 + 0x48;
    *(u32*)(p + 8) &= 0xFFFF;
    __construct_array(p + 0xC, fn_27_CD5E0, (void (*)(void*))fn_27_46700, 0x60, 9);

    SoraVecCalc* self = (SoraVecCalc*)arg0;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    d = self->v28();
    c = self->v27();
    b = self->v13();
    a = self->v14();
    s32 e = self->v4();

    s32 count = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(p + 4, arg1, e, a, b, c, d);

    s32 i = 0;
    while (i < count) {
        self->v10(arg2);
        i++;
    }

    return arg0;
}
