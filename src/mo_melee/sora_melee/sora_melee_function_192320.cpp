#include <revolution/GX/GXTypes.h>
#pragma force_active on
struct Parameters {
 float values[7];
 unsigned int value:9; unsigned int field9:2; unsigned int field11:2;
 unsigned int field13:2; unsigned int field15:1; unsigned int rest:16;
};
class Module04 {
 int padding[2];
public:
 virtual void slot0() = 0;
 virtual void slot1() = 0;
 virtual void slot2() = 0;
 virtual void slot3() = 0;
 virtual void slot4() = 0;
 virtual void slot5() = 0;
 virtual void slot6() = 0;
 virtual void slot7() = 0;
 virtual void slot8() = 0;
 virtual void slot9() = 0;
 virtual void slot10() = 0;
 virtual void slot11() = 0;
 virtual void slot12() = 0;
 virtual void slot13() = 0;
 virtual void slot14() = 0;
 virtual void slot15() = 0;
 virtual void slot16() = 0;
 virtual void slot17() = 0;
 virtual void slot18() = 0;
 virtual void slot19() = 0;
 virtual void slot20() = 0;
 virtual void slot21() = 0;
 virtual void slot22() = 0;
 virtual void slot23() = 0;
 virtual void slot24() = 0;
 virtual void slot25() = 0;
 virtual void slot26() = 0;
 virtual void slot27() = 0;
 virtual void slot28() = 0;
 virtual void slot29() = 0;
 virtual void slot30() = 0;
 virtual void slot31() = 0;
 virtual void slot32() = 0;
 virtual int call8C(int) = 0;
};
class Object_vptr_0 {
public:
 virtual void slot0() = 0;
 virtual void slot1() = 0;
 virtual void slot2() = 0;
 virtual void slot3() = 0;
 virtual void slot4() = 0;
 virtual void slot5() = 0;
 virtual void slot6() = 0;
 virtual void slot7() = 0;
 virtual void slot8() = 0;
 virtual void slot9() = 0;
 virtual void slot10() = 0;
 virtual void slot11() = 0;
 virtual void slot12(int, Parameters*, int) = 0;
 virtual void slot13() = 0;
 virtual void slot14() = 0;
 virtual void slot15(int,int,int) = 0;
 virtual void slot16() = 0;
 virtual void slot17() = 0;
 virtual void slot18(int,int) = 0;
};
struct Modules { char pad00[4]; Module04* module04; char pad08[0x18]; Object_vptr_0* module20; };
struct Object { char pad00[0xD8]; Modules* modules; };
extern "C" void fn_27_192320(void*, Object* object) {
 Parameters p;
 p.values[0]=0.0f; p.values[1]=10.0f; p.values[2]=0.0f;
 p.values[3]=0.0f; p.values[4]=12.0f; p.values[5]=0.0f; p.values[6]=8.0f;
 p.value=object->modules->module04->call8C(0x130);
 p.field9=0; p.field11=1; p.field13=0; p.field15=1;
 object->modules->module20->slot12(0,&p,0);
 object->modules->module20->slot18(3,0);
 object->modules->module20->slot15(0,0,0);
}
