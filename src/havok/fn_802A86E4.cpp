#pragma force_active on

typedef unsigned int u32;

struct Entry {
    int a;
    int b;
    void* object;
};

struct Holder {
    char pad[12];
    Entry* data;
    u32 count;
    u32 flags;
};

struct Visitor {
    virtual void unused();
    virtual void object(const char*, int, void*);
    virtual void array(const char*, int, void*, u32, u32);
    virtual void pointer(const char*, int, void*);
};

extern char lbl_8040FB98[];

extern "C" void fn_802A86E4(Holder* self, Visitor* visitor) {
    visitor->object(lbl_8040FB98 + 0x26, 8, self);

    const char* name = lbl_8040FB98 + 0x30;
    if (!(self->flags & 0x80000000)) {
        visitor->array(name, 8, self->data,
                       self->count * 12,
                       (self->flags & 0x3FFFFFFF) * 12);
    }

    Entry* p = self->data;
    Entry* end = p + self->count;
    for (; p != end; ++p) {
        if (p->object != 0) {
            visitor->pointer(lbl_8040FB98 + 0x3A, 8, p->object);
        }
    }
}
