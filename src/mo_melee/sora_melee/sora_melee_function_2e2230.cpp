#include <so/so_array_vector_calculator.h>
#include <so/work/so_general_work_simple.h>
#pragma force_active on
extern "C" {
extern char lbl_27_data_20950[], lbl_27_data_1D4E8[], lbl_27_data_3EF48[];
extern char lbl_27_data_8E80[], lbl_27_data_3E650[], lbl_27_data_3ED00[], lbl_27_data_7CB18[];
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
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25();
 void* owner; int count1; void* data1; int count2; void* data2; int count3;
};
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual bool slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(const void*); virtual void slot11(); virtual void slot12(); virtual int slot13(); virtual bool slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual int slot27(); virtual int slot28();
 void* calc; unsigned int flags;
};
struct WorkStorage { int ints[2]; float floats[2]; int flags; Work work; };
struct Object {
 void* vtable; int zero; int status; int enabled; WorkStorage storage;
 char other[0xa4]; void* vt; void* vt2; unsigned int fl; char pad2[0xc];
 Object_vptr_0* arrayPtr; Object_vptr_0 array; char impl[1];
};
extern "C" Object* fn_27_2E2230(Object* self, int arg1, int arg2, int arg3) {
 self->zero = 0;
 self->vtable = lbl_27_data_20950;
 self->status = arg2;
 self->enabled = 3;
 if (!arg2) self->enabled = 0;
 WorkStorage* st = &self->storage;
 Work* w = &st->work;
 w->flag = 0;
 *(void**)((char*)w + 8) = __vt__19soGeneralWorkSimple;
 w->vtable0 = __vt__19soGeneralWorkSimple + 8;
 w->owner = st->ints;
 w->count1 = 2;
 w->data1 = st->floats;
 w->count2 = 2;
 w->data2 = &st->flags;
 w->count3 = 1;
 w->f25();
 int x;
 char* p = (char*)self + 0x48;
 *(void**)p = lbl_27_data_1D4E8;
 *(void**)(p + 4) = lbl_27_data_1D4E8 + 0x48;
 *(unsigned int*)(p + 8) &= 0x01ffffff;
 __construct_array(p + 0x0c, fn_27_AB128, (void (*)(void*))fn_27_AB18C, 0x14, 1);
 *(void**)(p + 0x20) = lbl_27_data_3EF48;
 *(void**)(p + 0x24) = lbl_27_data_3EF48 + 0x48;
 *(unsigned int*)(p + 0x28) &= 0x0007ffff;
 __construct_array(p + 0x2c, fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 6);
 *(void**)(p + 0x8c) = lbl_27_data_8E80;
 *(void**)(p + 0x90) = p;
 *(int*)(p + 0x94) = 0;
 *(int*)(p + 0x98) = -1;
 *(int*)(p + 0x9c) = -1;
 *(int*)(p + 0xa0) = 0;
 char temp[0x14];
 for (int i = 0; i < 1; ++i) {
  fn_27_AB15C(temp, i == 0 ? p + 0x20 : 0);
  ((Object_vptr_0*)p)->slot10(temp);
  fn_27_AB18C(temp, -1);
 }
 self->vt = lbl_27_data_3E650;
 self->vt2 = lbl_27_data_3E650 + 0x48;
 self->fl &= 0x003fffff;
 Object_vptr_0* a = &self->array;
 self->arrayPtr = a;
 *(void**)a = lbl_27_data_3ED00;
 a->calc = lbl_27_data_3ED00 + 0x48;
 a->flags &= 0x01ffffff;
 x = a->slot28();
 int n = soArrayVectorCalculator::resize(*(soArrayVectorCalcInterface*)&a->calc, 1, a->slot4(), a->slot14(), a->slot13(), a->slot27(), x);
 int i = 0;
 for (; i < n; i++) a->slot10(&lbl_27_data_7CB18);
 self->array.slot13();
 fn_27_73930((char*)self + 0x118, arg1, self, (char*)self + 0xec, (char*)self + 0x24, (char*)self + 0xd4, (char*)self + 0x104, arg3, 3, 1);
 return self;
}