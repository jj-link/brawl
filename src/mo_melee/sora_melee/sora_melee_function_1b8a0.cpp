#include <types.h>
#pragma force_active on

struct Entry {
    u32 a, b, c, d, e;
};

class Handler {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void apply(Entry* entry);
};

struct Object {
    u8 padding[0x140];
    Handler* handler;
};

extern "C" void fn_27_1B8A0(Object* self, Entry* entries, s32 count) {
    if (entries == 0 || count <= 0) {
        return;
    }
    for (int i = 0; i < count; ++i) {
        self->handler->apply(&entries[i]);
    }
}
