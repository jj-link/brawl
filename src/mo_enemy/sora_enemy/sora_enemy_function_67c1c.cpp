#pragma force_active on
class soNullable {
public:
 virtual void isNull();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5(int);
 virtual int slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual int slot16();
 virtual void slot17();
 virtual void slot18();
};
class Class_6E20 {
public:
 virtual void fn_41_3516C();
 virtual void fn_41_34F30();
 virtual void fn_41_350A4();
 virtual void fn_41_350AC();
 virtual void fn_41_350B4();
 virtual void fn_41_350BC();
 virtual void fn_41_350DC();
 virtual void fn_41_350C4();
 virtual void fn_41_35120();
 virtual void fn_41_350CC(int,int);
 virtual void fn_41_350D4();
 virtual void fn_41_350E4();
 virtual void fn_41_350EC();
 virtual void fn_41_350F0();
 virtual void fn_41_350F4(int);
 virtual void fn_41_350F8();
 virtual void fn_41_350FC();
 virtual void fn_41_35108();
 virtual void fn_41_3510C();
};
struct VarModule {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
 virtual void setInt(int,int);
 virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
 virtual void onFlag(int);
};
struct StatusModule {
 virtual void v0(); virtual void v1(); virtual void v2();
 virtual void change(int, void*);
};
struct Base39 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
 virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
 virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
 virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
 virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
 virtual void v35(); virtual void v36();
};
struct Pad38 { char pad[0x38]; };
struct Object : Pad38, Base39 { virtual int v39(); };
struct ModuleSet {
 char pad0[0x30]; soNullable* m30; char pad1[8]; soNullable* m3c;
 char pad2[0x30]; soNullable* m70;
};
struct EnumStart {
 char pad0[0x3c]; Class_6E20* m3c; char pad1[0x24]; VarModule* m64;
 char pad2[8]; StatusModule* m70;
};
struct Accesser { char pad[0xd8]; EnumStart* mD8; };
struct Fighter { char pad0[0x60]; Accesser* m60; char pad1[0x150]; ModuleSet* m1b4; };
struct Event { int kind; unsigned char b4,b5; char pad0[2]; int value; char pad1[0x10]; unsigned char b1c; };
extern "C" void fn_41_B8D4(void*,void*,void*,void*,void*);
extern "C" void fn_41_67C1C(Fighter* self, Event* event, void* arg2, Object* object, void* arg4) {
 switch (event->kind) {
 case 8:
  if (self->m1b4->m70->slot16() == 0x2a && self->m1b4->m3c->slot6() == 0 && object->v39() == 0) {
   self->m1b4->m30->slot4();
   event->b4 = 1;
   event->b1c = 1;
   event->value = 5;
   self->m1b4->m3c->slot5(-1);
   self->m60->mD8->m64->setInt(*(int*)((char*)object + 0x28), 0x10000018);
   self->m60->mD8->m64->setInt(0, 0x10000019);
   self->m60->mD8->m64->setInt(0, 0x1000001a);
   self->m60->mD8->m64->onFlag(0x1200000b);
   return;
  }
  break;
 case 14:
  if (self->m1b4->m70->slot16() == 0x2d || self->m1b4->m70->slot16() == 0x2e) {
   int value = event->b5;
   self->m60->mD8->m3c->fn_41_350F4(0);
   self->m60->mD8->m3c->fn_41_350CC(1,0);
   if (!value) self->m60->mD8->m70->change(0x30,self->m60);
   return;
  }
  break;
 case 9:
  if (self->m1b4->m70->slot16() == 0x2b || self->m1b4->m70->slot16() == 0x2c ||
      self->m1b4->m70->slot16() == 0x2d || self->m1b4->m70->slot16() == 0x2e) {
   self->m60->mD8->m3c->fn_41_350F4(0);
   self->m60->mD8->m3c->fn_41_350CC(1,0);
   self->m60->mD8->m70->change(0x30,self->m60);
   return;
  }
  break;
 }
 fn_41_B8D4(self,event,arg2,object,arg4);
}