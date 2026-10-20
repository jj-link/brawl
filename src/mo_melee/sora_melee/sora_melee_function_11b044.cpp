#pragma force_active on
class SubObj {
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
    virtual void v10();
};

class Outer {
public:
    char pad[0x10];
    SubObj sub;
};

extern "C" {
void fn_27_11B044(Outer* p) {
    p->sub.v8();
}
}
