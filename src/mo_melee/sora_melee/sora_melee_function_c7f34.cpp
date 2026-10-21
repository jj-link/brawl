#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;

struct Entry {
    u8 active : 1;
    u8 other : 7;
    char pad[15];
    s8 prev;
    s8 next;
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
    Entry entries[1];
};

extern "C" void fn_27_C7F34(Self* self) {
    self->flags = ((self->flags & 0x07FFFFFF) | 0x07FE0000) & 0xFFFE0FFF;

    if (self->count() == 1) {
        self->entries[0].prev = -1;
        self->entries[0].next = -1;
        self->entries[0].active = 0;
        return;
    }

    for (int i = 0; i < self->count(); i++) {
        self->entries[i].prev = i - 1;
        self->entries[i].next = i + 1;
        self->entries[i].active = 0;
    }

    Entry* last = &self->entries[self->count() - 1];
    last->next = -1;
}
