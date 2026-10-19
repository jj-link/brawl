#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Obj {
    char pad[0x4c];
    u8 type;
};

struct Node {
    int unk0;
    Node* next;
    Obj* obj;
};

struct Owner {
    char pad[0x40];
    Node* head;
    u32 pad2;
    Node* cur;
    u32 count;
};

extern "C" void fn_27_271F1C(void* obj, void* p4, u32 a, u32 b);

extern "C" void fn_27_271B14(Owner* self, void* p4, u32 a, u32 b, u32 c) {
    self->cur = self->head;
    u32 n = self->count;
    for (u32 i = 0; i < n; i++) {
        Node* node = self->cur;
        Obj* obj = node->obj;
        if (a == obj->type) {
            fn_27_271F1C(obj, p4, b, c);
            return;
        }
        self->cur = node->next;
    }
}
