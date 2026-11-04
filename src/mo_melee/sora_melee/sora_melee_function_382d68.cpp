
#pragma force_active on
typedef unsigned int u32;
#define V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
#define V32(p) V8(p##0) V8(p##1) V8(p##2) V8(p##3)
struct Base { char pad[0x3c]; };
struct Status : Base {
 V32(a) V8(b)
 virtual int getKind();
};
struct Start : Base {
 V32(a) V32(b) V32(c) V32(d) V32(e)
 V8(f0) V8(f1) V8(f2)
 virtual void f184();
 virtual void** get();
};
struct Work {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual int getInt(u32); virtual void setInt(int,u32);
 virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual float getFloat(u32); virtual void setFloat(float,u32);
 virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
 virtual void onFlag(u32); virtual void offFlag(u32);
};
struct Article {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void generate(int,int); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void remove(int); virtual unsigned exists(int); virtual void s10(); virtual Status* get(int);
 V32(a) V32(b) V8(c) V8(d)
 virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3(); virtual void e4(); virtual void e5(); virtual void e6();
 virtual void change(int,int,bool);
};
struct Motion {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
 virtual void change(int,int,int,int);
};
struct Modules { char pad[0x50]; Motion* motion; Article* article; char pad58[0xc]; Work* work; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Anims { int a,b,c; };
struct Entry { Anims* anim; int pad; };
struct Table { Entry* entries; };
struct Params { char pad[0x84]; Table* table; float* limits; };
struct Self : Base {
 V32(a) V32(b) V32(c) V32(d) V32(e)
 V8(f0) V8(f1) V8(f2)
 virtual void f184();
 virtual void** get();
 char pad40[0x20];
 Access* access;
 char pad64[0xa8];
 int id;
 char pad110[0x7e8c];
 Params* params;
};
extern "C" float fn_27_1D53A0(void*,int,int);
extern "C" float fn_27_10C8CC(void*,int);
extern "C" void* g_ftManager;
extern "C" float lbl_27_rodata_7C2C;
extern "C" float lbl_27_rodata_7C30;
extern "C" void fn_27_382D68(Self* self, int kind) {
 Access* acc = self->access;
 float value = fn_27_1D53A0((char*)*self->get()+0x9e8,2,0);
 int old = acc->modules->work->getInt(0x10000040);
 acc->modules->work->onFlag(0x1200003e);
 if (acc->modules->article->exists(6)==1) acc->modules->article->remove(6);
 acc->modules->article->generate(6,kind);
 acc->modules->article->change(6,4,true);
 acc->modules->article->change(6,13,true);
 switch(acc->modules->article->get(6)->getKind()) {
 case 29: kind=0; break;
 case 30: kind=1; break;
 case 31: kind=2; break;
 }
 acc->modules->work->setInt(kind,0x10000049);
 switch (old) {
 case 0: case 6: case 7: case 8: {
  float delta=value-acc->modules->work->getFloat(0x11000021);
  float damage=fn_27_10C8CC(g_ftManager,self->id);
  if (damage < lbl_27_rodata_7C2C || self->params->limits[1]>delta) {
   acc->modules->motion->change(self->params->table->entries[kind].anim->a,0,0,0);
  } else if (damage < lbl_27_rodata_7C30 || self->params->limits[0]>delta) {
   acc->modules->motion->change(self->params->table->entries[kind].anim->b,0,0,0);
  } else {
   acc->modules->motion->change(self->params->table->entries[kind].anim->c,0,0,0);
  }
 break;
 }
 }
 acc->modules->work->setFloat(value,0x11000021);
 acc->modules->work->offFlag(0x1200003d);
}
