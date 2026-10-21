#include <types.h>
#pragma force_active on

struct Node {
    Node* next;
    char pad04[0x18];
    unsigned char flags;
    unsigned char id;
    char pad1E[0x26];

    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int test(void*);
};

struct Container {
    char pad00[0x18];
    Container* children[4];
    int count;
    Node* head;
};

extern "C" unsigned int fn_800131B4(Container*, void*);

extern "C" Node* fn_8001237C(void* self, Container* container,
                            unsigned int id, void* arg) {
    unsigned int index = fn_800131B4(container, arg);
    if (index != 0xFF && container->children[index] != 0) {
        Node* result = fn_8001237C(self, container->children[index], id, arg);
        if (result != 0) {
            return result;
        }
    }

    if (container->count != 0) {
        Node* node = container->head;
        Node* end = (Node*)&container->head;
        while (node != end) {
            if (((node->flags >> 7) & 1) &&
                id == node->id &&
                node->test(arg) != 0) {
                return node;
            }
            node = node->next;
        }
    }

    return 0;
}
