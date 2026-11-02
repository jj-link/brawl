#include <types.h>
#pragma force_active on

struct Elem {
    s32 unk0;
    s32 key;
};

class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual Elem* get(s32 index);
};

class Container {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 count();

    s32 pad[3];
    Inner inner;

    s32 find(s32 key) {
        if (key <= -1)
            return -1;

        s32 n = count();
        for (s32 i = 0; i < n; ++i) {
            if (key == inner.get(i)->key)
                return i;
        }
        return -1;
    }
};

extern "C" s32 fn_27_1E6544(Container* self, s32 key) {
    return self->find(key);
}
