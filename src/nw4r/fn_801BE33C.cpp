#pragma force_active on

typedef unsigned char u8;

struct Node {
    Node* prev;
    Node* next;
};

struct Manager {
    int field0;
    int size;
    Node head;
    u8 field10;
    int field14;
};

struct Object {
    u8 pad0[0x31];
    u8 field31;
    u8 field32;
    u8 field33;
    u8 pad34[0xA0];
    void (*callback)(Object*, int, int);
    int arg;
    void* handle;
    int fielde0;
    Node node;
};

extern Manager lbl_804C1CC8;
extern u8 lbl_805A0580;
extern u8 lbl_804C1CB8[0x10];

extern "C" {
void fn_801D1140(void*);
void fn_801D0DA4(void*);
void fn_801BD71C(void*);
void __register_global_object(void*, void (*)(void*), void*);
void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void*, Node*);
void fn_801C0A68(Manager*, Object*);
}

extern "C" void fn_801BE33C(Object* self) {
    if (self->handle) {
        fn_801D1140(self->handle);
        fn_801D0DA4(self->handle);
        self->handle = 0;
        self->field31 = 0;
        self->field32 = 0;

        if (self->field33) {
            self->field33 = 0;

            if ((signed char)lbl_805A0580 == 0) {
                lbl_804C1CC8.head.prev = 0;
                lbl_804C1CC8.head.next = 0;
                lbl_804C1CC8.field0 = 0;
                lbl_804C1CC8.size = 0;

                Node* head = &lbl_804C1CC8.head;
                head->prev = head;
                head->next = head;

                lbl_804C1CC8.field10 = 0;
                lbl_804C1CC8.field14 = 0;
                __register_global_object(
                    &lbl_804C1CC8, fn_801BD71C, lbl_804C1CB8);
                lbl_805A0580 = 1;
            }

            Manager* manager = &lbl_804C1CC8;
            Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(
                &manager->size, &self->node);

            if (self) {
                fn_801C0A68(manager, self);
            }
        }

        if (self->callback) {
            self->callback(self, 0, self->arg);
        }
    }
}
