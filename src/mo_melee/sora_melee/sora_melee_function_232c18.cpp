#include <types.h>
#pragma force_active on

struct Node;

struct NodeData {
    Node* next;
    char pad[0x2C];
};

struct Node : NodeData {
    virtual ~Node();
};

struct Manager {
    char pad[0x40];
    Node* head;
    int unk44;
    int unk48;
    void* buffer4c;
    void* buffer50;
    void* buffer54;
    void* buffer58;
    int unk5c;
    unsigned char flag60;
};

extern "C" void* memset(void*, int, unsigned int);

extern "C" void fn_27_232C18(Manager* self) {
    Node* node = self->head;
    while (node != 0) {
        Node* next = node->next;
        delete node;
        node = next;
    }

    void* buffer200 = self->buffer4c;
    self->unk44 = 0;
    self->head = 0;
    self->unk48 = 0;
    self->flag60 = 1;
    self->buffer50 = 0;
    self->buffer58 = 0;

    if (buffer200 != 0) {
        memset(buffer200, 0, 0x200);
    }
    if (self->buffer54 != 0) {
        memset(self->buffer54, 0, 0x100);
    }
}
