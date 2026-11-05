#pragma force_active on
#define V(n) virtual void v##n();
#define V10(n) V(n##0) V(n##1) V(n##2) V(n##3) V(n##4) V(n##5) V(n##6) V(n##7) V(n##8) V(n##9)
struct Vec3f { float x,y,z; };
struct Work {
 V(0) V(1) V(2) V(3) V(4)
 virtual void setInt(int,int);
 V(6) V(7) V(8) V(9) V(10) V(11) V(12)
 virtual void setFloat(float,int);
 V(14) V(15) V(16) V(17) V(18) V(19)
 virtual void setFlag(bool,int);
};
struct Effect {
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10)
 virtual int make(int,int,Vec3f*,Vec3f*,float,bool,int,int,int);
 V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
 V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
 V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38)
 virtual void end(int);
};
struct Modules { char p[0x64]; Work* work; char q[0x20]; Effect* effect; };
struct Access { char p[0xd8]; Modules* modules; };
struct Base { char p[0x3c]; };
struct Object : Base {
 V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7) V10(8) V10(9)
 V10(10) V10(11) V10(12) V10(13) V10(14) V10(15) V10(16) V10(17)
 V(180) V(181) V(182) V(183) V(184)
 virtual void* get();
 char p2[0x20]; Access* access;
};
extern "C" float fn_118_95F0(Access*);
extern "C" float fn_118_8EE4(Object*);
extern "C" void fn_118_8FA0(Object*,float);
extern "C" void fn_27_12BAF8(Object*,int);
extern "C" void* fn_118_8E00();
extern "C" void fn_27_39AB00(void*,Access*);
extern "C" int fn_27_111E30(void*);
extern "C" Vec3f* fn_118_8DF0(Vec3f*,float,float,float);
extern "C" const float lbl_118_rodata_C;
extern "C" void fn_118_8B3C(Object* self, int arg) {
 Access* a = self->access;
 Work* w = a->modules->work;
 float f = fn_118_95F0(a);
 w->setFloat(f,0x11000013);
 w->setFloat(f,0x11000014);
 fn_118_8FA0(self,fn_118_8EE4(self));
 fn_27_12BAF8(self,arg);
 fn_27_39AB00(fn_118_8E00(),a);
 if (fn_27_111E30(self->get())) {
  self->access->modules->work->setInt(0,0x10000047);
  self->access->modules->work->setInt(0,0x10000048);
 } else {
  Effect* e = self->access->modules->effect;
  float scale = fn_118_8EE4(self);
  Vec3f b1,a1,b2,a2;
  int id1 = e->make(0x220001,0x1f,fn_118_8DF0(&b1,lbl_118_rodata_C,lbl_118_rodata_C,lbl_118_rodata_C),fn_118_8DF0(&a1,lbl_118_rodata_C,lbl_118_rodata_C,lbl_118_rodata_C),scale,1,0x10,0,-1);
  int id2 = e->make(0x220001,0x35,fn_118_8DF0(&b2,lbl_118_rodata_C,lbl_118_rodata_C,lbl_118_rodata_C),fn_118_8DF0(&a2,lbl_118_rodata_C,lbl_118_rodata_C,lbl_118_rodata_C),scale,1,0x10,0,-1);
  self->access->modules->work->setInt(id1,0x10000047);
  self->access->modules->work->setInt(id2,0x10000048);
 }
 self->access->modules->effect->end(0x1a);
 self->access->modules->work->setFlag(true,0x1200003f);
}