#pragma force_active on
#define SLOT(n) virtual void slot##n();
#define TEN(p) \
    SLOT(p##0) SLOT(p##1) SLOT(p##2) SLOT(p##3) SLOT(p##4) \
    SLOT(p##5) SLOT(p##6) SLOT(p##7) SLOT(p##8) SLOT(p##9)

class Object {
public:
    unsigned char padding[0x3C];

    TEN(a)
    TEN(b)
    TEN(c)
    TEN(d)
    TEN(e)
    TEN(f)
    TEN(g)
    TEN(h)
    TEN(i)
    TEN(j)
    TEN(k)
    TEN(l)
    TEN(m)
    TEN(n)
    TEN(o)
    TEN(p)
    TEN(q)
    TEN(r)
    SLOT(s0)
    SLOT(s1)
    SLOT(s2)
    SLOT(s3)
    SLOT(s4)
    SLOT(s5)

    virtual void target();
};

#undef TEN
#undef SLOT

extern "C" void fn_108_AF30(Object* object) {
    object->target();
}
