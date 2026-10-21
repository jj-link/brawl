#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual int getValue(int index);
    virtual void v4();
    virtual int getCount();
};

class Visitor {
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
    virtual void visit(int* value);
};

struct Outer {
    char pad[0x10];
    Inner inner;
};

extern "C" void fn_27_292AC0(Outer* self, Visitor* visitor) {
    int count = self->inner.getCount();
    for (int i = 0; i < count; i++) {
        int value = self->inner.getValue(i);
        visitor->visit(&value);
    }
}
