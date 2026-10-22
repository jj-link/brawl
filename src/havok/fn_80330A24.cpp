#pragma force_active on
struct Alloc { virtual void* alloc(int size, int align); };
struct Vec2 { char pad[0x18]; int* data; int size; unsigned cap; };
struct Flag { signed char v; };
struct Stream {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual unsigned read(void* buf, int n);
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Flag isOpen();
    virtual void v9();
    virtual int getSize();
};
struct Owner {
    char pad0[8];
    Vec2* list;
    int* buf;
    char pad1[0x50];
    int size;
};
extern Alloc* lbl_805A0EB8;
extern "C" void fn_8027CE3C(void*, int);
extern "C" void fn_80281D64(void*, int, int);
extern "C" int fn_80330A24(Owner* self, Stream* s, int* b) {
    self->size = s->isOpen().v ? s->getSize() : 0;
    if (b == 0) {
        b = (int*)lbl_805A0EB8->alloc(0x40, 5);
        Vec2* l = self->list;
        if (l->size == (int)(l->cap & 0x3FFFFFFF)) fn_8027CE3C(&l->data, 4);
        l->data[l->size++] = (int)b;
    }
    if (s->read(b, 0x40) == 0x40) {
        int tmp[16];
        fn_80281D64(tmp, -1, 0x40);
        tmp[0] = 0x57E0E057;
        tmp[1] = 0x10C0C010;
        ((char*)tmp)[0x28] = 0;
        if (b[0] == tmp[0] && b[1] == tmp[1]) {
            self->buf = b;
            return 0;
        }
    }
    self->buf = 0;
    return 1;
}
