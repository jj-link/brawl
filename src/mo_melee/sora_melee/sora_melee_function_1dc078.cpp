#pragma force_active on
extern float lbl_27_rodata_27DC;
struct Vec3 { float x,y,z; };
struct Pair { unsigned long a,b; };
class soNullable {
public:
 virtual void isNull();
 virtual soNullable** slot1(int);
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5(int, Pair*, Vec3*, void*);
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual unsigned long long slot13(short*);
 unsigned char byte4, flags;
};
struct Modules { char pad[0x7c]; soNullable* field; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Object { char pad[0x14]; soNullable* array; };
extern "C" void fn_27_1DC078(Object* obj, int arg, Access* access) {
 soNullable* array = obj->array;
 soNullable* first = *array->slot1(0);
 soNullable* second = *array->slot1(1);
 if (arg == 0) {
  short id = 1;
  Pair p;
  unsigned long long value = access->modules->field->slot13(&id);
  p = *(Pair*)&value;
  Vec3 v = { lbl_27_rodata_27DC, lbl_27_rodata_27DC, lbl_27_rodata_27DC };
  first->slot5(1, &p, &v, access);
  Vec3 v2 = { lbl_27_rodata_27DC, lbl_27_rodata_27DC, lbl_27_rodata_27DC };
  struct FloatPair { float a,b; } p2 = { lbl_27_rodata_27DC, lbl_27_rodata_27DC };
  second->slot5(-1, (Pair*)&p2, &v2, access);
 }
 first->flags |= 0x80;
 second->flags |= 0x80;
}