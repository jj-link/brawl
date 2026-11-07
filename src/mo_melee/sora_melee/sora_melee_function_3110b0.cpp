#include <so/so_value_accesser.h>
#pragma force_active on
#pragma fp_contract off
struct U64 { unsigned long hi, lo; };
class Object_vptr_0 { public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual int slot3(int=0, void* = 0); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual U64 slot13(short*); virtual void slot14(); virtual void slot15(); virtual int slot16(); virtual int slot17(unsigned long); };
class Stop { public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual int slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual U64 slot13(short*); virtual void slot14(); virtual void slot15(); virtual int slot16(); virtual int slot17(unsigned long); };
class Motion { public: char pad[8];
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
virtual void v34();
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
virtual void v54();
virtual void v55();
virtual void v56();
virtual U64 get(int,int);
};
struct Modules { char pad0[0x10]; Motion* motion; Stop* stop; char pad1[0x4c]; Object_vptr_0* work; char pad2[8]; Object_vptr_0* status; char pad3[8]; Object_vptr_0* other; };
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" float fn_8003DDD0(void*,void*);
extern float lbl_27_rodata_7478; extern float lbl_27_rodata_747C;
extern "C" void fn_27_3110B0(void*,Accesser* a) {
switch(a->modules->status->slot16()) { case 0x117:
if (a->modules->work->slot17(0x22000011)) { if (!a->modules->stop->slot3()) {
U64 xx, yy;
U64 x = a->modules->motion->get(8,0);
xx = x;
short s=1;
U64 y=a->modules->other->slot13(&s);
yy=y;
float f=fn_8003DDD0(&xx,&yy);
if(f >= lbl_27_rodata_7478 * (lbl_27_rodata_747C + soValueAccesser::getConstantFloat((soModuleAccesser*)a,0xfb7,0)))
a->modules->status->slot3(0x119,a);
}} break; }
}