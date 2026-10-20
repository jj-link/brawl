#pragma force_active on
struct soB {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

extern "C" void fn_27_1510D8(char* self) {
    ((soB*)(self + 0x30))->v6();
}
