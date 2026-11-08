#pragma force_active on
struct StageObjBase { unsigned char pad[0x3c]; };
class StageObj : public StageObjBase {
public:
virtual void m1();
virtual void m2();
virtual void m3();
virtual void m4();
virtual void m5();
virtual void m6();
virtual void m7();
virtual void m8();
virtual void m9();
virtual void m10();
virtual void m11();
virtual void m12();
virtual void m13();
virtual void m14();
virtual void m15();
virtual void m16();
virtual void m17();
virtual void m18();
virtual void m19();
virtual void m20();
virtual void m21();
virtual void m22();
virtual void m23();
virtual void m24();
virtual void m25();
virtual void m26();
virtual void m27();
virtual void m28();
virtual void m29();
virtual void m30();
virtual void m31();
virtual void m32();
virtual void m33();
virtual void m34();
virtual void m35();
virtual void m36();
virtual void m37();
virtual void m38();
virtual void m39();
virtual int linkKind();
virtual int statusKind();
virtual void a0();
virtual void a1();
virtual void a2();
virtual void a3();
virtual void a4();
virtual void a5();
virtual void a6();
virtual void a7();
virtual void a8();
virtual void a9();
virtual void a10();
virtual void a11();
virtual void a12();
virtual void a13();
virtual void a14();
virtual void a15();
virtual void a16();
virtual void a17();
virtual void a18();
virtual void a19();
virtual void a20();
virtual void a21();
virtual void a22();
virtual void a23();
virtual void a24();
virtual void a25();
virtual void a26();
virtual void a27();
virtual void a28();
virtual void a29();
virtual void a30();
virtual void a31();
virtual void a32();
virtual void a33();
virtual void a34();
virtual void a35();
virtual void a36();
virtual void a37();
virtual void a38();
virtual void a39();
virtual void a40();
virtual void a41();
virtual void a42();
virtual void a43();
virtual void a44();
virtual void a45();
virtual void a46();
virtual void a47();
virtual void a48();
virtual void a49();
virtual void a50();
virtual void a51();
virtual void a52();
virtual void a53();
virtual void a54();
virtual void a55();
virtual void a56();
virtual void a57();
virtual void a58();
virtual void a59();
virtual void a60();
virtual void a61();
virtual void a62();
virtual void a63();
virtual void a64();
virtual void a65();
virtual void a66();
virtual void a67();
virtual void a68();
virtual void a69();
virtual void a70();
virtual void a71();
virtual void a72();
virtual void a73();
virtual void a74();
virtual void a75();
virtual void a76();
virtual void a77();
virtual void a78();
virtual void a79();
virtual void a80();
virtual void a81();
virtual void a82();
virtual void a83();
virtual void a84();
virtual void a85();
virtual void a86();
virtual void a87();
virtual void a88();
virtual void a89();
virtual void a90();
virtual void a91();
virtual void a92();
virtual void a93();
virtual void a94();
virtual void a95();
virtual void a96();
virtual void reset(int);
};
class Object_vptr_0 {
public:
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
virtual void slot18(unsigned int);
};
class KindSetter {
public:
virtual void s0();
virtual void s1();
virtual void s2();
virtual void s3();
virtual void s4();
virtual void s5();
virtual void s6();
virtual void s7();
virtual void s8();
virtual void s9();
virtual void s10();
virtual void s11();
virtual void s12();
virtual void s13();
virtual void s14();
virtual void setLinkEvent(int, void*);
};
struct Modules { unsigned char pad[0x54]; KindSetter* kindSetter; unsigned char gap[0xc]; Object_vptr_0* kindGetter; };
struct Accesser { unsigned char pad[0xd8]; Modules* modules; };
struct Event { int eventKind; int pad; StageObj* child; };
extern "C" void fn_27_1DB0F0(void*, void*, void*, void*, int);
extern "C" void fn_27_317D84(StageObj* self, Event* event, Accesser* accesser, StageObj* sender, int link) {
 Object_vptr_0* getter = accesser->modules->kindGetter;
 if (sender->linkKind() == 0) {
  int kind = sender->statusKind();
  switch (kind) {
  case 6: case 0x13: case 0x2c:
   switch (event->eventKind) {
   case 0x456: getter->slot18(0x22000001); return;
   case 0x457: getter->slot18(0x22000002); return;
   case 0x458: getter->slot18(0x22000003); return;
   case 0x459: getter->slot18(0x22000004); return;
   case 0: case 2: case 4: self->reset(0); goto common;
   }
  }
 } else { switch (event->eventKind) { case 0x3e:
  StageObj* child = event->child;
  int childKind = child->statusKind();
  switch (childKind) {
  case 0xf: case 5:
   accesser->modules->kindSetter->setLinkEvent(3, event);
   break;
  }
 } }
common:
 fn_27_1DB0F0(self, event, accesser, sender, link);
}