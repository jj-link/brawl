#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

struct Entry {
    u8 active : 1;
    u8 other : 7;
    char pad[11];
    s8 prev;
    s8 next;
    char pad2[2];

    void clear() { active = 0; }
    void setNext(s8 value) { next = value; }
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

    u32 flags;
    Entry entries[1];
};

extern "C" void fn_27_9EE9C(Object* self) {
    self->flags = ((self->flags & 0x07FFFFFF) | 0x07FE0000) & 0xFFFE0FFF;
    if (self->count() == 1) {
        self->entries[0].prev = -1;
        self->entries[0].next = -1;
        self->entries[0].clear();
    } else {
        for (int i = 0; i < self->count(); i++) {
            self->entries[i].prev = i - 1;
            self->entries[i].next = i + 1;
            self->entries[i].clear();
        }
        self->entries[self->count() - 1].setNext(-1);
    }
}
