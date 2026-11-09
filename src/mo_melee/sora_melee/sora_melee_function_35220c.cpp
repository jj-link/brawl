#pragma force_active on
extern "C" {
extern char lbl_27_data_8E430[], lbl_27_data_8E2B8[], lbl_27_data_C938[], lbl_27_data_2C0C0[], lbl_27_data_CBA0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_353C20(void*, void*, unsigned int, unsigned int, unsigned int, unsigned int, void*);
int fn_27_352468(void*, void*, void*, unsigned int, unsigned int, unsigned int);
}
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual Object_vptr_0* slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual int slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual unsigned int slot21(int);
};
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
 virtual void fn_27_7B274(); virtual void fn_27_7AC18(); virtual void fn_27_7AC28();
 virtual void fn_27_7AB50(); virtual void* fn_27_7B2EC();
};
struct Pd8 { Class_90D8* r; char pad[0x14]; Object_vptr_0* q; };
struct Inner8 { char pad[0x28]; void* s; };
struct Ctx { char pad0[8]; Inner8* p8; char pad1[0xcc]; Pd8* pd8; };
static inline unsigned int getKind(Ctx* ctx) {
 Object_vptr_0* y = (Object_vptr_0*)__dynamic_cast(ctx->pd8->r->fn_27_7B2EC(), 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
 return y->slot21(0x13);
}
static inline void build(void* castObj, Ctx* ctx, unsigned int v) {
 Pd8* p = ctx->pd8;
 void* s = ctx->p8->s;
 fn_27_353C20(castObj, s, v, v, 1, 1, p->q->slot2()->slot2());
}
static inline void build13(Object_vptr_0* obj, Ctx* ctx) {
 void* castObj = __dynamic_cast(obj, 0, lbl_27_data_8E430, lbl_27_data_C938, 0);
 build(castObj, ctx, getKind(ctx));
}
extern "C" int fn_27_35220C(void* self, Object_vptr_0* obj, Ctx* ctx) {
 switch (obj->slot6()) {
 case 13:
  build13(obj, ctx);
  return 1;
 case 14: {
  void* castObj = __dynamic_cast(obj, 0, lbl_27_data_8E2B8, lbl_27_data_C938, 0);
  return fn_27_352468(self, castObj, ctx, 0x1b8, getKind(ctx), 0x01160001);
 }
 default: return 0;
 }
}