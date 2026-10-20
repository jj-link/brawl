#pragma force_active on
struct fnSubObj {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
};

extern "C" {
int fn_27_F4DA8(char* self) {
    return ((fnSubObj*)(self + 0x10))->v8();
}
}
