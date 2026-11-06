#pragma force_active on
class Object;
class soNullable {
public:
 virtual void isNull();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3(int, Object*);
 virtual int slot4(unsigned int);
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
 virtual bool slot17(unsigned int);
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26(int);
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
 virtual void slot47();
 virtual void slot48();
 virtual void slot49();
 virtual void slot50();
 virtual float slot51(int);
};
struct Modules {
 char pad0[0x20];
 soNullable* m20;
 char pad24[0x1c];
 soNullable* m40;
 char pad44[0x18];
 soNullable* m5c;
 char pad60[4];
 soNullable* m64;
 char pad68[8];
 soNullable* m70;
};
class Object {
public:
 char pad[0xd8];
 Modules* modules;
};
extern float lbl_27_rodata_2490;
extern "C" void fn_27_184C90(void*, Object* obj) {
 obj->modules->m40->slot15();
 if (!obj->modules->m64->slot17(0x22000011) &&
     obj->modules->m5c->slot51(0) <= lbl_27_rodata_2490) {
   obj->modules->m20->slot26(0);
   if (obj->modules->m64->slot4(0x20000001) == 0x20 ||
       obj->modules->m64->slot17(0x22000013)) {
     obj->modules->m70->slot3(0xd5, obj);
   } else {
     obj->modules->m70->slot3(0x40, obj);
   }
 }
}