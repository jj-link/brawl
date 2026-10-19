#pragma force_active on
struct FtWolfObj {
    char pad[8];
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
    virtual void activate();
};

struct FtWolf {
    char pad[0x1C0];
    FtWolfObj object;
};

extern "C" FtWolfObj* fn_125_9170(
    FtWolfObj*, void*, int, void*, int, void*, int);

extern "C" FtWolf* fn_125_9670(FtWolf* self) {
    fn_125_9170(
        &self->object,
        self,
        0x4D,
        (char*)self + 0x134,
        0x20,
        (char*)self + 0x1B4,
        3);
    self->object.activate();
    return self;
}
