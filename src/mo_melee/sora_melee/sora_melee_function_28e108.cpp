#pragma force_active on
struct Vec { float x, y; };
class Object_vptr_0 {
public:
#define V(n) virtual void slot##n();
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
virtual int slot16();
#undef V
};
struct Object_vptr_4_base { char pad[4]; };
class Object_vptr_4 : public Object_vptr_4_base {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(void*, int, int);
};
class A {
public:
#define V(n) virtual void v##n();
 V(0) V(1) V(2) V(3) V(4)
 virtual void v5(int,int);
 V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16)
 virtual int v17(int); virtual void v18(int);
#undef V
};
class B { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(int,void*); };
class C { public: virtual void v0(); virtual void v1(); virtual unsigned int* v2(int); };
class D {
public:
#define V(n) virtual void v##n();
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
 V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
 V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
 V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40)
 virtual void v41(Vec*); V(42) V(43) V(44) V(45) V(46) V(47)
#undef V
};
extern "C" { extern Object_vptr_4 lbl_27_bss_71C8; void fn_27_28DEE0(void*); }
extern "C" void fn_27_28E108(void* object, Vec* arg) {
 unsigned char* self = (unsigned char*)object;
 fn_27_28DEE0(object);
 Vec pos; pos.x = arg->x; pos.y = arg->y;
 ((A*)(self + 0x2aac))->v5(0, 0x1000001c);
 ((B*)(self + 0x2c34))->v3(5, self + 0xcc);
 if ((*(Object_vptr_0**)(*(unsigned char**)(self + 0x1a4) + 0x70))->slot16() == 5) {
  ((A*)(self + 0x2aac))->v18(0x22000000);
  if (((A*)(self + 0x2aac))->v17(0x22000000) && !(*((C*)(self + 0x297c))->v2(8) & 0x4c00)) {
   float y = pos.y; float x = pos.x; Vec copy; copy.x = x; copy.y = y;
   ((D*)(self + 0x15c0))->v41(&copy);
   ((Object_vptr_4*)&lbl_27_bss_71C8)->slot5(self + 0xcc, 0xd6f, 0);
   ((D*)(self + 0x15c0))->v45();
   ((Object_vptr_4*)&lbl_27_bss_71C8)->slot5(self + 0xcc, 0xd70, 0);
   ((D*)(self + 0x15c0))->v47();
  }
 }
}