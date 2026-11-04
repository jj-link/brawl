#pragma force_active on
struct Item { char pad[10]; short unkA; };
struct Property { int b[3]; };
struct Sub {
 virtual void v00(); virtual void v04(); virtual Item* v10(int);
 virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30();
 virtual void v34(int, Property*);
 virtual void v38(); virtual void v3c(); virtual unsigned int v40();
};
struct Obj {
 virtual void v00(); virtual void v04(); virtual void v10(); virtual void v14(); virtual int count(); virtual void v1c(); virtual unsigned int test(int);
 char pad4[12]; Sub sub; char pad14[0x38]; unsigned char flag;
 inline int find(int b) {
  if (b <= -1) return count();
  int n = count();
  for (int i = 0; i < n; i++) {
   int v = sub.v10(i)->unkA;
   if (v <= -1) return i;
   if (v > b) return i;
  }
  return n;
 }
};
extern "C" int fn_27_1CADC0(Obj*);
extern "C" void fn_27_FDF94(Property*, int*, int, const short*, int);
extern "C" int fn_27_1CA5B8(Obj* self, int* a1, int a2, short* a3, int a4) {
 if (self->sub.v40() == 1U) return -1;
 if ((self->flag == 0 || a2 > -1) && self->test(a2) == 1U) return -1;
 if (self->flag == 0 && a2 <= -1) {
  a2 = fn_27_1CADC0(self);
  if (a2 <= -1) return -1;
 }
 int idx = self->find(a4);
 if (idx < 0) return -1;
 short t = *a3;
 Property p;
 fn_27_FDF94(&p, a1, a2, &t, a4);
 self->sub.v34(idx, &p);
 return a2;
}