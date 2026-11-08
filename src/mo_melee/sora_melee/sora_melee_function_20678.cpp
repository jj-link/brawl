#include <types.h>
#pragma force_active on
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(float); };
struct Obj { Object_vptr_0* p0; Object_vptr_0* p1; Object_vptr_0* p2; Object_vptr_0* p3; Object_vptr_0* p4; float f14; float f18; char pad[4]; float f20; u8 a:1; u8 b:1; u8 c:1; u8 rest:5; };
struct Value { int x; };
extern "C" void fn_27_1FA94(void*, Value*, Value*, int, int);
extern "C" void fn_27_20678(Obj* obj, Value a, Value b, int c, int d, int e, int f, float f1, float f2) {
    Value va;
    Value vb;
    vb = b;
    va = a;
    fn_27_1FA94(obj, &va, &vb, c, f);
    obj->a = d;
    obj->f20 = f2;
    if (!obj->c) {
        if (obj->p0) obj->p0->slot5(f1);
        if (obj->p1) obj->p1->slot5(f1);
        if (obj->p2) obj->p2->slot5(f1);
        if (obj->p3) obj->p3->slot5(f1);
        if (obj->p4) obj->p4->slot5(f1);
        obj->f14 = f1;
    }
    obj->f18 = f1;
    obj->b = e;
}