#pragma force_active on
class First { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual short slot7(); };
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(void*); };
struct Holder { char pad[8]; First first; }; struct Modules { char pad0[4]; Object_vptr_0* other; char pad1[0x78]; Holder* holder; }; struct Access { char pad[0xd8]; Modules* modules; };
struct Object { void* vtable; void* p4; unsigned int flags; char arr0[0x14]; void* p20; void* p24; unsigned int flags28; char arr2[0x10]; void* p3c; void* p40; int n44; int n48; int n4c; int n50; char pad54[4]; void* p58; void* p5c; unsigned int flags60; char arr64[0x2c]; char pad90[4]; void* p94; int n98; int n9c; int na0; char padA4[4]; char data[1]; };
struct Flag60 { unsigned int hi:4; unsigned int two:2; unsigned int bit25:1; unsigned int low:25; };
extern "C" {
extern char lbl_27_data_1D4E8[],lbl_27_data_3C688[],lbl_27_data_8E80[],lbl_27_data_20248[],lbl_27_data_2490[],lbl_27_data_11740[],lbl_27_data_12380[];
extern signed char lbl_27_bss_5208,lbl_27_bss_5200; extern void* lbl_27_bss_520C; extern void* lbl_27_bss_5204;
extern char lbl_27_bss_884C[],lbl_27_bss_8840[],lbl_27_bss_9BC[],lbl_27_bss_DBC[];
void fn_27_AB128(void*); void fn_27_AB18C(void*,short); void fn_27_AB15C(void*,void*); void fn_27_D2A0C(void*); void* fn_27_AB510(void*,int); void fn_27_137B4(void*); void fn_27_137EC(void*);
void __construct_array(void*,void(*)(void*),void(*)(void*),unsigned long,int); void* __register_global_object(void*,void*,void*); void fn_27_82794(void*,short); void fn_27_82A14(void*,short);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*,long,long);
void fn_27_13844(void*,Access*,void*,void*,void*,void*,void*,void*,int,int,void*);
}
inline char* part(char* p, int offset) {
 for (int i=0; i<1; ++i) { if (i==0) return p+offset; }
 return 0;
}
inline void initializeArray(Object* self) {
 char temp[0x14];
 for (int i=0; i<1; ++i) {
  fn_27_AB15C(temp, i==0 ? &self->p20 : 0);
  ((Object_vptr_0*)self)->slot10(temp);
  fn_27_AB18C(temp,-1);
 }
}
inline void* global1() {
 if(lbl_27_bss_5208==0){lbl_27_bss_520C=0;lbl_27_bss_520C=lbl_27_data_11740;__register_global_object(&lbl_27_bss_520C,(void*)fn_27_82794,lbl_27_bss_884C);lbl_27_bss_5208=1;}
 return &lbl_27_bss_520C;
}
extern "C" Object* fn_27_38B778(Object* self,Access* access,int arg) {
self->vtable=lbl_27_data_1D4E8; self->p4=lbl_27_data_1D4E8+0x48; self->flags&=0x01ffffff;
__construct_array((char*)self+0xc,fn_27_AB128,(void(*)(void*))fn_27_AB18C,0x14,1);
self->p20=lbl_27_data_3C688; self->p24=lbl_27_data_3C688+0x48; self->flags28&=0x01ffffff;
__construct_array((char*)self+0x2c,fn_27_D2A0C,(void(*)(void*))fn_27_AB510,0x10,1);
self->p40=self; self->p3c=lbl_27_data_8E80; self->n44=0; self->n50=0; self->n48=-1; self->n4c=-1;
initializeArray(self);
self->p58=lbl_27_data_20248; self->p5c=lbl_27_data_20248+0x48;
Flag60* f=(Flag60*)&self->flags60; f->hi=0; f->two=1; f->bit25=0;
__construct_array((char*)self+0x64,fn_27_137B4,(void(*)(void*))fn_27_137EC,0x2c,1);
postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell((char*)self+0x5c,1,1);
self->n98=0; self->p94=lbl_27_data_2490; self->n9c=arg; self->na0=3; if(arg==0) self->na0=0;
void* global=global1();
if(lbl_27_bss_5200==0){lbl_27_bss_5204=0;lbl_27_bss_5204=lbl_27_data_12380;__register_global_object(&lbl_27_bss_5204,(void*)fn_27_82A14,lbl_27_bss_8840);lbl_27_bss_5200=1;}
Modules* modules=access->modules;
char* a58=part((char*)self,0x58); char* a3c=part((char*)self,0x3c);
short val=modules->holder->first.slot7();
fn_27_13844((char*)self+0xa8,access,(char*)self+0x94,a3c,global,a58,lbl_27_bss_9BC,&lbl_27_bss_5204,val,0,lbl_27_bss_DBC);
access->modules->other->slot0(); return self;
}