#include <types.h>
#pragma force_active on

struct fnRes {
    void* m_unused;
    void* m_ptr;
};

class fnSub {
public:
    virtual void f0();
    virtual fnRes* f1();
    virtual void f2();
    virtual void f3();
};

struct fnOuter {
    u8 m_pad[0x10];
    fnSub m_sub;
};

extern "C" {
    void* fn_27_1BBF24(fnOuter* p) {
        return p->m_sub.f1()->m_ptr;
    }
}
