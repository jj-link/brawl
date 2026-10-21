#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

struct Entry {
    u8 active : 1;
    u8 flags : 7;
    char pad[7];
    s8 prev;
    s8 next;
    char pad2[2];
};

struct Object {
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

    u32 header;
    Entry entries[1];
};

extern "C" void fn_27_2C1E4C(Object* self) {
    self->header =
        ((self->header & 0xFFFFFF) | 0xFF0000 | 0xFF00) & 0xFFFFFF00;

    if (self->count() == 1) {
        self->entries[0].prev = -1;
        self->entries[0].next = -1;
        self->entries[0].active = 0;
    } else {
        for (int i = 0; i < self->count(); i++) {
            self->entries[i].prev = i - 1;
            self->entries[i].next = i + 1;
            self->entries[i].active = 0;
        }

        Entry* last = &self->entries[self->count() - 1];
        last->next = -1;
    }
}
