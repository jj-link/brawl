#pragma force_active on
class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

extern "C" void fn_27_D9DC4(char* p) {
    Inner* o = (Inner*)(p + 0x10);
    return o->v3();
}
