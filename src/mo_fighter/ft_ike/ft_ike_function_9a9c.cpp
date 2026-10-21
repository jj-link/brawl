#pragma force_active on
struct Array {
    virtual ~Array();
    virtual void slot0();
    virtual void slot1();
    virtual int size() const;
};

struct Aggregate {
    void* vtable;
    unsigned cache[3];
    Array* a;
    Array* b;
    Array* c;
};

extern "C" int fn_119_9A9C(const Aggregate* x) {
    int size = x->c->size();
    if (size < x->a->size())
        size = x->a->size();
    if (size < x->b->size())
        size = x->b->size();
    return size;
}
