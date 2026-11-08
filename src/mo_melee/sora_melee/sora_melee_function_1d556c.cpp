#include <types.h>
#pragma force_active on

struct Elem {
    s32 a;
    s32 b;
};

class Obj {
public:
    virtual void v2();
    virtual Elem* get(s32 index);
    virtual void v4();
    virtual s32 count();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(Elem* key);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual u32 v16();
};

extern "C" void fn_27_1D556C(Obj* self, Elem* key) {
    s32 n = self->count();
    for (s32 i = 0; i < n; ++i) {
        Elem* e = self->get(i);
        if (e->b == key->b && e->a == key->a) {
            return;
        }
    }
    if (self->v16() == 1) {
        self->v9();
    }
    self->v11(key);
}
