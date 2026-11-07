#include <mt/mt_prng.h>
#pragma force_active on
extern "C" {
extern const unsigned char lbl_110_data_5EF0[], lbl_110_data_212C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
struct Property { int id; char flag; int value; };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual int slot4(int); virtual void slot5(int,int); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(int, Property*);
 virtual void slot16(); virtual void slot17(); virtual void slot18(int);
};
extern "C" void fn_110_1823C(void*, char* accesser) {
 char* modules = *(char**)(accesser + 0xd8);
 Object_vptr_0* work = *(Object_vptr_0**)(modules + 0x64);
 Object_vptr_0* other = *(Object_vptr_0**)(modules + 0x54);
 char* fighter = (char*)__dynamic_cast(*(void**)(accesser + 8), 0x3c, lbl_110_data_5EF0, lbl_110_data_212C, 1);
 char* params = *(char**)(fighter + 0x2980);
 int count = work->slot4(0x20000000);
 Property prop;
 prop.id = 0x841;
 prop.flag = 0;
 other->slot15(3, &prop);
 int random = randi(*(int*)(params + 0x7c));
 if ((int)((unsigned)(count + (4 - prop.value)) + 1) > random + 1 || count + 1 >= *(int*)(params + 0x80))
   work->slot18(0x22000009);
 work->slot5(count + 1, 0x20000000);
 struct SmallProperty { int id; char flag; } prop2;
 prop2.id = 0x83a;
 prop2.flag = 0;
 other->slot15(3, (Property*)&prop2);
}