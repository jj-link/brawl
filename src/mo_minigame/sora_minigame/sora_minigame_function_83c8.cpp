#include <stddef.h>
#pragma force_active on

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

class Node {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    u8 m_flag;
};

struct Container {
    u32 _pad0;
    u32 _pad4;
    s32 m_count;
};

struct Outer {
    u8 _pad[0x4C0];
    Container* m_container;
};

extern "C" {
    Node* fn_20_4A0(Container* self, s32* idx);

    void fn_20_83C8(Outer* self) {
        if (self->m_container) {
            s32 i = 0;
            while (i < self->m_container->m_count) {
                Node* n1 = fn_20_4A0(self->m_container, &i);
                if (n1) {
                    Node* n2 = fn_20_4A0(self->m_container, &i);
                    if (n2->m_flag) {
                        Node* n3 = fn_20_4A0(self->m_container, &i);
                        n3->f3();
                    }
                }
                i++;
            }
        }
    }
}
