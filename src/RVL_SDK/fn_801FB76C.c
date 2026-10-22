#pragma force_active on
typedef struct Node {
    struct Node *next;
    struct Node *prev;
} Node;

extern Node lbl_804E43F0[];
int OSDisableInterrupts(void);
void OSRestoreInterrupts(int level);

void *fn_801FB76C(void) {
    Node *node;
    Node *head;
    int i;
    int level;

    level = OSDisableInterrupts();
    head = lbl_804E43F0;
    for (i = 0; i < 4; head++, i++) {
        if (head->next != head) {
            OSRestoreInterrupts(level);
            level = OSDisableInterrupts();
            node = lbl_804E43F0[i].next;
            lbl_804E43F0[i].next = node->next;
            node->next->prev = &lbl_804E43F0[i];
            OSRestoreInterrupts(level);
            node->next = 0;
            node->prev = 0;
            return node;
        }
    }
    OSRestoreInterrupts(level);
    return 0;
}
