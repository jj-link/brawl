#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

struct Body;
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(Body*, void*, void*);
};
class Class_80487228 {
public:
    virtual void fn_802C8FC4();
    virtual void fn_80080A64();
    virtual void fn_802C9FAC();
    virtual void fn_802C9D24();
    virtual void fn_802C9A8C();
    virtual void fn_802C9714();
    virtual void fn_802C8F68();
    virtual void fn_802CA234();
};
struct Shape { char pad[0x10]; void* child; char pad2[0x1c]; char transform[1]; };
struct Body {
    const Shape* shape; unsigned int key; void* data; const Body* parent;
};
struct Self { char pad[0xc]; Object_vptr_0* child; };
extern "C" void fn_802873E8(void*, void*, void*);

extern "C" void fn_802CA234(Self* self, const Body* arg1, void* a2, void* a3) {
    const Shape* shape = arg1->shape;
    Body body;
    __attribute__((aligned(16))) unsigned char transform[0x40];
    fn_802873E8(transform, arg1->data, (void*)shape->transform);
    body.parent = arg1;
    body.data = transform;
    const Shape* child = (const Shape*)shape->child;
    body.key = arg1->key;
    body.shape = child;
    self->child->slot7(&body, a2, a3);
}
