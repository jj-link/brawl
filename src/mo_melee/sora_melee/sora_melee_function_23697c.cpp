#pragma force_active on
struct Pair { float x, y; };
struct Class_4C338_base { unsigned int first; };
class Class_4C338 : public Class_4C338_base {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void* slot2();
 virtual void slot3(void*);
 void* arg;
 unsigned char flag;
 char pad[0x2f];
 unsigned int result;
};
struct Obj1C { char pad[0x1c]; unsigned char b7 : 1; };
struct Trig { unsigned int u0; void* u4; unsigned int u8; unsigned char uC; void* u10; };
struct Trig2 { unsigned int u0; void* u4; unsigned int u8; bool uC; void* u10; };
struct Param {
 char pad0[4];
 int type;
 char pad8[0x20];
 unsigned char b28;
 unsigned char b29;
 unsigned short h2a;
 unsigned short h2c;
 unsigned char b2e;
};
struct Req { int a; short b; float c; unsigned short d; };

extern "C" {
extern char lbl_27_data_4C338[];
extern char lbl_27_data_4C498[];
extern const float lbl_27_rodata_38F0;
extern void* lbl_27_bss_5780;
extern void* g_stTriggerMng;
void fn_27_234DDC(void*, void*, void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
unsigned int fn_27_22AF90(void*, void*);
void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(void*, int, void*);
void fn_27_233F58(void*, void*);
void fn_27_233FCC(void*, void*);
}

extern "C" Class_4C338* fn_27_23697C(Class_4C338* self, void* arg1, Param* p) {
 Pair copy;
 Pair tmp;
 self->first = 0;
 self->arg = arg1;
 tmp.x = lbl_27_rodata_38F0;
 tmp.y = lbl_27_rodata_38F0;
 self->flag = 0;
 *(void**)((char*)self + 4) = lbl_27_data_4C338;
 p->type = 0x19;
 ((unsigned int*)&copy)[0] = ((unsigned int*)&tmp)[0];
 ((unsigned int*)&copy)[1] = ((unsigned int*)&tmp)[1];
 fn_27_234DDC(self, p, &copy);
 if (p->h2c != 0) {
  Trig* n1;
  int var_r28;
  void* r27 = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(g_stTriggerMng, 0, &p->h2c);
  if (p->b2e & 1) {
   var_r28 = 1;
   Obj1C* t = (Obj1C*)self->slot2();
   t->b7 = 0;
  } else {
   var_r28 = 0;
  }
  n1 = (Trig*)__nw__FUlQ25Heaps8HeapType(0x14, 0xF);
  if (n1 != 0) {
   void* v = self->slot2();
   n1->u0 = 0;
   n1->u8 = 0;
   n1->u4 = lbl_27_data_4C498;
   n1->uC = var_r28;
   n1->u10 = v;
  }
  fn_27_233F58(r27, n1);
  Trig2* n2 = (Trig2*)__nw__FUlQ25Heaps8HeapType(0x14, 0xF);
  if (n2 != 0) {
   void* v = self->slot2();
   n2->u0 = 0;
   n2->u8 = 0;
   n2->u4 = lbl_27_data_4C498;
   n2->uC = var_r28 == 0;
   n2->u10 = v;
  }
  fn_27_233FCC(r27, n2);
 }
 Req sp18;
 sp18.b = 0x12;
 if (p->b29 == 0) {
  sp18.c = (float)p->b28;
 } else {
  sp18.c = (float)(-(int)p->b28);
 }
 sp18.d = p->h2a;
 self->slot3(&sp18);
 if (lbl_27_bss_5780 == 0) {
  void* mgr = __nw__FUlQ25Heaps8HeapType(0x54, 2);
  if (mgr != 0) mgr = fn_27_22A914(mgr);
  lbl_27_bss_5780 = mgr;
 }
 self->result = fn_27_22AF90(lbl_27_bss_5780, &sp18);
 return self;
}
