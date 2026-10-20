#pragma force_active on
class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v7(int a, int b, int c, int d);
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
    virtual int v23();
};

extern "C" void fn_27_29D4C4(void* unused, char* self) {
    Obj* c = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x8);
    if (c->v23() == 10) {
        Obj* d = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x50);
        d->v7(0x1f52, 0, 0, 0);
    }
}
