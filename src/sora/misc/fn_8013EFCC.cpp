#include <gf/gf_heap_manager.h>
#pragma force_active on

class Item {
public:
    virtual void v0();
    virtual void v1();
    virtual void clear();
    char pad[0x10];
};

struct Object {
    char pad0[0x20];
    void* buffer;
    char pad24[0x14];
    Item a;
    char pad4c[0xc];
    Item items[4];
    char pada8[0xa8];
    Item b;
    char pad164[4];
    Item c;
    char pad17c[0xb4];
    int x230;
    int x234;
    unsigned char flag;
    char pad239[3];
    void* buffer2;
    int x240;
    int x244;
    int x248;
    int x24c;
};

extern "C" void fn_8013EFCC(Object* self) {
    self->b.clear();
    self->a.clear();
    gfHeapManager::free(self->buffer);
    self->buffer = 0;
    self->c.clear();
    if (!self->flag && self->buffer2 != 0)
        gfHeapManager::free(self->buffer2);
    self->buffer2 = 0;
    self->x230 = 0;
    self->x234 = 0;
    self->x240 = 0;
    self->x244 = 0;
    self->x248 = 0;
    self->x24c = 0;
    for (unsigned char i = 0; i < 4; ++i)
        self->items[i].clear();
}