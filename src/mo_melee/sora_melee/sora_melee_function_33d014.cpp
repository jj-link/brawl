#pragma force_active on
struct soNullable {
 virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3(int,int,int);
 virtual int slot4(int); virtual void slot5(int,int);
 virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13();
 virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17();
 virtual void slot18(int);
};
struct gfTask_base { char pad[0x3c]; };
struct gfTask : gfTask_base {
#define SLOT(n) virtual void slot##n();
 SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7)
 SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15)
 SLOT(16) SLOT(17) SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
 SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29) SLOT(30) SLOT(31)
 SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38)
 virtual int fn_27_248088();
 virtual int slot40();
#undef SLOT
};
struct Container { char pad[0x64]; soNullable* a; char pad2[0x1c]; soNullable* b; };
struct Arg { char pad[8]; gfTask* obj; char pad2[0xcc]; Container* container; };
extern "C" int fn_27_33D014(void*, Arg* arg) {
 int first = arg->obj->fn_27_248088();
 int kind = arg->obj->slot40();
 if (first != 0) return 0;
 if (kind != 14 && kind != 5) return 0;
 soNullable* a = arg->container->a;
 soNullable* b = arg->container->b;
 int count = a->slot4(0x10000040);
 a->slot18(0x22000012);
 int value = 0;
 if (kind == 14) value = 0;
 else if (kind == 5) value = 13;
 for (int i = 0; i < count; ++i) b->slot3(value, 0, 0);
 a->slot5(0, 0x10000040);
 return 0;
}