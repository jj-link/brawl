#pragma force_active on
extern "C" void* fn_95_9118(void*, int, int, int, int, int, int);

struct Module {
    int data[2];
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
};

extern "C" void* fn_95_9618(void* self) {
    char* p = (char*)self;
    fn_95_9118(p + 0x1c0, (int)self, 0x4d, (int)(p + 0x134),
               0x20, (int)(p + 0x1b4), 3);
    ((Module*)(p + 0x1c0))->v25();
    return self;
}
