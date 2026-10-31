#pragma force_active on

class Result {
public:
    int pad;
    int value;
};

class SubObj {
public:
    virtual void v0();
    virtual void v1();
    virtual Result* get(int idx);
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
    virtual unsigned fn();
};

class MainObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual unsigned m7();
    int field1;
    int field2;
    int field3;
    SubObj sub;
};

extern "C" int fn_27_295470(MainObj* self) {
    if (self->sub.fn() == 1) {
        return 0x7FFF;
    }
    if (self->m7() == 1) {
        return 0;
    }

    int idx = self->sub.size() - 1;
    if (self->sub.get(idx)->value < 0x7FFF) {
        int idx2 = self->sub.size() - 1;
        return self->sub.get(idx2)->value + 1;
    }

    int prev;
    int i = self->sub.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->sub.get(i)->value == 0) {
                return -1;
            }
            return self->sub.get(i)->value - 1;
        }

        prev = self->sub.get(i - 1)->value;
        if (self->sub.get(i)->value - 1 > prev) {
            return self->sub.get(i)->value - 1;
        }
        i--;
    }
    return -1;
}
