#include <types.h>
#pragma force_active on
struct Vec { u32 x, y, z; };
struct Object_vptr_1c_base { char pad[0x1c]; };
class Object_vptr_1c : public Object_vptr_1c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2(int, Vec, Vec, void*, int, int, int, float);
    char pad2[0xc2];
    u16 count;
};
class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual Object_vptr_1c* slot17();
};
struct A { char pad[0x20]; Object_vptr_0** obj; };
struct B { char pad[0xbc]; A* a; };
struct Owner { char pad[0x20]; B* b; char pad2[0x2c]; u16 count; };
extern "C" void fn_8015BFB4(void*, void*);
extern "C" Object_vptr_1c* fn_8016C744(Owner* self, int a, Vec b, Vec c, int d, int e, int f, int g, float h) {
    Object_vptr_1c* result = (*self->b->a->obj)->slot17();
    if (!result) return 0;
    if (!result->slot2(a, b, c, self, d, e, f, h)) return 0;
    result->count += g;
    fn_8015BFB4((char*)self + 0x38, result);
    self->count++;
    *(int*)((char*)result + 0xc) = 1;
    return result;
}