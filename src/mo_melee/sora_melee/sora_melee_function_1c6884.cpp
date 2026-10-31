#pragma force_active on

struct Item {
    int pad0;
    int val;
};

class Container {
public:
    virtual void a0();
    virtual void a1();
    virtual Item* get(int index);
    virtual int size();
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual unsigned int f14();
};

class Sub {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual unsigned int s5();
};

struct Owner {
    Sub sub;
    int pad[3];
    Container container;
};

extern "C" int fn_27_1C6884(Owner* self) {
    if (self->container.f14() == 1U) {
        return 0x7FFF;
    }
    if (self->sub.s5() == 1U) {
        return 0;
    }

    int idx = self->container.size() - 1;
    Item* item = self->container.get(idx);
    if (item->val < 0x7FFF) {
        int idx2 = self->container.size() - 1;
        return self->container.get(idx2)->val + 1;
    }

    int prev;
    int i = self->container.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->container.get(i)->val == 0) {
                return -1;
            }
            return self->container.get(i)->val - 1;
        }
        prev = self->container.get(i - 1)->val;
        Item* curr = self->container.get(i);
        if (curr->val - 1 > prev) {
            return self->container.get(i)->val - 1;
        }
        i--;
    }
    return -1;
}
