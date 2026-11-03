#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

struct Node {
    int field0;
    unsigned int key;
    int field8;
};

extern struct Node *lbl_805A0B90;
extern void fn_8020A24C(struct Node *);
extern void fn_8020A0C0(struct Node *);

struct Node *fn_8020992C(struct Node *node) {
    BOOL enabled = OSDisableInterrupts();
    fn_8020A24C(node);
    node->field0 = 0;
    node->field8 = 1;
    OSRestoreInterrupts(enabled);
    if (node == lbl_805A0B90) {
        fn_8020A0C0(node);
    }
    return node;
}
