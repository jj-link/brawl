#pragma force_active on

extern "C" int fn_27_2ACB8C(void*);

struct soEntry {
    int a;
    int b;
    int c;
};

class soWorkBase {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual unsigned int v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
};

extern "C" void* fn_27_2AE644(soWorkBase* self) {
    int idx = fn_27_2ACB8C(self);
    if (self->v6() != 1 && idx >= 0) {
        self->v15();
    }
    return (soEntry*)((char*)self + idx * 12 + 12);
}
