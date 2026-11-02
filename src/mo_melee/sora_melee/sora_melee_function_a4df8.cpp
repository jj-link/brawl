#pragma force_active on

class Arr {
public:
    virtual void isNull();
    virtual int* at(int i);
    virtual int* atC(int i) const;
    virtual int size() const;
};

class Self {
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
    virtual void v10();
    virtual void v11();
    virtual void v12(int a, int b, int c);
    unsigned char pad[0x2C];
    Arr* a;
    unsigned char pad2[8];
    Arr* c;
};

extern "C" void fn_27_A7838(int* p);

extern "C" void fn_27_A4DF8(Self* self, int arg1) {
    if (arg1 < 0) {
        int n = self->c->size();
        for (int i = 0; i < n; i++) {
            int idx = *self->c->at(i);
            if (idx != -1) {
                fn_27_A7838(self->a->at(idx));
                self->v12(idx, 0, -1);
                *self->c->at(i) = -1;
            }
        }
        return;
    }
    int idx = *self->c->at(arg1);
    if (idx != -1) {
        fn_27_A7838(self->a->at(idx));
        self->v12(idx, 0, -1);
        int* p = self->c->at(arg1);
        *p = -1;
    }
}
