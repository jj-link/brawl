#include <types.h>
#pragma force_active on

struct Elem {
    s32 unk0;
    s32 key;
};

class Inner {
public:
    virtual void fn_27_AC9D8();
    virtual void fn_27_AC37C();
    virtual Elem* fn_27_AC38C(s32);
};

class Container {
public:
    virtual void fn_27_1BA390();
    virtual void fn_27_1B9D34();
    virtual void fn_27_1B9D44();
    virtual void fn_27_1A34EC();
    virtual s32 fn_27_86BA0();

    s32 pad[3];
    Inner inner;

    s32 find(s32 key) {
        if (key <= -1)
            return -1;

        s32 count = fn_27_86BA0();
        for (s32 i = 0; i < count; ++i) {
            if (key == inner.fn_27_AC38C(i)->key)
                return i;
        }
        return -1;
    }
};

extern "C" s32 fn_27_1C3664(Container* self, s32 key) {
    return self->find(key);
}
