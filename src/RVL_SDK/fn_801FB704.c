#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct Node {
    struct Node *next;
    struct Node *prev;
} Node;
extern Node lbl_804E43F0[];

int fn_801FB704(int index, Node *node) {
    BOOL level = OSDisableInterrupts();
    Node *head = &lbl_804E43F0[index];
    head->prev->next = node;
    node->prev = head->prev;
    node->next = head;
    head->prev = node;
    OSRestoreInterrupts(level);
    return 1;
}
