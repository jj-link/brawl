#pragma force_active on
class Base {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
};

extern "C" void fn_27_EF4A4(char* self) {
    Base* b = reinterpret_cast<Base*>(self + 0x10);
    b->v8();
}
