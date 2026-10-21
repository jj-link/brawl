#pragma force_active on
class Node {
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
};

class Owner {
public:
    int pad[4];
    Node* m_node;
};

extern "C" void fn_802A23CC(Owner* self) {
    Node* node = self->m_node;
    if (node) {
        node->v12();
    }
}
