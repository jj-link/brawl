#pragma force_active on
struct Node {
    Node* next;
    unsigned char pad4[4];
    unsigned char state;
    unsigned char pad9[0x13];
    unsigned int value;
    unsigned int id;
};

struct Object {
    unsigned char pad[0x1094];
    Node* head;
};

extern "C" void* fn_27_70050(void*);

static inline Node* findNode(Node* node, unsigned int id) {
    while (node) {
        if (id == node->id)
            return node;
        node = node->next;
    }
    return 0;
}

extern "C" void* fn_27_144FC4(Object* object, unsigned int id, unsigned int mode) {
    if (id != 0xffff) {
        Node* node = findNode(object->head, id);
        if (node) {
            if (mode == 1 && node->state > 1)
                return 0;
            return fn_27_70050(&node->value);
        }
    }
    return 0;
}
