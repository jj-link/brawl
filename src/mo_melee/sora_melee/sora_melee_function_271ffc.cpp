#pragma force_active on
struct Node {
    Node* prev;
    Node* next;
    void* value;
};
struct Object {
    void* vtable;
    Node* head;
    Node* tail;
    Node* current;
    unsigned int count;
};
extern "C" {
extern char lbl_27_data_58030[];
void __dl__FPv(void*);
void* fn_27_271FFC(Object* self, int flag) {
    if (self) {
        unsigned int i;
        unsigned int n = self->count;
        self->vtable = lbl_27_data_58030;
        self->current = self->head;
        for (i = 0; i < n; i++) {
            __dl__FPv(self->current->value);
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
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
}