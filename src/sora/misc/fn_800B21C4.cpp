#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_801AB038(void*, int);
extern "C" void fn_801AB0B8(void*, int);
extern "C" void fn_801AB0CC(void*, int);

extern int lbl_80455D18[8];

struct Owner;

struct Node {
    virtual ~Node();
    Node* next;
    Owner* owner;
};

struct Model {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void set(int, int);

    char pad[0xD0];
    Node* head;
};

struct Owner {
    char pad[0x10];
    Model* model;
    char pad2[0x40];
    int heap;
    Node* node;
};

extern "C" void fn_800B21C4(Owner* self, int enabled) {
    Model* model = self->model;
    if (enabled != 0) {
        if (self->node == 0) {
            Node* node = (Node*)__nw__FUlQ25Heaps8HeapType(12, self->heap);
            if (node != 0) {
                Node* next = model->head;
                *(void**)node = lbl_80455D18;
                node->next = next;
                node->owner = self;
            }
            model->head = node;
            fn_801AB038(model, 4);
            if (self->node != node) {
                delete self->node;
                self->node = node;
            }
        }
        fn_801AB0B8(model, 2);
    } else {
        fn_801AB0CC(model, 2);
        Model* current = self->model;
        current->set(3, 0);
    }
}
