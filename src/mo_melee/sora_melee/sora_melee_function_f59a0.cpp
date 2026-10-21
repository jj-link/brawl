#include <types.h>
#pragma force_active on

class Member {
public:
    virtual void v0();
    virtual void* getItem(s32 index);
    virtual void v2();
    virtual s32 getCount();
};

class Owner {
public:
    u8 pad[0x10];
    Member mem;
};

class Visitor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void visit(void** item);
};

extern "C" void fn_27_FE0C8(s16* out, void* v);

extern "C" {
void fn_27_F59A0(Owner* self, s16* mask, Visitor* v) {
    s32 n = self->mem.getCount();
    for (s32 i = 0; i < n; i++) {
        s16 tmp;
        fn_27_FE0C8(&tmp, self->mem.getItem(i));
        if (tmp & *mask) {
            void* p = self->mem.getItem(i);
            v->visit(&p);
        }
    }
}
}
