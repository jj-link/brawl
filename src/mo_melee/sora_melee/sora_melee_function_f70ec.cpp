#include <types.h>
#pragma force_active on

class Elem {
public:
    int a;
    int b;
};

class List {
public:
    virtual void v0();
    virtual void v1();
    virtual Elem* get(int index);
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
    virtual unsigned int check();
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int state();
    u8 pad[0xC];
    List list;
};

extern "C" int fn_27_F70EC(Owner* self) {
    int temp;
    int i;

    if (self->list.check() == 1) {
        return 0x7fff;
    }
    if (self->state() == 1) {
        return 0;
    }
    {
        int n = self->list.size() - 1;
        if (self->list.get(n)->b < 0x7fff) {
            int m = self->list.size() - 1;
            return self->list.get(m)->b + 1;
        }
    }
    i = self->list.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->list.get(i)->b == 0) {
                return -1;
            }
            return self->list.get(i)->b - 1;
        }
        temp = self->list.get(i - 1)->b;
        if (self->list.get(i)->b - 1 > temp) {
            return self->list.get(i)->b - 1;
        }
        i--;
    }
    return -1;
}
