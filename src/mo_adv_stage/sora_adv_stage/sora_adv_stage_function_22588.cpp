#pragma force_active on
struct Entry {
    char pad[0x154];
    void* key;
};

struct Node {
    Node* prev;
    Node* next;
    Entry* data;
};

struct Object {
    char pad[0x154];
    Node* head;
    unsigned int unknown;
    Node* current;
    unsigned int count;
};

extern "C" void fn_40_23CBC(void*);
extern "C" void fn_27_27255C(void*, int, int, void*);

extern "C" void fn_40_22588(Object* self, void* key)
{
    self->current = self->head;
    unsigned int count = self->count;
    for (unsigned int i = 0; i < count; ++i) {
        Node* node = self->current;
        Entry* entry = node->data;
        if (key == entry->key) {
            fn_40_23CBC(entry);
            fn_27_27255C((char*)self + 0x14C, 0, 1, key);
            break;
        }
        self->current = node->next;
    }
}
