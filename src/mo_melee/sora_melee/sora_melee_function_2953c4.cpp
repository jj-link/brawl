#include <types.h>
#pragma force_active on

struct Elem {
    s32 a;
    s32 id;
};

struct Helper {
    virtual void v0();
    virtual void v1();
    virtual Elem* getAt(s32 idx);
};

struct Base {
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual s32 getCount();

    s32 pad[3];
    Helper helper;

    s32 find(s32 index) {
        if (index <= -1)
            return -1;

        s32 count = getCount();
        for (s32 i = 0; i < count; i++) {
            if (index == helper.getAt(i)->id)
                return i;
        }
        return -1;
    }
};

extern "C" s32 fn_27_2953C4(Base* self, s32 index) {
    return self->find(index);
}
