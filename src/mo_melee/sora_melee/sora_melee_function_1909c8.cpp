#pragma force_active on
extern "C" void fn_27_190A8C(void*);

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(unsigned int);
    virtual void v5();
    virtual void v6();
    virtual void v7(unsigned int);
};

struct Inner {
    char pad[0x64];
    Obj* obj;
};

struct Outer {
    char pad[0xd8];
    Inner* inner;
};

extern "C" void fn_27_1909C8(void*, Outer* self) {
    Obj* obj = self->inner->obj;
    int a = obj->v4(0x20000000);
    int b = obj->v4(0x20000001);
    obj->v4(0x20000002);
    obj->v7(0x20000002);

    switch (a) {
    case 2:
        switch (b) {
        case 0:
            fn_27_190A8C(self);
            break;
        }
        break;
    }
}
