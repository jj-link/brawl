#pragma force_active on
struct FtSnakeWork {
    void* vtSecondary;
    unsigned char pad[4];

    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
};

extern "C" FtSnakeWork* fn_122_BD60(
    FtSnakeWork*, int, int, int, int, int, int);

extern "C" void* fn_122_C260(unsigned char* self) {
    fn_122_BD60(
        (FtSnakeWork*)(self + 0x1C0),
        (int)self,
        0x4D,
        (int)(self + 0x134),
        0x20,
        (int)(self + 0x1B4),
        3);

    ((FtSnakeWork*)(self + 0x1C0))->f25();
    return self;
}
