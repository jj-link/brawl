#pragma force_active on
class Object {
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
    virtual void target(int, int, const int&, int, int, int, int, int, int);
};

extern "C" void fn_27_988B8(Object* self, int a, int b, int c, int d,
                           int e, int f, int g, int h) {
    int value = 65535;
    self->target(a, b, value, c, d, e, f, g, h);
}
