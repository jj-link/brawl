#pragma force_active on
struct Item {
    unsigned char pad[0x4C];
    unsigned char id;
};

struct Node {
    Node* prev;
    Node* next;
    Item* item;
};

struct List {
    unsigned char pad[0x40];
    Node* head;
    Node* tail;
    Node* current;
    unsigned int count;
};

extern "C" void fn_27_271F94(void* self, void* arg);

extern "C" void fn_27_271B60(List* self, void* arg, unsigned int id) {
    self->current = self->head;
    unsigned int count = self->count;
    for (unsigned int i = 0; i < count; ++i) {
        Node* node = self->current;
        Item* item = node->item;
        if (id == item->id) {
            fn_27_271F94(item, arg);
            return;
        }
        self->current = node->next;
    }
}
