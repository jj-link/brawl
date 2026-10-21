#pragma force_active on
struct Flags {
    unsigned char pad[5];
    unsigned char f0 : 1;
    unsigned char f1 : 1;
    unsigned char f2 : 1;
    unsigned char f3 : 1;
    unsigned char f4 : 1;
    unsigned char f5 : 1;
    unsigned char f6 : 1;
    unsigned char f7 : 1;
};

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Flags* v6(int a);
};

extern "C" void fn_102_169B4(char* self) {
    Obj* a = *(Obj**)(*(char**)(self + 0xd8) + 0x7c);
    Flags* p = a->v6(0);
    p->f0 = 0;
    a = *(Obj**)(*(char**)(self + 0xd8) + 0x7c);
    p = a->v6(1);
    p->f0 = 0;
    a = *(Obj**)(*(char**)(self + 0xd8) + 0x7c);
    p = a->v6(2);
    p->f0 = 0;
    a = *(Obj**)(*(char**)(self + 0xd8) + 0x7c);
    p = a->v6(3);
    p->f0 = 0;
}
