#pragma force_active on

struct Field {
    char padding[0x10];
    void* value;
};

struct FirstArg {
    char padding[0x100];
    Field* field;
};

struct SecondArg {
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
    virtual void v12();
    virtual void call(void*);
};

extern "C" void fn_8010C0DC(FirstArg* first, SecondArg* second) {
    second->call(first->field->value);
}
