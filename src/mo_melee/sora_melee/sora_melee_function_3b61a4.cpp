#include <types.h>
#pragma force_active on
#pragma fp_contract off
typedef unsigned long u32; typedef float f32;
class Energy { public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual f32 v12(u32);
};
class Obj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(f32*); };
class Work { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void* v6(int); };
class Dst { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); u8 pad4; s8 field5; };
struct Modules { char pad0[0xc]; Obj* obj; char pad1[0x54]; Energy* energy; char pad2[0x14]; Work* work; };
struct Access { char pad[0xd8]; Modules* modules; };
struct SelfBase { char pad[0x3c]; };
class Self : public SelfBase { public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
char pad[0x20]; Access* access;
};
extern "C" void fn_27_1DA1F4(void*);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" char lbl_27_data_13840[]; extern "C" char lbl_27_data_CDF8[]; extern "C" const f32 lbl_27_rodata_7FE4;
extern "C" void fn_27_3B61A4(Self* self, int arg1) {
fn_27_1DA1F4(self);
if (arg1 == 1) {
f32 a=self->access->modules->energy->v12(0x11000002);
f32 b=self->access->modules->energy->v12(0x11000001);
f32 vec[3]; vec[0]=b; vec[1]=a; vec[2]=lbl_27_rodata_7FE4;
self->access->modules->obj->v5(vec); self->v43();
void* src=self->access->modules->work->v6(2);
void* result=__dynamic_cast(src,0,lbl_27_data_13840,lbl_27_data_CDF8,0);
if(result) { Dst* dst=(Dst*)result; dst->v6(); dst->field5 &= 0xFFFFFF7F; }
}
}