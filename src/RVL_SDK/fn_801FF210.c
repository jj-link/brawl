#pragma force_active on
typedef struct RmNode {
    struct RmNode* prev;
    struct RmNode* pad;
    struct RmNode* next;
    unsigned int idx;
    void (*cb)(struct RmNode*);
} RmNode;

extern RmNode* lbl_805A0A28;
extern RmNode* lbl_804E4850[];
extern void fn_801FF448(RmNode* node);

void fn_801FF210(void) {
    RmNode* node = lbl_805A0A28;

    if (node != 0) {
        lbl_805A0A28 = node->next;
    }

    while (node != 0) {
        if (node->idx != 0) {
            if (node->cb != 0) {
                node->cb(node);
            }
            fn_801FF448(node);
            node->prev = lbl_804E4850[0];
            lbl_804E4850[0] = node;
            node->idx = 0;
        }
        node = lbl_805A0A28;
        if (node != 0) {
            lbl_805A0A28 = node->next;
        }
    }
}
