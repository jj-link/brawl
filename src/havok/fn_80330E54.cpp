// Best result: 99.8% match. Remaining diff: index/offset loads in the tail use r0/r4 instead of r4/r5.
#pragma force_active on
#pragma use_lmw_stmw on

class Allocator {
public:
    virtual char* alloc(int, int);
};

extern Allocator* lbl_805A0EB8;
extern void* lbl_805A0EC8;

extern "C" void fn_8027CE3C(void*, int);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" char* fn_8027C83C(void*);

struct Entry {
    int first;
    int second;
};

struct Array {
    Entry* data;
    int size;
    unsigned int capacity;

    bool isOwned() const {
        return (capacity & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, capacity * 8, 0x15);
    }
};

struct Context {
    char pad[0x18];
    int start;
    int end;
    char pad2[0xc];
    int length;
};

struct Buf {
    char pad[0x18];
    char** data;
    int size;
    unsigned int capacity;
};

struct Info {
    char pad[0xc];
    int type;
    char pad2[0x10];
    int index;
    int offset;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3(char*, int);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void* slot12(int, int);

    int pad;
    Buf* buf;
    Info* info;
    Context* contexts;
    char** blocks;
};

extern "C" void fn_80331C3C(Context*, char*, Array*);
extern "C" void fn_80331D14(Context*, char*, Array*);
extern "C" void fn_8033249C(Buf*, int, int);
extern "C" void fn_8033251C(Buf*, int, int);

extern "C" int fn_80330E54(
    Object_vptr_0* self, Object_vptr_0* reader, int index, char* base
) {
    Context* ctx = &self->contexts[index];
    Buf* buf;
    int idx;
    int off;
    int length = ctx->length;

    if (base == 0) {
        base = lbl_805A0EB8->alloc(length, 5);
        buf = self->buf;
        if (buf->size == (int)(buf->capacity & 0x3fffffff))
            fn_8027CE3C(&buf->data, 4);
        buf->data[buf->size++] = base;
    }

    if (length == reader->slot3(base, length)) {
        int* p = (int*)(base + ctx->start);
        for (int i = 0; i < (ctx->end - ctx->start) / 4; i += 2) {
            if (p[0] != -1)
                *(char**)(base + p[0]) = base + p[1];
            p += 2;
        }

        Array a;
        a.data = 0;
        a.size = 0;
        a.capacity = 0x80000000;
        fn_80331C3C(ctx, base, &a);
        for (int i = 0; i < a.size; i++)
            fn_8033249C(self->buf, a.data[i].first, a.data[i].second);
        if (a.isOwned())
            a.dealloc();

        Array b;
        b.data = 0;
        b.size = 0;
        b.capacity = 0x80000000;
        fn_80331D14(ctx, base, &b);

        int i = 0;
        int j = 0;
        while (i < b.size) {
            fn_8033251C(
                self->buf,
                ((Entry*)((char*)b.data + j))->first,
                ((Entry*)((char*)b.data + j))->second
            );
            j += 8;
            i++;
        }
        if (b.isOwned())
            b.dealloc();

        self->blocks[index] = base;
        idx = self->info->index;
        off = self->info->offset;
        if (index == idx) {
            if (off >= 0 && self->info->type < 3) {
                self->info->offset = fn_8027C83C(self->slot12(idx, off)) - base;
            }
        }
        return 0;
    }

    return 1;
}
