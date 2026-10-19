#include <types.h>
#pragma force_active on

struct Item {
    void* unk0;
    s32 key;
};

class WorkArray {
public:
    virtual void x0();
    virtual void set(s32 index);
    virtual Item* get(s32 index);
    virtual void x3();
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
};

extern "C" void fn_27_C49C8(Owner* self, s32 index) {
    s32 result;
    if (index <= -1) {
        self->m_array.set(0);
        return;
    }
    if (index <= -1) {
        result = -1;
        goto exit;
    }
    {
        s32 n = self->size();
        s32 i;
        result = 0;
        for (i = 0; i < n; i++) {
            if (self->m_array.get(i)->key == index) {
                result = i;
                goto exit;
            }
        }
        result = -1;
    }
exit:
    if (result < 0) {
        self->m_array.set(0);
    } else {
        self->m_array.set(result);
    }
}
