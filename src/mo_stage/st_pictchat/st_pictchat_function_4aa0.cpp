#include <new>
#include <so/collision/so_collision_attack_part.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/so_array_vector_calculator.h>
#pragma force_active on
#pragma use_simple_stdpnew on
extern "C" {
extern char lbl_73_data_4DE8[],lbl_73_data_1428[],lbl_73_data_3F40[],lbl_73_data_4228[],lbl_73_data_48D0[];
extern char lbl_27_bss_398[],lbl_27_bss_3DC[],lbl_27_bss_598[],lbl_27_bss_444[];
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;
extern float lbl_73_rodata_78[];
void fn_27_262728(void*,void*,void*,void*,void*,void*,void*,void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*,int,float,float);
void fn_73_9C84(void*);
void __dt__21soCollisionAttackPartFv(void*,short);
void __construct_array(void*,void(*)(void*),void(*)(void*,short),unsigned long,int);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*,short);
int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(void*,int,int,int,int,int,int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*,int,int);
}
struct Bits { unsigned int a:4,b:2,c:1,rest:25; };
struct Obj {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
virtual int v4(); virtual void v5(); virtual void v6(); virtual void v7();
virtual void v8(); virtual void v9(); virtual void v10(const soCollisionAttackPart&);
virtual void v11(); virtual void v12(); virtual int v13(); virtual int v14();
virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
virtual int v27(); virtual int v28();
void* calc; unsigned int flags; char parts[0x2d0];
void* vt2; void* calc2; Bits bits2; char groups[0x78];
void* vt3; char impl[0xa0];
};
struct BigPart { float padding[0x4e]; char part[0x90]; };
class AbsoluteArrayStorage { void* table; public: AbsoluteArrayStorage() : table(lbl_73_data_48D0) {} };
inline void initializeAttackModule(void* impl,soModuleAccesser* accesser,int id,gfTask::Category category,
soArray<soCollisionAttackPart>* parts,soArray<soCollisionGroup>* groups,
soArray<soCollisionAttackAbsolute>* absolutes,soEventObserverRegistrationDesc* desc,BigPart& storage,float value) {
absolutes = (soArray<soCollisionAttackAbsolute>*)new(absolutes) AbsoluteArrayStorage;
storage.padding[0x3d]=value;
storage.padding[0xa]=value;
storage.padding[0x25]=value;
new(impl) soCollisionAttackModuleImpl(accesser,id,category,parts,groups,absolutes,desc,true);
}
extern "C" char* fn_73_4AA0(char* self,char* arg) {
float* rodata=lbl_73_rodata_78;
BigPart storage;
fn_27_262728(self,arg,lbl_73_data_4DE8,self+0x6bc,lbl_27_bss_398,lbl_27_bss_3DC,lbl_27_bss_598,lbl_27_bss_444);
*(void**)(self+0x3c)=lbl_73_data_1428;
*(void**)(self+0x40)=lbl_73_data_1428+0x64;
*(void**)(self+0x48)=lbl_73_data_1428+0x70;
*(void**)(self+0x54)=lbl_73_data_1428+0x84;
*(void**)(self+0x64)=lbl_73_data_1428+0xdc;
gfTask::Category category; Obj* h; soEventObserverRegistrationDesc* desc; int id;
id=*(int*)(self+0x28);
category=(gfTask::Category)(unsigned char)(*(unsigned int*)(self+0x2c)>>7);
h=(Obj*)(self+0x358);
desc=lbl_27_data_54C60;
{
new(storage.part) soCollisionAttackPart((soCollision::Category)6,false);
*(void**)h=lbl_73_data_3F40; h->calc=lbl_73_data_3F40+0x48; h->flags &= 0x7ffff;
__construct_array(h->parts,fn_73_9C84,__dt__21soCollisionAttackPartFv,0x90,5);
int d,c,b,a;
a=h->v28(); b=h->v27(); c=h->v13(); d=h->v14(); int e=h->v4();
int count=resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(&h->calc,5,e,d,c,b,a);
for(int i=0;i<count;++i) h->v10(*(soCollisionAttackPart*)storage.part);
((soCollisionAttackPart*)storage.part)->~soCollisionAttackPart();
}
h->vt2=lbl_73_data_4228; h->calc2=lbl_73_data_4228+0x48;
h->bits2.a=0; h->bits2.b=1; h->bits2.c=0;
__construct_array(h->groups,__ct__16soCollisionGroupFv,fn_27_37D3C,0x78,1);
postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&h->calc2,1,1);
float value=rodata[4];
initializeAttackModule(h->impl,(soModuleAccesser*)(self+0xa8),id,category,(soArray<soCollisionAttackPart>*)h,
(soArray<soCollisionGroup>*)&h->vt2,(soArray<soCollisionAttackAbsolute>*)&h->vt3,desc,storage,value);
fn_27_26320C(self);
fn_27_2632F4(self,*(int*)(arg+0xc),rodata[10],rodata[0]);
*(int*)(self+0x75c)=0; *(int*)(self+0x760)=0; *(int*)(self+0x764)=0; *(int*)(self+0x768)=0;
return self;
}
