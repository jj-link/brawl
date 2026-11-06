#pragma force_active on
struct Vec2 { float x, y; Vec2() {} Vec2(const Vec2& v) : x(v.x), y(v.y) {} Vec2& operator=(const Vec2& v) { float a=v.y; float b=v.x; x=b; y=a; return *this; } };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual Vec2 slot4();
};
struct Access { char pad[12]; Object_vptr_0* obj; };
struct Arg { char pad[0xd8]; Access* access; };
struct Data { unsigned char type; char pad; unsigned short flags; char pad4[12]; Vec2 a; Vec2 b; };
struct Target { char pad[0x1c]; union { unsigned char flags; struct { unsigned char high:1; unsigned char rest:7; } bits; }; char pad1d[3]; Vec2 pos; };
struct Self { Data* data; Target* target; int state; Vec2 a; Vec2 b; unsigned char type; union { unsigned char flags; struct { unsigned char high:1; unsigned char rest:7; } bits; }; };
extern "C" char lbl_27_data_157A0[], lbl_27_data_157C8[], lbl_27_data_157D8[];
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" void fn_8001133C(void*, Vec2*, Vec2*);
extern "C" void fn_80011528(void*, Vec2*, float);
extern "C" void fn_27_A6C80(Self* self, Arg* arg) {
 Vec2 pos = arg->access->obj->slot4();
 self->a = self->data->a;
 self->b = self->data->b;
 self->type = self->data->type;
 Vec2& dest = (self->target->pos = pos);
 ((Target*)((char*)&dest - 0x20))->flags |= 0x20;
 switch (self->type) {
 case 0: {
  void* p = __dynamic_cast(self->target, 0x44, lbl_27_data_157C8, lbl_27_data_157D8, 0);
  if (!p) return;
  fn_8001133C(p, &self->a, &self->b);
  break;
 }
 case 1: {
  void* p = __dynamic_cast(self->target, 0x44, lbl_27_data_157A0, lbl_27_data_157D8, 0);
  if (!p) return;
  fn_80011528(p, &self->a, self->b.x);
  break;
 }
 }
 if (self->data->flags & 8) {
  self->target->bits.high = 0;
  self->bits.high = 0;
 } else {
  self->target->flags |= 0x80;
  self->flags |= 0x80;
 }
 self->state = -1;
}