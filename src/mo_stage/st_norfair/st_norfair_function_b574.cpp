#pragma force_active on

extern "C" void update__9grGimmickFf(void*, float);

struct GimmickBase {
    unsigned char padding[0x3C];
};

struct GimmickDispatch : GimmickBase {
#define TEN(N) \
    virtual void r##N##0(); \
    virtual void r##N##1(); \
    virtual void r##N##2(); \
    virtual void r##N##3(); \
    virtual void r##N##4(); \
    virtual void r##N##5(); \
    virtual void r##N##6(); \
    virtual void r##N##7(); \
    virtual void r##N##8(); \
    virtual void r##N##9();

    TEN(0)
    TEN(1)
    TEN(2)
    TEN(3)
    TEN(4)
    TEN(5)
    TEN(6)
    TEN(7)
    TEN(8)
    TEN(9)
    TEN(10)

#undef TEN

    virtual void r110();
    virtual void r111();
    virtual void r112();
    virtual void updateFirst(float);
    virtual void updateSecond(float);
    virtual void updateThird(float);
    virtual void updateFourth(float);

    unsigned char padding1[0x88];
    unsigned char active;
};

extern "C" void fn_54_B574(GimmickDispatch* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->updateFirst(deltaFrame);
        self->updateSecond(deltaFrame);
        self->updateThird(deltaFrame);
        self->updateFourth(deltaFrame);
    }
}
