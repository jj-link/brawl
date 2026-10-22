#pragma force_active on

struct Element {
    int field0;
    int field4;
};

class ClassA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned check();
    int pad[3];
};

class ClassB {
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
    virtual unsigned check();
};

struct Owner {
    ClassA classA;
    ClassB classB;
};

extern "C" int fn_27_1AD58C(Owner* self) {
    if (self->classB.check() == 1) {
        return 0x7FFF;
    }
    if (self->classA.check() == 1) {
        return 0;
    }
    int idx = self->classB.size() - 1;
    Element* elem = self->classB.get(idx);
    if (elem->field4 < 0x7FFF) {
        int idx2 = self->classB.size() - 1;
        Element* e2 = self->classB.get(idx2);
        return e2->field4 + 1;
    }
    int prev_val;
    int i = self->classB.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->classB.get(i)->field4 == 0) {
                return -1;
            }
            return self->classB.get(i)->field4 - 1;
        }
        prev_val = self->classB.get(i - 1)->field4;
        if (self->classB.get(i)->field4 - 1 > prev_val) {
            return self->classB.get(i)->field4 - 1;
        }
        i--;
    }
    return -1;
}
