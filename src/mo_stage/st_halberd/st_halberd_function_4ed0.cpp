#pragma force_active on
extern "C" void update__9grGimmickFf(void* self, float deltaFrame);

struct Prefix {
    char padding[0x3C];
};

#define DECLARE_TEN_SLOTS(n) \
    virtual void slot##n##0(); \
    virtual void slot##n##1(); \
    virtual void slot##n##2(); \
    virtual void slot##n##3(); \
    virtual void slot##n##4(); \
    virtual void slot##n##5(); \
    virtual void slot##n##6(); \
    virtual void slot##n##7(); \
    virtual void slot##n##8(); \
    virtual void slot##n##9();

struct Object : Prefix {
    DECLARE_TEN_SLOTS(a)
    DECLARE_TEN_SLOTS(b)
    DECLARE_TEN_SLOTS(c)
    DECLARE_TEN_SLOTS(d)
    DECLARE_TEN_SLOTS(e)
    DECLARE_TEN_SLOTS(f)
    DECLARE_TEN_SLOTS(g)
    DECLARE_TEN_SLOTS(h)
    DECLARE_TEN_SLOTS(i)
    DECLARE_TEN_SLOTS(j)
    DECLARE_TEN_SLOTS(k)
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void first(float deltaFrame);
    virtual void second(float deltaFrame);

    char padding1[0x88];
    unsigned char active;
};

#undef DECLARE_TEN_SLOTS

extern "C" void fn_57_4ED0(Object* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->first(deltaFrame);
        self->second(deltaFrame);
    }
}
