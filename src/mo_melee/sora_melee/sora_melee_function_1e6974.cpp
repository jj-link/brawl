#include <types.h>
#pragma force_active on

struct Item {
    void* unk0;
    s32 key;
};

class WorkArray {
public:
    virtual void x0();
    virtual void x1();
    virtual Item* get(s32 index);
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void x6();
    virtual void x7();
    virtual void x8();
    virtual void x9();
    virtual void x10();
    virtual void x11();
    virtual void select(s32 index);
};

class Owner {
public:
    virtual void y0();
    virtual void y1();
    virtual void y2();
    virtual void y3();
    virtual s32 size();
    void* pad0;
    void* pad1;
    void* pad2;
    WorkArray arr;

    s32 find(s32 id) {
        if (id <= -1)
            return -1;

        s32 count = size();
        for (s32 i = 0; i < count; ++i) {
            if (id == arr.get(i)->key)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_1E6974(Owner* self, s32 id) {
    s32 result = self->find(id);
    if (result >= 0) {
        self->arr.select(result);
    }
}
