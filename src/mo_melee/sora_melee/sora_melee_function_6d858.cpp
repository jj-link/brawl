#pragma force_active on
#include <so/ground/so_ground_module_impl.h>
extern const float lbl_27_rodata_950;
namespace matching { class soNullable { public:
virtual int isNull();
virtual void* fn_27_6A3D8(int);
virtual void fn_27_6A4BC();
virtual void fn_27_6A51C();
virtual void fn_27_6A5E0();
virtual void fn_27_6A640();
virtual void fn_27_6A660();
virtual void fn_27_6A650();
virtual void fn_27_6A6DC();
virtual void fn_27_6A71C();
virtual void fn_27_6A770();
virtual void fn_27_6BC40();
virtual void fn_27_6BC94();
virtual void fn_27_6BCF8();
virtual void fn_27_6BD6C();
virtual void fn_27_6AE24();
virtual void fn_27_6B22C();
virtual void fn_27_6B66C();
virtual void fn_27_6BA10();
virtual void fn_27_6BA7C();
virtual void fn_27_6BAEC();
virtual void fn_27_6BB6C();
virtual void fn_27_6BBEC();
virtual void fn_27_6BDD0();
virtual void fn_27_6BE68();
virtual void fn_27_6BEE4();
virtual void fn_27_6BF60();
virtual void fn_27_6BFDC();
virtual void fn_27_6C084();
virtual void fn_27_6C11C();
virtual void fn_27_6C1B4();
virtual void fn_27_6C24C();
virtual void fn_27_6C2E8();
virtual void fn_27_6C384();
virtual void fn_27_6C480();
virtual void fn_27_6C514();
virtual void fn_27_6C5AC();
virtual void fn_27_6C634();
virtual void fn_27_6C6F4();
virtual void fn_27_6C748();
virtual void fn_27_6C79C();
virtual void fn_27_6C7F0();
virtual void fn_27_6C858();
virtual void fn_27_6C89C();
virtual void fn_27_6C908();
virtual void fn_27_6C960();
virtual void fn_27_6C9B8();
virtual void fn_27_6EA30();
virtual void fn_27_6CA10();
virtual void fn_27_6CA64();
virtual void fn_27_6CAB8();
virtual void fn_27_6CB10();
virtual void fn_27_6DF40();
virtual void fn_27_6DF9C();
virtual void fn_27_6DFF4();
virtual void fn_27_6CB68();
virtual void fn_27_6CBBC();
virtual void fn_27_6CC10();
virtual void fn_27_6CC64();
virtual void fn_27_6CCC8();
virtual void fn_27_6CD1C();
virtual void fn_27_6CDA4();
virtual void fn_27_6CDF8();
virtual void fn_27_6CE5C();
virtual void fn_27_6CEB0();
virtual void fn_27_6CF04();
virtual void fn_27_6CFAC();
virtual void fn_27_6D000();
virtual void fn_27_6D054();
virtual void fn_27_6D0A8();
virtual void fn_27_6D138();
virtual void fn_27_6D1E8();
virtual void fn_27_6C3D8();
virtual void fn_27_6C42C();
virtual void fn_27_6D59C();
virtual void fn_27_6D610();
virtual void fn_27_6D7A4();
virtual void fn_27_6D9C8(int, int);
virtual void fn_27_6F2F4();
virtual void fn_27_6F2EC();
virtual void fn_27_6F2DC();
virtual void fn_27_6F2D4();
virtual void fn_27_6E1AC();
virtual void fn_27_6E1B4();
virtual void fn_27_6D79C();
virtual void fn_27_6F2AC();
virtual void fn_27_6DB38();
virtual void fn_27_6D858();
virtual int fn_27_6AA2C();
}; }
struct Node { char pad[0x1c]; int field; };
struct Base8 { char pad[8]; };
struct Resource : Base8 { public:
virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
};
struct Mods { char pad[4]; Resource* resource; char pad2[8]; soGroundModule* ground; };
struct Data { char pad[0xd8]; Mods* modules; };
struct Accessor { char pad[0x44]; Data* data; };
struct Self { char pad[0x38]; int id; short a; char b; char pad2[5]; Data* data; matching::soNullable* manager; int x; int y; };
extern "C" Accessor* fn_27_6F30C(void*);
inline void reset(Self* self) { self->id=-1; self->x=-1; self->y=-1; self->a=0; self->b=0; }
inline Vec2f center(soGroundModule* g) { return g->getCenterPos(0); }
inline Vec3f make(const Vec2f& p) { return Vec3f(p.m_x,p.m_y,lbl_27_rodata_950); }
extern "C" void fn_27_6D858(Self* self, u32 mode) {
 if (((matching::soNullable*)self)->fn_27_6AA2C()) {
 void* node=self->manager->fn_27_6A3D8(self->id);
 ((matching::soNullable*)self)->fn_27_6D9C8(self->id,0);
 reset(self);
 if(mode==1) {
 if(!((matching::soNullable*)fn_27_6F30C(&((Node*)node)->field)->data->modules->ground)->isNull()) {
 Vec3f pos=make(center(fn_27_6F30C((char*)node+0x1c)->data->modules->ground));
 self->data->modules->ground->relocate((Vec2f*)&pos,0);
 }}
 self->data->modules->resource->s7();
 }
}
