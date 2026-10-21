#pragma force_active on
class Obj {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void f9(int a);
    virtual void v10();
    virtual void v11();
    virtual void f12(int a, int b, int c);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual int f20(int a);
};

extern "C" void fn_122_EE8C(char* self) {
    Obj* a = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x58);
    a->f9(1);
    Obj* b = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x84);
    if (b->f20(9)) {
        b = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x84);
        b->f12(9, 1, 0);
    }
}
