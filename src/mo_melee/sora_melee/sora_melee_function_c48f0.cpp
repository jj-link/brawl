#include <types.h>
#pragma force_active on

struct Item {
    void* unk0;
    s32 key;
};

class WorkArray {
public:
    virtual void f0();
    virtual void f1();
    virtual Item* get(s32 index);
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void set(s32 index);
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
    WorkArray m_array;

    s32 find(s32 index) {
        if (index <= -1)
            return -1;

        s32 n = size();
        for (s32 i = 0; i < n; ++i) {
            if (index == m_array.get(i)->key)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_C48F0(Owner* self, s32 index) {
    s32 result = self->find(index);
    if (result >= 0)
        self->m_array.set(result);
}
