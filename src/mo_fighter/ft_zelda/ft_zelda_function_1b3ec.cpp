#pragma force_active on
class Object_vptr_0 { public:
virtual void fn_104_7930(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(int,int); virtual void slot5(); virtual void slot6(); virtual void slot7();
virtual void slot8(); virtual float slot9(void*); virtual void slot10(); virtual void slot11();
virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual int slot16(); };
class Obj18Chain { public: virtual void a0(); virtual void a1(); virtual Obj18Chain* a2(); };
class Obj0Result { public:
virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7();
virtual void c8(); virtual void c9(); virtual void c10(); virtual void c11(); virtual void c12(); virtual void c13(); virtual void c14(); virtual int c15(); };
class Obj0 { int pad0[2]; public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual Obj0Result* d4(); };
struct Data { Obj0* obj0; char p4[8]; Object_vptr_0* objc; char p10[8]; Obj18Chain* obj18; char p1c[0x38]; Object_vptr_0* obj54; char p58[0x18]; Object_vptr_0* obj70; };
struct Context { char p0[8]; void* ctx8; char pc[0xCC]; Data* data; };
struct Context8 { char pad[0x28]; int value; };
struct Self { char pad[0x28]; int value; };
extern "C" void fn_104_23F80(void*, int, int, void*, float, unsigned int);
extern "C" int fn_104_1B3EC(void* self, Context* ctx) {
int arg5; Obj18Chain* result; float f; Obj0* obj0; int value; Obj18Chain* chain; int flag;
flag = ctx->data->obj70->slot16() == 0x10C;
chain = ctx->data->obj18;
obj0 = ctx->data->obj0;
value = ((Context8*)ctx->ctx8)->value;
f = ctx->data->objc->slot9(ctx->data);
result = chain->a2()->a2();
arg5 = obj0->d4()->c15();
fn_104_23F80(self, value, arg5, result, f, flag);
ctx->data->obj54->slot4(6, ((Self*)self)->value);
return 1;
}