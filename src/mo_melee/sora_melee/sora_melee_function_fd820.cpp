#pragma force_active on
class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
};

class Outer {
public:
    int unk0[4];
    Sub sub;
};

extern "C" void fn_27_FD820(Outer* self) {
    self->sub.v8();
}
