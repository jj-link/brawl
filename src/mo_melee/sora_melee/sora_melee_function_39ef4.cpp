#pragma force_active on
struct Data { int abcd[4]; float e; int fghi[4]; float j, k, l; unsigned int tail[4]; };
struct Elem { int active; Data data; };
class Object_vptr_0 { public: virtual void slot0(); virtual Elem* slot1(int); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); };
class Object_extra { public: virtual void slot0(); virtual Elem* slot1(int, void*); };
struct Inner { char pad[4]; void* value; };
struct Context { char pad[0xd8]; Inner* inner; };
class soCollisionAttackModuleImpl {
public:
 virtual ~soCollisionAttackModuleImpl(); virtual void fn_27_39AA4(); virtual void fn_27_39C34(); virtual void fn_27_39C90(); virtual void fn_27_39D10(); virtual void fn_27_39D80(); virtual void fn_27_39E30(); virtual void fn_27_39EF4(); virtual void fn_27_3A0C4(int, int);
 char pad04[0x24]; Context* context; char pad2c[4]; Object_vptr_0* array; char pad34[0x2c]; float value; char pad64[4]; char work[0x13]; unsigned char flag; char pad7c[0x20]; unsigned int flags;
};
extern "C" unsigned int fn_27_36074(void*, int, unsigned int, int);
extern "C" void* fn_27_36028(void*, int, int);
extern "C" void fn_27_38988(Elem*);
extern "C" void fn_27_38730(Elem*, void*);
extern "C" void fn_27_38C08(Elem*, void*, void*, float);
extern "C" void fn_27_39EF4(soCollisionAttackModuleImpl* self, int index, int arg, Data* data) {
 void* result;
 if (fn_27_36074(self->work, index, data->tail[3] >> 31, arg) == 1) {
  if (self->array->slot1(index)->active != 0) fn_27_38988(self->array->slot1(index));
 }
 result = fn_27_36028(self->work, index, arg);
 Elem* dst = self->array->slot1(index);
 int a; int b = (a = data->abcd[0], data->abcd[1]);
 dst->data.abcd[0] = a; a = data->abcd[2]; dst->data.abcd[1] = b;
 b = data->abcd[3]; dst->data.abcd[2] = a;
 float f = data->e; dst->data.abcd[3] = b;
 b = data->fghi[0]; dst->data.e = f;
 a = data->fghi[1]; dst->data.fghi[0] = b;
 b = data->fghi[2]; dst->data.fghi[1] = a;
 a = data->fghi[3]; dst->data.fghi[2] = b;
 f = data->j; dst->data.fghi[3] = a;
 float g = data->k; dst->data.j = f;
 f = data->l; dst->data.k = g;
 b = data->tail[0]; dst->data.l = f;
 a = data->tail[1]; dst->data.tail[0] = b;
 b = data->tail[2]; dst->data.tail[1] = a;
 a = data->tail[3]; dst->data.tail[2] = b; dst->data.tail[3] = a;
 self->fn_27_3A0C4(index, arg);
 fn_27_38730(self->array->slot1(index), result);
 self->flag = (data->tail[2] >> 8) & 1;
 if (((self->flags >> 27) & 1) == 1) {
  Inner* inner = self->context->inner; void* value = inner->value;
  Elem* e2 = ((Object_extra*)self->array)->slot1(index, inner);
  fn_27_38C08(e2, value, result, self->value);
 }
}