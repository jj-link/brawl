#include <types.h>
#include <new>
#include <so/so_array_vector_calculator.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern signed char lbl_27_bss_526C;
extern char lbl_27_data_1E938[], lbl_27_data_150C8[], lbl_27_data_1B58[];
extern char lbl_27_data_12F08[], lbl_27_data_7BB54[], lbl_27_bss_7398[];
extern void* lbl_27_bss_5270;
void fn_27_82C54(void*, int);
void fn_27_9FA44(void*);
void fn_27_9FA50(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __register_global_object(void*, void*, void*);
void fn_27_9747C(void*, int, void*, int, void*, void*, int, int, int, int, int, void*);
}

struct fn27Flags { unsigned int a : 4; unsigned int b : 2; unsigned int c : 1; unsigned int d : 25; };

struct Elem { s8 v; Elem() : v(-1) { } };

struct Vec1 {
    void* vt0;
    void* vt1;
    u32 top : 2;
    u32 last : 2;
    u32 size : 2;
    u32 isFull : 1;
    Elem elems[1];
    Vec1() : vt0(lbl_27_data_150C8), vt1(lbl_27_data_150C8 + 0x48), top(0), last(0), size(1), isFull(false) { }
};

class SoArrayVecObj { public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual bool v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(const void*);
    virtual void v11(); virtual void v12(); virtual int v13(); virtual bool v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
    virtual int v27(); virtual int v28();
    void* calc;
    unsigned int flags;
};

struct Arr1 { void* vt; void* calc; fn27Flags flags; char elems[0x2c]; };

struct Outer {
    Arr1 arr1;
    u32 pad;
    Vec1 vec;
    SoArrayVecObj arr;
    char body[0x10];
};

static inline void* getGlobal5270() {
    if (lbl_27_bss_526C == 0) {
        lbl_27_bss_5270 = 0;
        lbl_27_bss_5270 = lbl_27_data_12F08;
        __register_global_object(&lbl_27_bss_5270, (void*)fn_27_82C54, lbl_27_bss_7398);
        lbl_27_bss_526C = 1;
    }
    return &lbl_27_bss_5270;
}

extern "C" void* fn_27_2DB778(Outer* self, int a1, int a2, int a3, int a4, int a5, int a6) {
    char* p = (char*)self;
    int count, i;
    self->arr1.vt = lbl_27_data_1E938;
    self->arr1.calc = lbl_27_data_1E938 + 0x48;
    self->arr1.flags.a = 0;
    self->arr1.flags.b = 1;
    self->arr1.flags.c = 0;
    __construct_array(self->arr1.elems, (void (*)(void*))fn_27_9FA44, (void (*)(void*))fn_27_9FA50, 0x2c, 1);
    soArrayVectorCalculator::postInitialize(*reinterpret_cast<soArrayVectorCalcInterface*>(&self->arr1.calc), 1, 1);
    Vec1* vec = &self->vec;
    new (vec) Vec1;
    soArrayVectorCalculator::postInitialize(*reinterpret_cast<soArrayVectorCalcInterface*>(&vec->vt1), 1, 1);
    SoArrayVecObj* arr = &self->arr;
    *(void**)arr = lbl_27_data_1B58;
    arr->calc = lbl_27_data_1B58 + 0x48;
    arr->flags &= 0x01FFFFFF;
    count = soArrayVectorCalculator::resize(*reinterpret_cast<soArrayVectorCalcInterface*>(&arr->calc), 1, arr->v4(), arr->v14(), arr->v13(), arr->v27(), arr->v28());
    for (i = 0; i < count; i++)
        arr->v10(lbl_27_data_7BB54);
    fn_27_9747C(p + 0x58, a1, self, a2, (SoArrayVecObj*)(p + 0x48), getGlobal5270(), a3, a6, a4, -1, a5, &self->vec);
    return self;
}
