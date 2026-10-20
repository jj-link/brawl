#pragma force_active on
class ExecObj {
public:
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
    virtual void callB(int a);
    virtual void callA(int a);
};

struct NodeB {
    unsigned char pad64[0x64];
    ExecObj* obj;
};

struct NodeA {
    unsigned char padD8[0xD8];
    NodeB* next;
};

struct Subject {
    unsigned char pad60[0x60];
    NodeA* f60;
    unsigned char pad50[0x4C];
    unsigned int fB0;
};

extern "C" {
void* getInstance__9emManagerFv();
int fn_41_6DDC(int, int);
void fn_41_CC44(int* obj, unsigned int p2, int (*p3)(int, int));

void fn_41_6EB4(Subject* p) {
    p->f60->next->obj->callA(0x12000011);
    fn_41_CC44((int*)getInstance__9emManagerFv(), p->fB0, &fn_41_6DDC);
    p->f60->next->obj->callB(0x12000011);
}
}
