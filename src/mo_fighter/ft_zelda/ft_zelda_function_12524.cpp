#pragma force_active on
struct Vec { float x,y,z; Vec(); Vec(const Vec&); };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual Vec slot4();
 virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual float slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12();
};
class Work {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual int slot4(int);
 virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual float slot12(int);
};
struct Modules { char pad[0xc]; Object_vptr_0* pos; char pad10[0x54]; Work* work; };
struct Sub { char pad[0x28]; void* p; };
struct Context { char pad[8]; Sub* sub; char padc[0xcc]; Modules* modules; };
extern "C" void fn_104_15470(void*, void*, int, float, Vec*, float);
extern "C" int fn_104_12524(void* self, Context* ctx) {
 void* p;
 Object_vptr_0* pos;
 Work* work;
 float f2;
 float f;
 Modules* modules = ctx->modules;
 pos = modules->pos;
 work = modules->work;
 p = ctx->sub->p;
 f = work->slot12(0x21000001);
 Vec v = pos->slot4();
 f2 = pos->slot9();
 fn_104_15470(self, p, work->slot4(0x20000001), f2, &v, f);
 return 0;
}