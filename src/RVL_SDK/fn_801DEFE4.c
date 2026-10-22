#pragma force_active on

typedef struct ShutdownNode {
    void* unk0;
    unsigned long priority;
    struct ShutdownNode* next;
    struct ShutdownNode* prev;
} ShutdownNode;

typedef struct ShutdownQueue {
    ShutdownNode* head;
    ShutdownNode* tail;
} ShutdownQueue;

extern ShutdownQueue ShutdownFunctionQueue_805A06E8;

void OSRegisterShutdownFunction(ShutdownNode* node) {
    ShutdownNode* cur = ShutdownFunctionQueue_805A06E8.head;
    ShutdownNode* prev;

    while (cur != 0 && cur->priority <= node->priority) {
        cur = cur->next;
    }

    if (cur == 0) {
        prev = ShutdownFunctionQueue_805A06E8.tail;
        if (prev == 0) {
            ShutdownFunctionQueue_805A06E8.head = node;
        } else {
            prev->next = node;
        }
        node->prev = prev;
        node->next = 0;
        ShutdownFunctionQueue_805A06E8.tail = node;
        return;
    }

    node->next = cur;
    prev = cur->prev;
    cur->prev = node;
    node->prev = prev;
    if (prev == 0) {
        ShutdownFunctionQueue_805A06E8.head = node;
        return;
    }
    prev->next = node;
}
