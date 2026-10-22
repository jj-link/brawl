#pragma force_active on
typedef unsigned int u32;

typedef struct Node {
    struct Node* next;
    struct Node* prev;
    u32 pad8;
    u32 idx;
} Node;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern void fn_801FF448(Node* node);
extern Node* lbl_804E4850[];
extern Node* lbl_804E48D0[];

void fn_801FF6C8(Node* node, u32 idx) {
    u32 level;
    Node* head;
    Node** slot;

    level = OSDisableInterrupts();
    fn_801FF448(node);
    slot = &lbl_804E4850[idx];
    head = *slot;
    node->next = head;
    node->prev = 0;
    if (head != 0) {
        (*slot)->prev = node;
        *slot = node;
    } else {
        *slot = node;
        lbl_804E48D0[idx] = node;
    }
    node->idx = idx;
    OSRestoreInterrupts(level);
}
