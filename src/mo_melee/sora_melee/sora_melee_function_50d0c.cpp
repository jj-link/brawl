#include <types.h>
#pragma force_active on

class Node {
public:
    virtual void v0();
    virtual Node* v1();
    virtual void v2();
    virtual void v3();
    Node* m_ptr;
};

struct Outer {
    u32 m_pad[4];
    Node m_node;
};

extern "C" void* fn_27_50D0C(Outer* p) {
    return p->m_node.v1()->m_ptr;
}
