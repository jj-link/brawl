#pragma force_active on
#pragma optimize_for_size off
#pragma optimization_level 2
#include <nw4r/math/math_types.h>
#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on
struct Pair { int x,y; };
struct Result { int a; Pair b; int c; Pair d; int e; Pair f,g,h,i,j,k; };
class Calc { public: char pad[8];
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
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
virtual void v27();
virtual void v28();
virtual void v29();
virtual void v30();
virtual void v31();
virtual void v32();
virtual void v33();
virtual int get(int);
virtual void v35();
virtual void v36();
virtual void v37();
virtual void v38();
virtual void v39();
virtual void v40();
virtual void v41();
virtual void v42();
virtual void v43();
virtual void v44();
virtual void v45();
virtual void v46();
virtual void v47();
virtual void v48();
virtual void v49();
virtual void v50();
virtual void v51();
virtual void v52();
virtual void v53();
virtual float value();
};
class Maker { public:
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual Result& make(Result&,int);
};
class Object_vptr_0 { public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual float slot22();
};
struct Bucket { char pad[4]; Calc* calc; char pad2[4]; Object_vptr_0* rate; };
struct Services { char pad[0xd8]; Bucket* bucket; int get(int n) { return bucket->calc->get(n); } };
struct Arg { char pad0[0x3c]; Maker* maker; char pad2[0x128]; Services* services; };
extern "C" void fn_8019589C(void*,nw4r::math::VEC3*);
extern "C" void fn_27_18D9C(nw4r::math::VEC3* out,const Arg* arg,int n,unsigned int flag) {
Services* q=arg->services;
Maker* maker=arg->maker;
Result temp;
Result* result=&maker->make(temp,q->get(n));
if(result!=&temp) { temp=*result; result=&temp; }
fn_8019589C(result,out);
if(flag==1) {
Bucket* b=arg->services->bucket;
Calc* c2=b->calc;
Object_vptr_0* rate=b->rate;
float a=rate->slot22();
float d=c2->value();
LocalScale((const Vec*)out,(Vec*)out,d*a);
}
}
