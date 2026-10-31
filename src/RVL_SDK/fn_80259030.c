#include <string.h>
#pragma force_active on

struct Node {
    int field0;
    void* next;
    char pad8[4];
    char data[6];
    char pad12[2];
};

struct Pool {
    int field0;
    unsigned int field4;
    void* head;
    char pad[0x5C];
    void* pool;
};

void* fn_80259030(struct Pool* arg0, unsigned int unused) {
    unsigned int size;
    struct Node* node;
    struct Node* cur;
    char* next;

    size = arg0->field4;
    if (size < 0x14) {
        return 0;
    }
    node = (struct Node*)arg0->pool;
    arg0->field4 = size - 0x14;
    next = (char*)node + 0x14;
    arg0->pool = next;
    node->field0 = 0;
    node->next = 0;
    ((void* (*)(void*, void*, unsigned int, void*))memcpy)(node->data, (void*)unused, 6, next);
    if (arg0->head == 0) {
        arg0->head = node;
    } else {
        cur = (struct Node*)arg0->head;
        while (cur->next) {
            cur = (struct Node*)cur->next;
        }
        cur->next = node;
    }
    return node;
}
