#pragma force_active on

typedef unsigned int u32;

struct Holder {
    char pad[0x30];
    void* data1;
    u32 count1;
    u32 flags1;
    u32 unk3C;
    void* data2;
    u32 count2;
    u32 flags2;
};

struct Visitor {
    virtual void unused();
    virtual void object(const char*, int, void*);
    virtual void array(const char*, int, void*, u32, u32);
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void finish();
};

extern char lbl_80410618[];

extern "C" void fn_802D2424(Holder* self, Visitor* visitor) {
    visitor->object(lbl_80410618 + 0x12, 1, self);

    const char* name1 = lbl_80410618 + 0x1B;
    if (!(self->flags1 & 0x80000000)) {
        visitor->array(name1, 1, self->data1,
                       self->count1 * 0x30,
                       (self->flags1 & 0x3FFFFFFF) * 0x30);
    }

    const char* name2 = lbl_80410618 + 0x1B;
    if (!(self->flags2 & 0x80000000)) {
        visitor->array(name2, 1, self->data2,
                       self->count2 * 0x10,
                       (self->flags2 & 0x3FFFFFFF) * 0x10);
    }

    visitor->finish();
}
