#pragma force_active on

struct Fn113Obj {
    void* vtA;
    int unk04;
    void* vtB;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
};

extern "C" Fn113Obj* fn_113_9204(Fn113Obj* obj, int a, int b, int c, int d, int e, int f);

class B {
    int x;
    int y;
public:
    virtual ~B();
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
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
};

class MainObj {
public:
    int data[0x70];
    B sub;
};

extern "C" MainObj* fn_113_9704(MainObj* self) {
    fn_113_9204((Fn113Obj*)&self->sub, (int)self, 0x4d, (int)self + 0x134, 0x20, (int)self + 0x1b4, 3);
    self->sub.v24();
    return self;
}
