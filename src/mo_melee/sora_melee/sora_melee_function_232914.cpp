#include <ut/ut_list.h>
#pragma force_active on
struct Object_vptr_4_base { Object_vptr_4_base* next; };
class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual void slot0();
    virtual void slot1(int);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};
struct Node : utListNode {
    char pad[0x18];
    Object_vptr_4* a20;
    Object_vptr_4* a24;
    Object_vptr_4* a28;
    char pad2C;
    unsigned char f2D;
    unsigned char f2E;
};
struct Self {
    char pad[0x40];
    utList list;
    char pad2[0x14];
    unsigned char flag;
};
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_4BCF8[];
extern char __RTTI__10gfCallBack[];
void fn_27_233CFC(void*);
}
inline void destroy(Object_vptr_4* p) {
    if (p) p->slot1(1);
}
extern "C" void fn_27_232914(Self* self) {
    Node* current;
    Node* n = *(Node**)&self->list;
    if (self->flag) {
        while (n) {
            Object_vptr_4* o = n->a24;
            while (o) {
                o->slot4();
                o = (Object_vptr_4*)__dynamic_cast(o->next, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
            }
            o = n->a20;
            while (o) {
                o->slot4();
                o = (Object_vptr_4*)__dynamic_cast(o->next, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
            }
            o = n->a28;
            while (o) {
                o->slot4();
                o = (Object_vptr_4*)__dynamic_cast(o->next, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
            }
            n = (Node*)n->m_next;
        }
    }
    current = *(Node**)&self->list;
    if (self->flag) {
        while (current) {
            fn_27_233CFC(current);
            current = (Node*)current->m_next;
        }
    }
    current = *(Node**)&self->list;
    while (current) {
        Node* next = (Node*)current->m_next;
        if (current->f2D) self->list.remove(current);
        if (current->f2E) {
            current->f2E = 0;
            if (current->a20) destroy(current->a20);
            if (current->a24) destroy(current->a24);
            if (current->a28) destroy(current->a28);
            current->a20 = 0;
            current->a24 = 0;
            current->a28 = 0;
        }
        current = next;
    }
}