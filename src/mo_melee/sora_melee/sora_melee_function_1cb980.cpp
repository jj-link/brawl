#pragma force_active on
struct Data { int a; int b; short c; short d; };
struct Inner {
 virtual void v0(); virtual void v1(); virtual char* get(int);
 virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
 virtual void set(int, Data*);
 virtual void v12(); virtual void v13(); virtual unsigned int full();
};
struct Outer {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual int count(); virtual void v5(); virtual unsigned int bad(int);
 char pad0[12]; Inner inner; char pad[0x4c-0x14]; unsigned char flag;
 inline int find(int b) {
  if (b <= -1) return count();
  int n = count();
  for (int i = 0; i < n; i++) {
   int v = *(short*)(inner.get(i)+0xa);
   if (v <= -1) return i;
   if (v > b) return i;
  }
  return n;
 }
};
extern "C" int fn_27_1CC188(Outer*);
extern "C" void fn_27_FE0D4(Data*, int*, int, short*, int);
extern "C" int fn_27_1CB980(Outer* self, int* e, int a, short* s, int b) {
 if (self->inner.full() == 1U) return -1;
 if ((self->flag == 0 || a > -1) && self->bad(a) == 1U) return -1;
 if (self->flag == 0 && a <= -1) {
  a = fn_27_1CC188(self);
  if (a <= -1) return -1;
 }
 int idx = self->find(b);
 if (idx < 0) return -1;
 short t = *s;
 Data p;
 fn_27_FE0D4(&p, e, a, &t, b);
 self->inner.set(idx, &p);
 return a;
}