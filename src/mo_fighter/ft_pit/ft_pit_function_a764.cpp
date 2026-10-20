#pragma force_active on
#define SLOT(n) virtual void slot##n();
#define TEN_SLOTS(p) \
    SLOT(p##0) SLOT(p##1) SLOT(p##2) SLOT(p##3) SLOT(p##4) \
    SLOT(p##5) SLOT(p##6) SLOT(p##7) SLOT(p##8) SLOT(p##9)

class Object {
    unsigned char padding[0x3C];

public:
    TEN_SLOTS(a)
    TEN_SLOTS(b)
    TEN_SLOTS(c)
    TEN_SLOTS(d)
    TEN_SLOTS(e)
    TEN_SLOTS(f)
    TEN_SLOTS(g)
    TEN_SLOTS(h)
    TEN_SLOTS(i)
    TEN_SLOTS(j)
    TEN_SLOTS(k)
    TEN_SLOTS(l)
    TEN_SLOTS(m)
    TEN_SLOTS(n)
    TEN_SLOTS(o)
    TEN_SLOTS(p)
    TEN_SLOTS(q)
    TEN_SLOTS(r)
    SLOT(s0) SLOT(s1) SLOT(s2) SLOT(s3) SLOT(s4) SLOT(s5)
    virtual void callback();
};

#undef TEN_SLOTS
#undef SLOT

extern "C" void fn_112_A764(Object* self) {
    self->callback();
}
