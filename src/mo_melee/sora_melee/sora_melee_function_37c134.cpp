#include <so/so_array_vector_calculator.h>
#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_20950[], lbl_27_data_98CD0[], lbl_27_data_3C688[];
extern char lbl_27_data_3E0E0[], lbl_27_data_8E80[], lbl_27_data_98BD8[];
extern char lbl_27_data_3ED00[], lbl_27_data_93914[];
extern unsigned char __vt__19soGeneralWorkSimple[];
void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_AB15C(void*, void*);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_73930(void*, int, void*, void*, void*, void*, void*, int, int, int);
}
struct WorkBase { void* vtable0; unsigned char flag; char pad[3]; };
struct Work : WorkBase {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
 virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
 virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
 virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
 virtual void f24(); virtual void f25();
 void* owner; int count1; void* data1; int count2; void* data2; int count3;
};
struct Array {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual bool v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(const void*);
 virtual void v11(); virtual void v12(); virtual int v13(); virtual bool v14();
 virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
 virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
 virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
 virtual int v27(); virtual int v28();
 void* calc; unsigned int flags;
};
struct WorkStorage { int ints[18]; float floats[14]; int flags[2]; Work work; };
struct Object {
 void* vtable; int zero; int status; int enabled; WorkStorage storage;
 char other1[0xf4]; char member1b0[0xc]; char other2[0x4ac]; Array* arrayPtr; Array array; char impl[1];
};
extern "C" Object* fn_27_37C134(Object* self, int arg1, int arg2, int arg3) {
 self->zero = 0;
 self->vtable = lbl_27_data_20950;
 self->status = arg2;
 self->enabled = 0x112;
 if (!arg2) self->enabled = 0;
 WorkStorage* st = &self->storage;
 Work* w = &st->work;
 w->flag = 0;
 *(void**)((char*)w + 8) = __vt__19soGeneralWorkSimple;
 w->vtable0 = __vt__19soGeneralWorkSimple + 8;
 w->owner = st->ints; w->count1 = 18;
 w->data1 = st->floats; w->count2 = 14;
 w->data2 = st->flags; w->count3 = 2;
 w->f25();
 char* p = (char*)self + 0xbc;
 *(void**)p = lbl_27_data_98CD0;
 *(void**)(p+4) = lbl_27_data_98CD0 + 0x48;
 *(unsigned int*)(p+8) &= 0x003fffff;
 __construct_array(p+0xc, fn_27_AB128, (void (*)(void*))fn_27_AB18C, 0x14, 2);
 *(void**)(p+0x34) = lbl_27_data_3C688;
 *(void**)(p+0x38) = lbl_27_data_3C688+0x48;
 *(unsigned int*)(p+0x3c) &= 0x01ffffff;
 __construct_array(p+0x40, fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 1);
 *(void**)(p+0x50) = lbl_27_data_3E0E0;
 *(void**)(p+0x54) = lbl_27_data_3E0E0+0x48;
 *(unsigned int*)(p+0x58) &= 0xffff;
 __construct_array(p+0x5c, fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 8);
 *(void**)(p+0xdc) = lbl_27_data_8E80;
 void** t792 = (void**)(p+0xe0);
 *t792 = p;
 *(int*)(p+0xe4) = 0;
 *(int*)(p+0xe8) = -1;
 *(int*)(p+0xec) = -1;
 *(int*)(p+0xf0) = 0;
 char temp[0x14];
 for (int i=0; i<2; ++i) {
  fn_27_AB15C(temp, i == 0 ? p+0x50 : i == 1 ? p+0x34 : 0);
  ((Array*)p)->v10(temp);
  fn_27_AB18C(temp, -1);
 }
 *(void**)(self->member1b0) = lbl_27_data_98BD8;
 *(void**)((char*)self+0x1b4) = lbl_27_data_98BD8+0x48;
 *(unsigned int*)((char*)self+0x1b8) &= 1;
 Array* a = &self->array;
 self->arrayPtr = a;
 *(void**)a = lbl_27_data_3ED00;
 a->calc = lbl_27_data_3ED00+0x48;
 a->flags &= 0x01ffffff;
 int n = soArrayVectorCalculator::resize(*(soArrayVectorCalcInterface*)&a->calc, 1, a->v4(), a->v14(), a->v13(), a->v27(), (a->v28()));
 for (int i=0; i<n; i++) a->v10(lbl_27_data_93914);
 ((Array*)((char*)self+0x66c))->v13();
 fn_27_73930((char*)self+0x67c, arg1, self, self->member1b0,
 (char*)self+0x98, (char*)self+0x198, (char*)self+0x668, arg3, 0x12b, 1);
 return self;
}