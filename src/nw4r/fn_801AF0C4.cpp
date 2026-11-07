#pragma force_active on
extern "C" {
extern unsigned char lbl_8040A9D0[], lbl_8040A918[], lbl_8040A940[], lbl_8040A970[], lbl_8040A9A0[];
}
class Class_80466388;
class Object_vptr_0 {
public:
 virtual int slot0(unsigned char**);
 virtual void slot1(unsigned int, int, Class_80466388*);
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
 void* parent;
};
class Class_80466388 {
public:
 virtual void fn_801AFEB4();
 virtual void fn_801AE668();
 virtual void fn_801AFD90();
 virtual void fn_8007FDF4();
 virtual void fn_801AFF1C();
 virtual void fn_801AB1C4();
 virtual void fn_801AEEF8();
 virtual void fn_801AEF40();
 virtual void fn_801AAFDC();
 virtual void fn_801AAFE8();
 virtual void fn_801AB290();
 virtual void fn_801AF0C4();
 virtual void fn_801AF6C0(Object_vptr_0*);
 char pad[0x120];
 Object_vptr_0* a;
 Object_vptr_0* b;
 Object_vptr_0* c;
 Object_vptr_0* d;
 Object_vptr_0* e;
};
extern "C" unsigned int fn_8019DA84(Object_vptr_0*, unsigned int);
#define CAST(dst, sym) { bool ok = false; if (obj) { unsigned char* t = sym; if (obj->slot0(&t)) ok = true; } if (ok) dst = obj; else dst = 0; }
extern "C" int fn_801AF0C4(Class_80466388* self, Object_vptr_0* obj, unsigned int kind) {
 Object_vptr_0* p;
 if (!obj || obj->parent) return 0;
 switch (kind) {
 case 0: CAST(p,lbl_8040A9D0); if (p) goto chr; break;
 case 1: CAST(p,lbl_8040A918); if (p) goto vis; break;
 case 2: CAST(p,lbl_8040A940); if (p) goto clr; break;
 case 3: CAST(p,lbl_8040A970); if (p) goto pat; break;
 case 4: CAST(p,lbl_8040A9A0); obj = p; if (obj) goto srt; break;
 case 6:
  CAST(p,lbl_8040A9D0); if (p) goto chr;
  CAST(p,lbl_8040A918); if (p) goto vis;
  CAST(p,lbl_8040A940); if (p) goto clr;
  CAST(p,lbl_8040A970); if (p) goto pat;
  CAST(p,lbl_8040A9A0); obj = p; if (obj) goto srt;
  break;
 }
 return 0;
chr:
 if (!fn_8019DA84(p,4)) return 0;
 if (self->a) self->fn_801AF6C0(self->a);
 self->a=p; p->slot1(0x10002,0,self); return 1;
vis:
 if (!fn_8019DA84(p,4)) return 0;
 if (self->b) self->fn_801AF6C0(self->b);
 self->b=p; p->slot1(0x10002,0,self); return 1;
clr:
 if (!fn_8019DA84(p,4)) return 0;
 if (self->c) self->fn_801AF6C0(self->c);
 self->c=p; p->slot1(0x10002,0,self); return 1;
pat:
 if (!fn_8019DA84(p,4)) return 0;
 if (self->d) self->fn_801AF6C0(self->d);
 self->d=p; p->slot1(0x10002,0,self); return 1;
srt:
 if (!fn_8019DA84(obj,4)) return 0;
 if (self->e) self->fn_801AF6C0(self->e);
 self->e=obj; obj->slot1(0x10002,0,self); return 1;
}