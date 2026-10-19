#pragma force_active on
struct Obj_93_47AC {
    void* secondary;
    unsigned char pad[4];

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

extern "C" Obj_93_47AC* fn_93_47AC(
    Obj_93_47AC*, void*, void*, void*, void*, void*, void*);

extern "C" void* fn_93_5AAC(unsigned char* self) {
    fn_93_47AC(
        (Obj_93_47AC*)(self + 0x1C0),
        self,
        (void*)0x4D,
        self + 0x134,
        (void*)0x20,
        self + 0x1B4,
        (void*)3);

    ((Obj_93_47AC*)(self + 0x1C0))->v25();
    return self;
}
