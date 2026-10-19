#pragma force_active on
struct Ft110Work {
    int padding[2];

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

extern "C" Ft110Work* fn_110_7FB0(
    Ft110Work*, int, int, int, int, int, int);

extern "C" void* fn_110_84B0(char* self) {
    fn_110_7FB0(
        reinterpret_cast<Ft110Work*>(self + 0x1c0),
        reinterpret_cast<int>(self),
        0x4d,
        reinterpret_cast<int>(self + 0x134),
        0x20,
        reinterpret_cast<int>(self + 0x1b4),
        3);

    reinterpret_cast<Ft110Work*>(self + 0x1c0)->v25();
    return self;
}
