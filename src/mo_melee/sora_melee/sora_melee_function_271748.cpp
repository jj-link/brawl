#include <gf/gf_task.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0(int);
};
struct Node {
    Node* prev;
    Node* next;
    Object_vptr_0* value;
};
struct Object {
    char pad[0x3c];
    char* vtable;
    Node* head;
    Node* tail;
    Node* current;
    unsigned int count;
};
extern "C" {
extern char lbl_27_data_57F70[];
void __dl__FPv(void*);
void __dt__6gfTaskFv(void*, int);
void* fn_27_271748(Object* self, int flag) {
    if (self) {
        unsigned int i;
        unsigned int n = self->count;
        self->vtable = lbl_27_data_57F70;
        self->current = self->head;
        for (i = 0; i < n; i++) {
            if (self->current->value)
                self->current->value->slot0(1);
            self->current->value = 0;
            self->current = self->current->next;
        }
        n = self->count;
        self->current = self->head;
        for (i = 0; i < n; i++) {
            Node* p = self->current;
            self->current = p->next;
            if (p)
                __dl__FPv(p);
        }
        self->head = 0;
        self->tail = 0;
        self->current = 0;
        self->count = 0;
        __dt__6gfTaskFv(self, 0);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
}