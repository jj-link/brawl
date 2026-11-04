#pragma force_active on
struct Vec2f { float x,y; };
struct Vec3 { float x,y,z; Vec3() {} Vec3(const Vec3& v): x(v.x), y(v.y), z(v.z) {} };
struct ObjectC {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual Vec3 getPos();
 virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8();
 virtual float f11();
 virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
 virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
 virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
 virtual float f24();
};
struct Object64 {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
 virtual void f12(); virtual void f15(float,int);
};
extern "C" void fn_27_13138C(void*,int,int,void*,void*);
extern "C" void fn_123_90FC(Vec2f*,const Vec2f*);
extern "C" const float lbl_123_rodata_8;
struct VTableObject { void** vtable; };
struct Result {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void* resource();
};
struct Object54 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual int check(int,void*);
};
struct Object84 {
 virtual void v0(); virtual void v1(); virtual void v2();
 virtual Result* get(int,bool,bool);
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
 virtual void remove(Result*);
 virtual void v14(); virtual void v15();
 virtual void set(int,int);
};
struct D8 {
 char pad0[0x0c]; VTableObject* objectC;
 char pad1[0x54-0x10]; Object54* object54;
 char pad2[0x64-0x58]; VTableObject* object64;
 char pad3[0x84-0x68]; Object84* object84;
};
struct Outer { char pad0[0x60]; Outer* child60; char pad1[0xd8-0x64]; D8* d8; };
extern "C" void fn_123_8EEC(Outer* arg0,int arg1,void* arg2,void* arg3,Outer* arg4) {
 fn_27_13138C(arg0,arg1,(int)arg2,arg3,arg4);
 if (arg1 == 0x114) {
  Vec3 position = ((ObjectC*)arg4->d8->objectC)->getPos();
  Vec2f offset;
  fn_123_90FC(&offset,(Vec2f*)&position);
  void* scale = *(void**)((char*)*(void**)((char*)*(void**)((char*)arg0+0xd5d4)+0x94)+0x34);
  float directionValue = ((ObjectC*)arg4->d8->objectC)->f11();
  int direction = directionValue < lbl_123_rodata_8 ? -1 : 1;
  float signedDirection = (float)direction;
  offset.x += *(float*)((char*)scale+4)*signedDirection;
  float delta = ((ObjectC*)arg4->d8->objectC)->f24();
  offset.y += *(float*)((char*)scale+8)*delta;
  ((Object64*)arg4->d8->object64)->f15(offset.x,0x21000004);
  ((Object64*)arg4->d8->object64)->f15(offset.y,0x21000005);
 } else if (arg1 == 0x116) {
  arg0->child60->d8->object84->set(1,0);
  Object54* object54;
  Result* result = arg0->child60->d8->object84->get(1,0,0);
  object54 = arg0->child60->d8->object54;
  void* resource = result->resource();
  if (object54->check(6,resource) != 0) {
   arg0->child60->d8->object84->remove(result);
  }
 }
}