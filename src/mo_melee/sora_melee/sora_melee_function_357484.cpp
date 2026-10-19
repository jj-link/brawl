#pragma force_active on
class Inner {
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
    virtual void v11(void* p, bool b);
};

struct Mid {
    char pad[0x3c];
    Inner* inner;
};

struct Obj {
    char pad[0xd8];
    Mid* mid;
};

extern "C" {
void fn_27_357484(void* r3, Obj* obj, int msg) {
    if (msg == 0x116) {
        obj->mid->inner->v11(0, true);
    } else {
        obj->mid->inner->v11(0, false);
    }
}
}
