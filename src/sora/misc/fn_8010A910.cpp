#pragma force_active on
struct Node {
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
    virtual void setCount(int);

    char padding[0xE0];
    int count;
};

struct Obj {
    char padding[0x110];
    Node* node;
};

extern "C" void fn_8010A910(Obj* obj) {
    Node* node = obj->node;
    while (node->count != 0) {
        if (node->count != 0) {
            node->setCount(node->count - 1);
        }
    }
}
