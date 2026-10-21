#pragma force_active on

struct Obj {
    virtual void v0();
    virtual void call(int, float, float, float);
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual int count();

    unsigned char pad[0x30];
    int value;
};

extern "C" void fn_27_48E2C(Obj* self, int value, float a, float b, float c) {
    self->value = value;
    for (int i = 0; i < self->count(); ++i) {
        self->call(i, a, b, c);
    }
}
