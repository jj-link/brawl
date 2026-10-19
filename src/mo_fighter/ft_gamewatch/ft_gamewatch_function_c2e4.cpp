#pragma force_active on
#define DECLARE_TEN(n) \
    virtual void reserved_##n##0(); \
    virtual void reserved_##n##1(); \
    virtual void reserved_##n##2(); \
    virtual void reserved_##n##3(); \
    virtual void reserved_##n##4(); \
    virtual void reserved_##n##5(); \
    virtual void reserved_##n##6(); \
    virtual void reserved_##n##7(); \
    virtual void reserved_##n##8(); \
    virtual void reserved_##n##9();

class Object {
public:
    unsigned char padding[0x3C];

    DECLARE_TEN(a)
    DECLARE_TEN(b)
    DECLARE_TEN(c)
    DECLARE_TEN(d)
    DECLARE_TEN(e)
    DECLARE_TEN(f)
    DECLARE_TEN(g)
    DECLARE_TEN(h)
    DECLARE_TEN(i)
    DECLARE_TEN(j)
    DECLARE_TEN(k)
    DECLARE_TEN(l)
    DECLARE_TEN(m)
    DECLARE_TEN(n)
    DECLARE_TEN(o)
    DECLARE_TEN(p)
    DECLARE_TEN(q)
    DECLARE_TEN(r)
    virtual void reserved_s0();
    virtual void reserved_s1();
    virtual void reserved_s2();
    virtual void reserved_s3();
    virtual void reserved_s4();
    virtual void reserved_s5();
    virtual void callback();
};

#undef DECLARE_TEN

extern "C" void fn_107_C2E4(Object* object) {
    object->callback();
}
