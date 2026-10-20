#pragma force_active on
extern "C" void update__9grGimmickFf(void* self, float deltaFrame);

struct GimmickBase {
    unsigned char padding[0x3C];
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

struct Gimmick : GimmickBase {
    DECLARE_TEN_SLOTS(0)
    DECLARE_TEN_SLOTS(1)
    DECLARE_TEN_SLOTS(2)
    DECLARE_TEN_SLOTS(3)
    DECLARE_TEN_SLOTS(4)
    DECLARE_TEN_SLOTS(5)
    DECLARE_TEN_SLOTS(6)
    DECLARE_TEN_SLOTS(7)
    DECLARE_TEN_SLOTS(8)
    DECLARE_TEN_SLOTS(9)
    DECLARE_TEN_SLOTS(10)
    virtual void slot110();
    virtual void slot111();
    virtual void update(float deltaFrame);

    unsigned char padding1[0x88];
    unsigned char enabled;
};

#undef DECLARE_TEN_SLOTS

extern "C" void fn_76_DE4(Gimmick* self, float deltaFrame)
{
    update__9grGimmickFf(self, deltaFrame);
    if (self->enabled) {
        self->update(deltaFrame);
    }
}
