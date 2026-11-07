#include <types.h>
#pragma force_active on
struct Data { int a; u8 c; u8 d; };
struct Params { int a; Data b; float x,y,z; };
struct Desc { void* a; void* b; void* c; Params* d; int e; };
extern Desc lbl_8040AFA8;
extern "C" void fn_801C6AC0(Params*);
extern "C" void* fn_801C96A0(void*);
extern "C" int fn_801C6C0C(void*, int, Data*);
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
virtual void slot20(int);
};
struct Object_vptr_8_base { char pad[8]; };
class Object_vptr_8 : public Object_vptr_8_base {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
virtual int slot8(Object_vptr_0**, int, Desc*, void*, int, int);
};
struct Owner { char pad[0xac]; void* a; Object_vptr_8* b; int c; float x,y,z; };
extern "C" int fn_801C5EF8(Owner* self, Object_vptr_0** out, int id, int unused1, int unused2, int arg5, int arg6) {
    Params p;
    fn_801C6AC0(&p);
    p.x = self->x; p.y = self->y; p.z = self->z;
    p.a = self->c;
    Data d;
    if (fn_801C6C0C(fn_801C96A0(self->b), id, &d)) {
        p.b = d;
    }
    Desc desc = lbl_8040AFA8;
    desc.a = self->a;
    void* ptr = self;
    if (self) ptr = (char*)self + 0xa8;
    desc.b = ptr;
    void* ptr2 = self->a;
    if (ptr2) ptr2 = (char*)ptr2 + 4;
    desc.c = ptr2;
    desc.d = &p;
    int result = self->b->slot8(out, id, &desc, (char*)self + 8, arg5, arg6);
    if (*out) (*out)->slot20(3);
    return result;
}