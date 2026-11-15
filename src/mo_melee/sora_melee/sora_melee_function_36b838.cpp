#include <so/so_array_vector_calculator.h>
#pragma force_active on
extern "C" {
extern signed char lbl_27_bss_835C, lbl_27_bss_526C, lbl_27_bss_5220;
extern char lbl_27_bss_8344[], lbl_27_bss_8338[], lbl_27_bss_832C[];
extern char lbl_27_data_1B58[], lbl_27_data_92218[];
extern int lbl_27_data_11DF0, lbl_27_data_12F08, lbl_27_data_12F98;
extern void* lbl_27_bss_8360; extern void* lbl_27_bss_5270; extern void* lbl_27_bss_5224;
void fn_27_828D4(void*, int); void fn_27_82C54(void*, int); void fn_27_82C94(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_9747C(void*, int, void*, int, void*, void*, int, int, int, int, int, void*);
}
static inline void* getGlobal8360() { if (lbl_27_bss_835C == 0) { lbl_27_bss_8360=0; lbl_27_bss_8360=&lbl_27_data_11DF0; __register_global_object(&lbl_27_bss_8360,(void*)fn_27_828D4,lbl_27_bss_8344); lbl_27_bss_835C=1; } return &lbl_27_bss_8360; }
static inline void* getGlobal5270() { if (lbl_27_bss_526C == 0) { lbl_27_bss_5270=0; lbl_27_bss_5270=&lbl_27_data_12F08; __register_global_object(&lbl_27_bss_5270,(void*)fn_27_82C54,lbl_27_bss_8338); lbl_27_bss_526C=1; } return &lbl_27_bss_5270; }
static inline void* getGlobal5224() { if (lbl_27_bss_5220 == 0) { lbl_27_bss_5224=0; lbl_27_bss_5224=&lbl_27_data_12F98; __register_global_object(&lbl_27_bss_5224,(void*)fn_27_82C94,lbl_27_bss_832C); lbl_27_bss_5220=1; } return &lbl_27_bss_5224; }
class SoArrayVecObj { public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual bool v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(const void*); virtual void v11(); virtual void v12(); virtual int v13(); virtual bool v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual int v27(); virtual int v28(); void* calc; unsigned int flags; };
struct Outer { void* unk0; SoArrayVecObj arr; };
extern "C" void* fn_27_36B838(Outer* self,int a1,int a2,int a3,int a4,int a5,int a6) {
SoArrayVecObj* arr=&self->arr;
int count,i; void *g8360,*g5270;
*(void**)arr=lbl_27_data_1B58; arr->calc=lbl_27_data_1B58+0x48; arr->flags=*(unsigned int*)((char*)arr+8)&0x01FFFFFF;
count=soArrayVectorCalculator::resize(*reinterpret_cast<soArrayVectorCalcInterface*>(&arr->calc),1,arr->v4(),arr->v14(),arr->v13(),arr->v27(),arr->v28());
for(i=0;i<count;i++) arr->v10(lbl_27_data_92218);
g8360=getGlobal8360(); g5270=getGlobal5270(); getGlobal5224();
fn_27_9747C((char*)self+0x14,a1,g8360,a2,&self->arr,g5270,a3,a6,a4,-1,a5,&lbl_27_bss_5224);
return self;
}