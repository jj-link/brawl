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
    virtual void f4();
    u8 m_flag;
};

struct Container {
    u32 _pad0;
    u32 _pad4;
    s32 m_count;
    u32 _pad0c;
    void* m_obj;
};

struct Outer {
    u8 _pad[0x4C0];
    Container* m_container;
};

extern "C" {
    extern float lbl_20_rodata_158;
    Node* fn_20_4A0(Container* self, s32* idx);
    void fn_8009A0FC(void* self, float f);

    void fn_20_82A8(Outer* self) {
        if (self->m_container != NULL) {
            s32 i = 0;
            while (i < self->m_container->m_count) {
                if (fn_20_4A0(self->m_container, &i) != NULL) {
                    if (fn_20_4A0(self->m_container, &i)->m_flag != 0) {
                        fn_20_4A0(self->m_container, &i)->f1();
                    }
                }
                i++;
            }
            fn_8009A0FC((char*)self->m_container->m_obj + 8, lbl_20_rodata_158);
            s32 j = 0;
            while (j < self->m_container->m_count) {
                if (fn_20_4A0(self->m_container, &j) != NULL) {
                    if (fn_20_4A0(self->m_container, &j)->m_flag != 0) {
                        fn_20_4A0(self->m_container, &j)->f2();
                    }
                }
                j++;
            }
        }
    }
}
