#pragma force_active on
class Obj {
public:
    virtual void v0(unsigned int);
    virtual void v1(unsigned int);
    virtual void v2(unsigned int);
    virtual void v3(unsigned int);
    virtual void v4(unsigned int);
    virtual void v5(unsigned int);
    virtual Obj* v6(unsigned int);
    virtual void v7(unsigned int);
    virtual void v8(unsigned int);
    virtual void v9(unsigned int);
    virtual void v10(unsigned int);
    virtual void v11(unsigned int);
    virtual void v12(unsigned int);
    virtual void v13(unsigned int);
    virtual void v14(unsigned int);
    virtual void v15(unsigned int);
    virtual void v16(unsigned int);
    virtual void v17(unsigned int);
    virtual void v18(unsigned int);
    virtual void v19(unsigned int);
    virtual void v20(unsigned int);
    unsigned char x4;
    signed char f5;
};

extern "C" void fn_27_164180(int a, int b, int c, char* p) {
    Obj* t = *(Obj**)(*(char**)(p + 0xd8) + 0x7c);
    t = t->v6(4);
    t->f5 &= ~0x80;
    Obj* u = *(Obj**)(*(char**)(p + 0xd8) + 0x64);
    u->v18(0x2200000d);
}
