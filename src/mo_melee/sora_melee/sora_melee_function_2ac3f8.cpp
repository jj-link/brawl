#pragma force_active on

typedef unsigned char u8;

struct Item {
    u8 active : 1;
    u8 flags : 7;
    char pad[7];
    signed char prev;
    signed char next;
    char pad2[2];
};

struct Self {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int count();

    unsigned int flags;
    Item items[1];
};

extern "C" void fn_27_2AC3F8(Self* self) {
    self->flags =
        ((self->flags & 0x1FFFFFFF) | 0x1F800000) & 0xFF8FFFFF;

    if (self->count() == 1) {
        self->items[0].prev = -1;
        self->items[0].next = -1;
        self->items[0].active = 0;
    } else {
        Self* links = self;
        Item* item = self->items;

        for (int i = 0; i < self->count(); ++i) {
            links->items[0].prev = i - 1;
            links->items[0].next = i + 1;
            links = (Self*)((char*)links + 12);
            item->active = 0;
            ++item;
        }

        Item* last = &self->items[self->count() - 1];
        last->next = -1;
    }
}
