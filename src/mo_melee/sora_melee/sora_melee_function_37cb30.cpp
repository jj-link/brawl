#include <types.h>
#include <new>
#include <so/so_array_vector_calculator.h>
#pragma force_active on
#pragma use_simple_stdpnew on
extern "C" {
extern char lbl_27_data_1E938[], lbl_27_data_3BF88[], lbl_27_data_150C8[], lbl_27_data_1B58[], lbl_27_data_93918[];
void fn_27_9FA44(void*);
void fn_27_9FA50(void*, int);
void fn_27_9FB70(void*);
void fn_27_9FB88(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_9747C(void*, int, void*, int, void*, void*, int, int, int, int, int, void*);
}
struct Flags { unsigned int a:4; unsigned int b:2; unsigned int c:1; unsigned int d:25; };
struct Elem { s8 v; Elem() : v(-1) {} };
struct Vec1 {
 void* vt0; void* vt1;
 u32 top:2; u32 last:2; u32 size:2; u32 isFull:1;
 Elem elems[1];
 Vec1() : vt0(lbl_27_data_150C8), vt1(lbl_27_data_150C8+0x48), top(0), last(0), size(1), isFull(false) {}
};
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual bool slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(const void*); virtual void slot11(); virtual void slot12(); virtual int slot13(); virtual bool slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual int slot27(); virtual int slot28();
 void* calc; unsigned int flags;
};
struct Arr1 { void* vt; void* calc; Flags flags; char elems[0x2c]; };
struct Arr2 { void* vt; void* calc; Flags flags; char elems[0xc]; };
struct Outer { Arr1 arr1; Arr2 arr2; Vec1 vec; Object_vptr_0 arr; char pad[4]; char body[1]; };
extern "C" void* fn_27_37CB30(Outer* self, int a1, int a2, int a3, int a4, int a5, int a6) {
 char* p=(char*)self; int one=1;
 self->arr1.vt=lbl_27_data_1E938; self->arr1.calc=lbl_27_data_1E938+0x48;
 self->arr1.flags.a=0; self->arr1.flags.b=one; self->arr1.flags.c=0;
 __construct_array(self->arr1.elems,fn_27_9FA44,(void(*)(void*))fn_27_9FA50,0x2C,one);
 soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&self->arr1.calc,one,one);
 self->arr2.vt=lbl_27_data_3BF88; self->arr2.calc=lbl_27_data_3BF88+0x48;
 self->arr2.flags.a=0; self->arr2.flags.b=one; self->arr2.flags.c=0;
 __construct_array(self->arr2.elems,fn_27_9FB70,(void(*)(void*))fn_27_9FB88,0x0C,one);
 soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&self->arr2.calc,one,one);
 Vec1* vec=&self->vec;
 new (vec) Vec1;
 soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&vec->vt1,one,one);
 Object_vptr_0* arr=&self->arr;
 *(void**)arr=lbl_27_data_1B58; arr->calc=lbl_27_data_1B58+0x48;
 arr->flags=(*(unsigned int*)((char*)arr+8)&0x01FFFFFF);
 int n=soArrayVectorCalculator::resize(*(soArrayVectorCalcInterface*)&arr->calc,one,arr->slot4(),arr->slot14(),arr->slot13(),arr->slot27(),arr->slot28());
 for(int i=0;i<n;++i) arr->slot10(lbl_27_data_93918);
 fn_27_9747C(p+0x6C,a1,self,a2,&self->arr,&self->arr2,a3,a6,a4,10,a5,&self->vec);
 return self;
}