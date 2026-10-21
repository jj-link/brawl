#pragma force_active on
struct IfaceC {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v9(int a);
    virtual void v10();
    virtual void v11();
    virtual void v12(int a, int b, int c);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual int v20(int a);
};

extern "C" void fn_122_EDF4(char* self) {
    IfaceC* c = *(IfaceC**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x58);
    c->v9(0);
    IfaceC* d = *(IfaceC**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x84);
    if (d->v20(9) != 0) {
        d = *(IfaceC**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x84);
        d->v12(9, 0, 0);
    }
}
