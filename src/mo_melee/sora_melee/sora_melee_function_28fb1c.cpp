#pragma force_active on
struct Class_2C0_base { char pad[4]; };
class Class_2C0 : public Class_2C0_base {
public:
 virtual void fn_27_5378();
 virtual void fn_27_6CA4();
 virtual void fn_27_6C80();
 virtual void fn_27_6C5C();
 virtual void fn_27_6C54();
 virtual void fn_27_6C34();
 virtual int fn_27_6C18(void*, int, int);
};
class soNullable {
public:
 virtual void isNull();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual int slot9(int);
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual int slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual float slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual float slot32();
};
extern int lbl_27_bss_71C8;
extern const float lbl_27_rodata_461C;
extern "C" float fn_27_28FB1C(char* self) {
 if (((Class_2C0*)&lbl_27_bss_71C8)->fn_27_6C18(self + 0xcc, 0x5b6d, 0) == 1) {
  int r;
  if ((*(soNullable**)(*(char**)(self + 0x1a4) + 0x70))->slot16() == 2)
   r = 1;
  else
   r = ((soNullable*)(self + 0x27a8))->slot9(3);
  if (r)
   return ((soNullable*)(self + 0x27a8))->slot32();
  return ((soNullable*)(self + 0xdb4))->slot25();
 }
 return lbl_27_rodata_461C;
}