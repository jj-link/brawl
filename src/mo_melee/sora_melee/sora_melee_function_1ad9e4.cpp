#include <types.h>
#pragma force_active on

struct Item {
    void* unk0;
    s32 key;
};

struct WorkArray {
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
    virtual void set(s32 index);
};

struct Owner {
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

extern "C" void fn_27_1AD9E4(Owner* self, s32 id) {
    s32 result;
    if (id <= -1) {
        result = -1;
        goto exit;
    }
    {
        s32 n = self->size();
        s32 i;
        result = 0;
        for (i = 0; i < n; i++) {
            if (self->m_array.get(i)->key == id) {
                result = i;
                goto exit;
            }
        }
        result = -1;
    }
exit:
    if (result >= 0) {
        self->m_array.set(result);
    }
}
