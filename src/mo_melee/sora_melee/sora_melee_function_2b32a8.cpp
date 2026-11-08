#pragma force_active on
#include <so/so_value_accesser.h>
extern "C" {
extern const char lbl_27_data_71BE0[];
extern const char lbl_27_data_CDC0[];
extern const float lbl_27_rodata_5EA8;
extern const float lbl_27_rodata_5EAC;
void* __dynamic_cast(void*, int, const void*, const void*, int);
void fn_27_2B348C(void*, void*, void*, void*, int);
}
class Obj64 { public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual int query(int);
};
class Obj7C { public:
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
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void slot46();
virtual void slot47(float*, void*);
};
class Obj4C { public:
virtual void slot0(); virtual void slot1(); virtual void apply(int,int,int,float*);
};
struct LocalVec3f { float x,y,z; LocalVec3f() {} LocalVec3f(float a, float b, float c) : x(a), y(b), z(c) {} };
struct LocalVec2f { float x,y; };
struct Arg27Data { char pad[12]; float x,y; };
inline void applyEffect(Obj4C* obj, void* arg2, float* value) {
    float constant = soValueAccesser::getConstantFloat((soModuleAccesser*)arg2, 0x7E6, 0);
    obj->apply(0, (int)constant, 0, value);
}
extern "C" int fn_27_2B32A8(void* arg0, void* arg1, void* arg2, Arg27Data* arg3) {
char* self = (char*)arg2;
Obj64* queryObj = *(Obj64**)(*(char**)(self + 0xD8) + 0x64);
int result = queryObj->query(0x10000016);
switch (result) {
case 2: {
LocalVec3f position(arg3->x, arg3->y, lbl_27_rodata_5EA8);
Obj7C* obj = (Obj7C*)__dynamic_cast(*(void**)(*(char**)(self + 0xD8) + 0x7C), 0, lbl_27_data_71BE0, lbl_27_data_CDC0, 1);
obj->slot9(); obj->slot47(&position.x, arg2); break;
}
case 3: {
LocalVec3f position;
position.x = arg3->x; position.y = lbl_27_rodata_5EA8; position.z = lbl_27_rodata_5EA8;
Obj7C* obj = (Obj7C*)__dynamic_cast(*(void**)(*(char**)(self + 0xD8) + 0x7C), 0, lbl_27_data_71BE0, lbl_27_data_CDC0, 1);
obj->slot9(); obj->slot47(&position.x, arg2); break;
}
}
fn_27_2B348C(arg0,arg1,arg2,arg3,1);
if (result != 0 && *(int*)((char*)arg3 + 0x20) <= 0) {
LocalVec2f value;
value.x = lbl_27_rodata_5EA8; value.y = lbl_27_rodata_5EAC;
applyEffect(*(Obj4C**)(*(char**)(self + 0xD8) + 0x4C), arg2, &value.x);
}
return 1;
}