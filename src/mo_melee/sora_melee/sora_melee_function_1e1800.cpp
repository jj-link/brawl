#include <types.h>
#include <so/so_array_vector_calculator.h>
#pragma force_active on
extern "C" {
extern signed char lbl_27_bss_5220;
extern char lbl_27_data_1E938[], lbl_27_data_3BF88[], lbl_27_data_1B58[];
extern char lbl_27_data_46068[], lbl_27_data_12F98[], lbl_27_bss_51D0[];
extern void* lbl_27_bss_5224;
void fn_27_82C94(void*, int);
void fn_27_9FA44(void*);
void fn_27_9FA50(void*, int);
void fn_27_9FB70(void*);
void fn_27_9FB88(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __register_global_object(void*, void*, void*);
void fn_27_9747C(void*, int, void*, int, void*, void*, int, int, int, int, int, void*);
}
static inline void* getGlobal5224() {
    if (lbl_27_bss_5220 == 0) {
        lbl_27_bss_5224 = 0;
        lbl_27_bss_5224 = &lbl_27_data_12F98;
        __register_global_object(&lbl_27_bss_5224, (void*)fn_27_82C94, lbl_27_bss_51D0);
        lbl_27_bss_5220 = 1;
    }
    return &lbl_27_bss_5224;
}
struct fn27Flags { unsigned int a : 4; unsigned int b : 2; unsigned int c : 1; unsigned int d : 25; };
struct Arr1 { void* vt; void* calc; fn27Flags flags; char elems[0x2c]; };
struct Arr2 { void* vt; void* calc; fn27Flags flags; char elems[0xc]; };
class SoArrayVecObj { public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual bool v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(const void*); virtual void v11(); virtual void v12(); virtual int v13(); virtual bool v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual int v27(); virtual int v28(); void* calc; unsigned int flags; };
struct Outer { Arr1 arr1; Arr2 arr2; char pad[4]; SoArrayVecObj arr3; };
extern "C" void* fn_27_1E1800(Outer* self, int a1, int a2, int a3, int a4, int a5, int a6) {
    char* p = (char*)self;
    int count, i;
    self->arr1.vt = lbl_27_data_1E938;
    self->arr1.calc = lbl_27_data_1E938 + 0x48;
    self->arr1.flags.a = 0;
    self->arr1.flags.b = 1;
    self->arr1.flags.c = 0;
    __construct_array(self->arr1.elems, (void (*)(void*))fn_27_9FA44, (void (*)(void*))fn_27_9FA50, 0x2c, 1);
    soArrayVectorCalculator::postInitialize(*reinterpret_cast<soArrayVectorCalcInterface*>(&self->arr1.calc), 1, 1);
    self->arr2.vt = lbl_27_data_3BF88;
    self->arr2.calc = lbl_27_data_3BF88 + 0x48;
    self->arr2.flags.a = 0;
    self->arr2.flags.b = 1;
    self->arr2.flags.c = 0;
    __construct_array(self->arr2.elems, (void (*)(void*))fn_27_9FB70, (void (*)(void*))fn_27_9FB88, 0xc, 1);
    soArrayVectorCalculator::postInitialize(*reinterpret_cast<soArrayVectorCalcInterface*>(&self->arr2.calc), 1, 1);
    SoArrayVecObj* arr = &self->arr3;
    *(void**)arr = lbl_27_data_1B58;
    arr->calc = lbl_27_data_1B58 + 0x48;
    arr->flags = *(unsigned int*)((char*)arr + 8) & 0x01FFFFFF;
    count = soArrayVectorCalculator::resize(*reinterpret_cast<soArrayVectorCalcInterface*>(&arr->calc), 1, arr->v4(), arr->v14(), arr->v13(), arr->v27(), arr->v28());
    for (i = 0; i < count; i++)
        arr->v10(lbl_27_data_46068);
    fn_27_9747C(p + 0x64, a1, self, a2, (SoArrayVecObj*)(p + 0x54), &self->arr2, a3, a6, a4, -1, a5, getGlobal5224());
    return self;
}
