#pragma force_active on
struct Entry {
    unsigned char active:1;
    unsigned char other:7;
    char pad[7];
    signed char prev;
    signed char next;
    char tail[2];
};
struct Object {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual int count();
    unsigned int a:7;
    unsigned int b:7;
    unsigned int c:7;
    unsigned int d:7;
    unsigned int e:4;
    Entry entries[1];
};
extern "C" void fn_27_25EA94(Object* self) {
    self->a = 0;
    self->b = -1;
    self->c = -1;
    self->d = 0;
    if (self->count() == 1) {
        self->entries[0].prev = -1;
        self->entries[0].next = -1;
        self->entries[0].active = 0;
    } else {
        for (int i = 0; i < self->count(); ++i) {
            self->entries[i].prev = i - 1;
            self->entries[i].next = i + 1;
            self->entries[i].active = 0;
        }
        Entry* last = &self->entries[self->count() - 1];
        last->next = -1;
    }
}
