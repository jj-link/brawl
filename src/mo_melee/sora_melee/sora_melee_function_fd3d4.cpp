#pragma force_active on

class Elem {
public:
    int pad0;
    int val;
};

class Sub {
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
    virtual unsigned int v14();
};

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int v5();
    unsigned char pad[0x10 - 4];
    Sub sub;
};

extern "C" int fn_27_FD3D4(Self* self) {
    if (self->sub.v14() == 1) {
        return 0x7FFF;
    }
    if (self->v5() == 1) {
        return 0;
    }
    int n = self->sub.size() - 1;
    if (self->sub.get(n)->val < 0x7FFF) {
        int m = self->sub.size() - 1;
        return self->sub.get(m)->val + 1;
    }
    int prev;
    for (int i = self->sub.size() - 1; i >= 0; i--) {
        if (i == 0) {
            if (self->sub.get(i)->val == 0) {
                return -1;
            }
            return self->sub.get(i)->val - 1;
        }
        prev = self->sub.get(i - 1)->val;
        if (self->sub.get(i)->val - 1 > prev) {
            return self->sub.get(i)->val - 1;
        }
    }
    return -1;
}
