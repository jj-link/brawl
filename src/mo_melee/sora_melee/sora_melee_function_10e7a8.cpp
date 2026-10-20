#pragma force_active on
class Target {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
};

class Holder {
public:
    virtual void dummy();
    int pad[3];
};

class Wrapper : public Holder, public Target {
};

extern "C" {
void fn_27_10E7A8(Wrapper& r) {
    ((Target&)r).v13();
}
}
