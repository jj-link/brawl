#pragma force_active on
struct Inner {
    char padding[0x18];
    int field_18;
    int field_1C;
};

class Base {
public:
    virtual void dummy();
};

class Outer : public Base {
    char padding[8];
public:
    Inner* inner;
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
    virtual int v10(char* arg);
    virtual void v11(int a, int b);
};

extern char lbl_8041552C[];

extern "C" void fn_803314B8(Outer* self) {
    int flag = 0;
    int a = self->inner->field_18;
    int b = self->inner->field_1C;
    if (a >= 0 && b >= 0) {
        flag = 1;
    }
    if (flag) {
        self->v11(a, b);
        return;
    }
    int result = self->v10(lbl_8041552C + 0x3E);
    self->v11(result, 0);
}
