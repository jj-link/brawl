#pragma force_active on
class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct Sub {
    unsigned char pad[0x14];
    Inner* inner;
};

struct Obj {
    unsigned char pad[0xd8];
    Sub* sub;
};

extern "C" void fn_27_32907C(Obj* obj);

extern "C" void fn_27_328F10(void* unused, Obj* obj) {
    if (obj->sub->inner->v3() == 2) {
        fn_27_32907C(obj);
    }
}
