#pragma force_active on
class wnPikminPikmin;
class EnumP { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual wnPikminPikmin** getCurrent(); void* a; void* b; int c; int index; };
class EnumBase { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual wnPikminPikmin** getCurrent(); };
template <class T, int N> class soArrayList { public: virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual int isEmpty(); EnumP getEnumerator(); };
typedef soArrayList<wnPikminPikmin*, 10> PikminList;
struct Fn113Owner { char pad_00[0x80]; PikminList list80; };
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(); virtual float* slot2(int i); virtual int slot3(); };
extern "C" { void fn_113_18000(wnPikminPikmin* self, float* p); int fn_113_242C8(void* it); void fn_113_24210(void* it, short count); }
extern "C" void fn_113_24B10(Fn113Owner* self, Object_vptr_0* src) {
 float* p;
 if (self->list80.isEmpty() == 0) {
  int i = 0;
  EnumP it = self->list80.getEnumerator();
  for (;;) {
   if (src->slot3() <= i) break;
   p = src->slot2(i);
   wnPikminPikmin* elem = *((EnumBase*)&it)->getCurrent();
   fn_113_18000(elem, p);
   if (fn_113_242C8(&it) == 0) break;
   i++;
  }
  fn_113_24210(&it, 0);
 }
}