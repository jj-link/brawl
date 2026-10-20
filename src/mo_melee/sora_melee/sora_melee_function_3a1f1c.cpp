#pragma force_active on

struct First {
    virtual ~First();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3(int);
};

struct Second {
    virtual ~Second();
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
    virtual void f19(int, int);
};

struct Node {
    char pad[0x50];
    Second* second;
    char pad2[0x10];
    First* first;
};

struct Self {
    char pad[0xD8];
    Node* node;
};

extern "C" void fn_27_3A1F1C(int arg, Self* self) {
    int result = self->node->first->f3(0x20000004);
    if (result >= 0) {
        self->node->second->f19(result, 0);
    }
}
