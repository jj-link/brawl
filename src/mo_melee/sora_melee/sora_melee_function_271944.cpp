#include <types.h>
#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_27_data_58000[];
extern "C" char lbl_27_data_58030[];
struct Obj {
    void* v0; void* v1;
    int a,b,c,d,e;
    unsigned char f; char pad1[3];
    void* v2; int g,h,i,j,k;
    unsigned char l; char pad2[3];
    int m,n,o,p;
    unsigned char id, q;
};
struct Node { Node* prev; Node* next; Obj* value; };
struct Self { char pad[0x40]; Node* head; Node* tail; Node* cur; unsigned int count; int serial; };
struct Input { char pad[0x10]; int serial; unsigned char id; };
extern "C" void fn_27_271EBC(Obj*, Input*);
inline Obj* findObj(Self* self, unsigned char id) {
    self->cur = self->head;
    unsigned int count = self->count;
    for (unsigned int i = 0; i < count; i++) {
        Obj* obj = self->cur->value;
        if (id == obj->id) return obj;
        self->cur = self->cur->next;
    }
    return 0;
}
extern "C" int fn_27_271944(Self* self, Input* input) {
    Obj* obj = findObj(self, input->id);
    if (obj == 0) {
        obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x50, 0xf);
        if (obj) {
            obj->v0 = lbl_27_data_58000;
            obj->v1 = lbl_27_data_58030;
            obj->a = 0; obj->b = 0; obj->c = 0; obj->d = 0; obj->e = 0;
            obj->f = 1;
            obj->v2 = lbl_27_data_58030;
            obj->g = 0; obj->h = 0; obj->i = 0; obj->j = 0; obj->k = 1;
            obj->l = 1;
            obj->m = 0; obj->n = 0; obj->o = 0; obj->p = 0;
            obj->id = 0; obj->q = 0;
        }
        obj->id = input->id;
        Node* n;
        if (self->head == 0) {
            n = (Node*)__nw__FUlQ25Heaps8HeapType(0xc, 0xf);
            if (n) { n->prev = 0; n->next = 0; }
            self->cur = n; self->tail = n; self->head = n;
            n->value = obj;
        } else {
            n = (Node*)__nw__FUlQ25Heaps8HeapType(0xc, 0xf);
            if (n) { n->prev = 0; n->next = 0; }
            self->tail->next = n;
            self->tail->next->value = obj;
            n = self->tail;
            n->next->prev = n;
            self->tail = self->tail->next;
        }
        self->count++;
    }
    input->serial = self->serial;
    fn_27_271EBC(obj, input);
    self->serial++;
    return input->serial;
}