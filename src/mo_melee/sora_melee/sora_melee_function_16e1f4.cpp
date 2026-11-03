#pragma force_active on
class soNullable {
public:
 virtual void isNull();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5(int, unsigned int);
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
 virtual void slot18(unsigned int);
 virtual void slot19(unsigned int);
};
struct Modules { char pad[0x64]; soNullable* work; };
struct Owner { char pad[0xd8]; Modules* modules; };
extern "C" unsigned int fn_27_193768(Owner*);
extern "C" void fn_27_16E1F4(void*, Owner* owner) {
 int kind;
 if (fn_27_193768(owner) == 1U) {
  kind = 0xaa;
  owner->modules->work->slot18(0x22000019);
 } else {
  kind = 0xb3;
  owner->modules->work->slot19(0x22000019);
 }
 owner->modules->work->slot5(kind, 0x20000008);
}