#include <types.h>
#pragma force_active on

struct Element {
    int field0;
    int field4;
};

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual Element* get(int index);
    virtual int size();
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
    virtual unsigned firstMethod();
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned checkMethod();
    char pad[12];
    Sub sub;
};

extern "C" int fn_27_F7AD0(Owner* self) {
    if (self->sub.firstMethod() == 1) {
        return 0x7fff;
    }
    if (self->checkMethod() == 1) {
        return 0;
    }
    int n = self->sub.size() - 1;
    if (self->sub.get(n)->field4 < 0x7fff) {
        int n2 = self->sub.size() - 1;
        return self->sub.get(n2)->field4 + 1;
    }
    int i = self->sub.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->sub.get(i)->field4 == 0) {
                return -1;
            }
            return self->sub.get(i)->field4 - 1;
        }
        if (self->sub.get(i)->field4 - 1 > self->sub.get(i - 1)->field4) {
            return self->sub.get(i)->field4 - 1;
        }
        i--;
    }
    return -1;
}
